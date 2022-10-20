#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
// const long long MOD=998244353;
#define LOCAL
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(),(x).end()
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U,typename V>
ostream&operator<<(ostream &os,const tuple<T,U,V> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template<typename T,typename U,typename V,typename W>
ostream&operator<<(ostream &os,const tuple<T,U,V,W> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const unordered_map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const unordered_set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const deque<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<typename T,typename E>
struct PrimalDual{
    const E inf=numeric_limits<E>::max();
    struct edge{
        int to,rev; T cap; E cost;
        edge(int to,T cap,E cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<pair<int,int>> pos;
    vector<E> h,dist;
    vector<int> prevv,preve;
    PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}
    int add_edge(int from,int to,T cap,E cost){
        pos.emplace_back(from,G[from].size());
        G[from].emplace_back(to,cap,cost,G[to].size());
        G[to].emplace_back(from,0,-cost,G[from].size()-1);
        return pos.size()-1;
    }
    tuple<int,int,int,int,int> get_edge(int i){
        auto e=G[pos[i].first][pos[i].second];
        auto re=G[e.to][e.rev];
        return {pos[i].first,e.to,e.cap+re.cap,re.cap,e.cost};
    }
    vector<tuple<int,int,int,int,int>> edges(){
        vector<tuple<int,int,int,int,int>> res;
        for (int i=0;i<pos.size();++i){
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    void dijkstra(int s){
        struct P{
            E c; int v;
            P(E c,int v):c(c),v(v){}
            bool operator<(const P &rhs) const {return c>rhs.c;}
        };
        priority_queue<P> pq;
        fill(dist.begin(),dist.end(),inf);
        dist[s]=0; pq.emplace(dist[s],s);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.v;
            if (dist[v]<p.c) continue;
            for (int i=0;i<G[v].size();++i){
                auto &e=G[v][i];
                if (e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v; preve[e.to]=i;
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
    }
    vector<pair<T,E>> slope(int s,int t,T lim){
        T f=0; E c=0,pre=-1;
        vector<pair<T,E>> res;
        res.emplace_back(f,c);
        while(f<lim){
            dijkstra(s);
            if (dist[t]==inf) break;
            for (int v=0;v<G.size();++v) h[v]+=dist[v];
            T d=lim-f;
            for (int v=t;v!=s;v=prevv[v]){
                d=min(d,G[prevv[v]][preve[v]].cap);
            }
            for (int v=t;v!=s;v=prevv[v]){
                auto &e=G[prevv[v]][preve[v]];
                e.cap-=d; G[v][e.rev].cap+=d;
            }
            f+=d; c+=h[t]*d;
            if (pre==h[t]) res.pop_back();
            res.emplace_back(f,c);
            pre=c;
        }
        return res;
    }
    E min_cost_flow(int s,int t,T f){
        auto res=slope(s,t,f).back();
        return res.first==f?res.second:-1;
    }
    pair<T,E> min_cost_max_flow(int s,int t){
        return slope(s,t,numeric_limits<T>::max()).back();
    }
    vector<pair<T,E>> min_cost_slope(int s,int t){
        return slope(s,t,numeric_limits<T>::max());
    }
};

void solve(){
    vector<int> x(4),y(4);
    for (int i=0;i<4;++i) cin >> x[i] >> y[i];

    vector<int> perm(4);
    iota(perm.begin(),perm.end(),0);
    ll ans=IINF;

    do {
        PrimalDual<ll,ll> PD(8);
        int s=6,t=7;
        for (int i=0;i<4;++i){
            for (int j=4;j<6;++j){
                PD.add_edge(i,j,IINF,1);
                PD.add_edge(j,i,IINF,1);
            }
        }
        vector<int> w(6);
        w[0]=x[perm[2]]-x[perm[0]];
        w[1]=x[perm[1]]-x[perm[3]];
        w[2]=y[perm[0]]-y[perm[1]];
        w[3]=y[perm[3]]-y[perm[2]];
        w[4]=x[perm[0]]+y[perm[2]]-x[perm[1]]-y[perm[0]];
        w[5]=x[perm[3]]+y[perm[1]]-x[perm[2]]-y[perm[3]];
        for (int i=0;i<6;++i){
            if (w[i]>0) PD.add_edge(s,i,w[i],0);
            else PD.add_edge(i,t,-w[i],0);
        }
        ans=min(ans,PD.min_cost_max_flow(s,t).second);
    } while (next_permutation(perm.begin(),perm.end()));

    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}
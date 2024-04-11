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

template<typename T,bool directed>
struct Dinic{
    struct edge{
        int to,rev; T cap;
        edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<pair<int,int>> pos;
    vector<int> level,iter;
    Dinic(int n):G(n),level(n),iter(n){}
    int add_edge(int from,int to,T cap){
        pos.emplace_back(from,G[from].size());
        G[from].emplace_back(to,cap,G[to].size());
        G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
        return pos.size()-1;
    }
    int add_vertex(){
        G.emplace_back();
        level.emplace_back();
        iter.emplace_back();
        return G.size()-1;
    }
    tuple<int,int,int,int> get_edge(int i){
        auto e=G[pos[i].first][pos[i].second];
        auto re=G[e.to][e.rev];
        return {pos[i].first,e.to,e.cap+re.cap,re.cap};
    }
    vector<tuple<int,int,int,int>> edges(){
        vector<tuple<int,int,int,int>> res;
        for (int i=0;i<pos.size();++i){
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    void change_edge(int i,T new_cap,T new_flow){
        auto &e=G[pos[i].first][pos[i].second];
        auto &re=G[e.to][e.rev];
        e.cap=new_cap-new_flow;
        re.cap=(directed?new_flow:new_cap+new_flow);
    }
    void bfs(int s){
        fill(level.begin(),level.end(),-1);
        queue<int> que;
        level[s]=0; que.emplace(s);
        while(!que.empty()){
            int v=que.front(); que.pop();
            for (auto &e:G[v]){
                if (e.cap>0&&level[e.to]<0){
                    level[e.to]=level[v]+1;
                    que.emplace(e.to);
                }
            }
        }
    }
    T dfs(int v,int t,T f){
        if (v==t) return f;
        for (int &i=iter[v];i<G[v].size();++i){
            auto &e=G[v][i];
            if (e.cap>0&&level[v]<level[e.to]){
                T d=dfs(e.to,t,min(f,e.cap));
                if (d<=0) continue;
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s,int t,T lim){
        T flow=0;
        while(lim>0){
            bfs(s);
            if (level[t]<0) break;
            fill(iter.begin(),iter.end(),0);
            while(lim>0){
                T f=dfs(s,t,lim);
                if (f==0) break;
                flow+=f; lim-=f;
            }
        }
        return flow;
    }
    T max_flow(int s,int t){
        return max_flow(s,t,numeric_limits<T>::max());
    }
    vector<bool> min_cut(int s){
        vector<bool> res(G.size());
        queue<int> que;
        res[s]=true; que.emplace(s);
        while(!que.empty()){
            int v=que.front(); que.pop();
            for (auto e:G[v]){
                if (e.cap>0&&!res[e.to]){
                    res[e.to]=true;
                    que.emplace(e.to);
                }
            }
        }
        return res;
    }
};

vector<int> prime_factor_table(int n){
    vector<int> res(n+1,0);
    for (int i=2;i<=n;++i) if (!res[i]){
        for (int j=i;j<=n;j+=i){
            if (!res[j]) res[j]=i;
        }
    }
    return res;
}

const int MAX_A=20010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v=prime_factor_table(MAX_A);
    vector<bool> prime(MAX_A,false);
    for (int i=0;i<MAX_A;++i){
        if (v[i]==i){
            prime[i]=true;
        }
    }
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    Dinic<int,true> D(n+2);
    int s=n,t=s+1;
    for (int i=0;i<n;++i){
        if (a[i]&1){
            D.add_edge(s,i,2);
            for (int j=0;j<n;++j){
                if (prime[a[i]+a[j]]){
                    D.add_edge(i,j,1);
                }
            }
        }
        else D.add_edge(i,t,2);
    }

    int f=D.max_flow(s,t);
    if (f!=n){
        cout << "Impossible" << '\n';
        return 0;
    }
    vector<tuple<int,int,int,int>> es=D.edges();
    vector<vector<int>> G(n);
    for (auto e:es){
        if (get<2>(e)!=get<3>(e)) continue;
        int u=get<0>(e),v=get<1>(e);
        if (u==s||v==t) continue;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> seen(n,false);
    auto dfs=[&](auto self,int v,int p)->void{
        if (p<0) ans.emplace_back();
        ans.back().emplace_back(v+1);
        seen[v]=true;
        for (int u:G[v]){
            if (seen[u]) continue;
            self(self,u,v);
        }
    };

    for (int i=0;i<n;++i){
        if (seen[i]) continue;
        dfs(dfs,i,-1);
    }
    cout << ans.size() << '\n';
    for (int i=0;i<ans.size();++i){
        cout << ans[i].size() << ' ';
        cout << ans[i] << '\n';
    }
}
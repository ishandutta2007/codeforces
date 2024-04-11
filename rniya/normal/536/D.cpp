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

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    template<typename C>
    int find_subtree(int k,const C &check,Monoid &M,bool type){
        while(k<n){
            Monoid nxt=type?f(dat[k<<1|type],M):f(M,dat[k<<1|type]);
            if (check(nxt)) k=k<<1|type;
            else M=nxt,k=k<<1|(type^1);
        }
        return k-n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template<typename C>
    int find_first(int a,const C &check){
        Monoid L=id;
        if (a<=0){
            if (check(f(L,dat[1]))) return find_subtree(1,check,L,false);
            return -1;
        }
        int b=n;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1){
                Monoid nxt=f(L,dat[l]);
                if (check(nxt)) return find_subtree(l,check,L,false);
                L=nxt; ++l;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template<typename C>
    int find_last(int b,const C &check){
        Monoid R=id;
        if (b>=n){
            if (check(f(dat[1],R))) return find_subtree(1,check,R,true);
            return -1;
        }
        int a=n;
        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){
            if (r&1){
                Monoid nxt=f(dat[--r],R);
                if (check(nxt)) return find_subtree(r,check,R,true);
                R=nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i){return dat[i+n];}
};

const int MAX_N=2010;
ll dp[MAX_N][MAX_N][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    int s,t; cin >> s >> t; --s,--t;
    vector<int> p(n);
    for (int i=0;i<n;++i) cin >> p[i];
    vector<vector<pair<int,int>>> G(n);
    for (int i=0;i<m;++i){
        int v,u,w; cin >> v >> u >> w; --v,--u;
        G[v].emplace_back(u,w);
        G[u].emplace_back(v,w);
    }

    auto dijkstra=[&](int source)->vector<int>{
        priority_queue<pair<ll,int>> pq;
        vector<ll> calc(n,IINF);
        calc[source]=0; pq.emplace(-calc[source],source);

        while (!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.second;
            if (calc[v]<-p.first) continue;
            for (auto e:G[v]){
                int u=e.first;
                if (calc[v]+e.second<calc[u]){
                    calc[u]=calc[v]+e.second;
                    pq.emplace(-calc[u],u);
                }
            }
        }

        vector<ll> comp(calc);
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());

        vector<int> res(n);
        for (int i=0;i<n;++i) res[i]=lower_bound(comp.begin(),comp.end(),calc[i])-comp.begin()+1;
        return res;
    };

    vector<vector<int>> d(2);
    d[0]=dijkstra(s); d[1]=dijkstra(t);

    vector<vector<ll>> get(n+2,vector<ll>(n+2,0));
    vector<vector<int>> cnt(n+2,vector<int>(n+2,0));
    for (int i=0;i<n;++i){
        get[d[0][i]+1][d[1][i]+1]+=p[i];
        ++cnt[d[0][i]+1][d[1][i]+1];
    }
    for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j){
            get[i+1][j+1]+=get[i+1][j]+get[i][j+1]-get[i][j];
            cnt[i+1][j+1]+=cnt[i+1][j]+cnt[i][j+1]-cnt[i][j];
        }
    }
    auto sum=[&](int lx,int rx,int ly,int ry){
        return get[rx][ry]-get[lx][ry]-get[rx][ly]+get[lx][ly];
    };
    auto rec_cnt=[&](int lx,int rx,int ly,int ry){
        return cnt[rx][ry]-cnt[lx][ry]-cnt[rx][ly]+cnt[lx][ly];
    };

    vector<SegmentTree<ll>> seg_x(n+1,SegmentTree<ll>(n+1,[](ll a,ll b){return max(a,b);},-IINF));
    vector<SegmentTree<ll>> seg_y(n+1,SegmentTree<ll>(n+1,[](ll a,ll b){return min(a,b);},IINF));

    for (int i=n;i>=0;--i){
        for (int j=n;j>=0;--j){
            for (int k=0;k<2;++k){
                ll rec=sum(i+1,n+1,j+1,n+1);
                if (!k){
                    if (!rec_cnt(i+1,n+1,j+1,n+1)) dp[i][j][k]=0;
                    else {
                        int lb=i,ub=n+1;
                        while (ub-lb>1){
                            int mid=(ub+lb)>>1;
                            (rec_cnt(mid+1,n+1,j+1,n+1)==rec_cnt(i+1,n+1,j+1,n+1)?lb:ub)=mid;
                        }
                        dp[i][j][k]=seg_x[j].query(ub,n+1)+rec;
                    }
                    seg_y[i].update(j,dp[i][j][k]+rec);
                } else {
                    if (!rec_cnt(i+1,n+1,j+1,n+1)) dp[i][j][k]=0;
                    else {
                        int lb=j,ub=n+1;
                        while (ub-lb>1){
                            int mid=(ub+lb)>>1;
                            (rec_cnt(i+1,n+1,mid+1,n+1)==rec_cnt(i+1,n+1,j+1,n+1)?lb:ub)=mid;
                        }
                        dp[i][j][k]=seg_y[i].query(ub,n+1)-rec;
                    }
                    seg_x[j].update(i,dp[i][j][k]-rec);
                }
            }
        }
    }

    ll score=dp[0][0][0];
    cout << (score>0?"Break a heart":(score<0?"Cry":"Flowers")) << '\n';
}
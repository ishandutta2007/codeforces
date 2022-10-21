#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
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
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> G(n);
    vector<tuple<int,int,int>> es;
    for (int i=0;i<n-1;++i){
        int u,v,val; cin >> u >> v >> val;
        es.emplace_back(--u,--v,val);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for (int i=0;i<n;++i){
        if (G[i].size()==2){
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    auto dfs=[&](auto self,int v,int p)->int{
        if (G[v].size()==1) return v;
        for (int u:G[v]){
            if (u==p) continue;
            return self(self,u,v);
        }
    };

    vector<vector<int>> ans(n,vector<int>(n,0));
    for (int i=0;i<n-1;++i){
        int u=get<0>(es[i]),v=get<1>(es[i]),val=get<2>(es[i]);
        int a=-1,b=-1,c=-1,d=-1;
        if (G[u].size()==1) a=b=u;
        else {
            for (int w:G[u]){
                if (w==v) continue;
                int nxt=dfs(dfs,w,u);
                (~a?b:a)=nxt;
            }
        }
        if (G[v].size()==1) c=d=v;
        else {
            for (int w:G[v]){
                if (w==u) continue;
                int nxt=dfs(dfs,w,v);
                (~c?d:c)=nxt;
            }
        }
        auto add=[&](int p,int q,int x){
            ans[p][q]+=x;
            ans[q][p]+=x;
        };
        debug(val,a,b,c,d);
        add(a,c,val/2); add(b,d,val/2);
        add(a,b,-val/2); add(c,d,-val/2);
    }

    vector<tuple<int,int,int>> res;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (ans[i][j]!=0){
                res.emplace_back(i+1,j+1,ans[i][j]);
            }
        }
    }

    cout << res.size() << '\n';
    for (auto e:res) cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << '\n';
}
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
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    if (n==2){cout << 2 << '\n'; return 0;}

    int r;
    for (int i=0;i<n;++i){
        if (G[i].size()!=1){
            r=i;
        }
    }

    vector<ll> sub(n,1),sum(n);
    ll ans=IINF;
    auto dfs=[&](auto self,int v,int p)->ll{
        map<ll,pair<ll,ll>> mp;
        for (int u:G[v]){
            if (u==p) continue;
            ll ch=self(self,u,v);
            if (!mp.count(sub[u])) mp[sub[u]]={IINF,IINF};
            if (ch<=mp[sub[u]].first){
                mp[sub[u]].second=mp[sub[u]].first;
                mp[sub[u]].first=ch;
            } else if (ch<=mp[sub[u]].second){
                mp[sub[u]].second=ch;
            }
            sub[v]+=sub[u];
        }
        vector<pair<ll,ll>> cand;
        for (auto p:mp){
            if (p.second.first!=IINF) cand.emplace_back(p.first,p.second.first);
            if (p.second.second!=IINF) cand.emplace_back(p.first,p.second.second);
        }
        for (int i=0;i<cand.size();++i){
            for (int j=i+1;j<cand.size();++j){
                ans=min(ans,(ll)(n-cand[i].first-cand[j].first)*(n-cand[i].first-cand[j].first)+cand[i].second+cand[j].second);
            }
        }
        ll Min=sub[v]*sub[v];
        for (int u:G[v]){
            if (u==p) continue;
            Min=min(Min,sum[u]+(sub[v]-sub[u])*(sub[v]-sub[u]));
        }
        return sum[v]=Min;
    };

    dfs(dfs,r,-1);
    cout << (ll)n*(n-1)/2+((ll)n*n-ans)/2 << '\n';
}
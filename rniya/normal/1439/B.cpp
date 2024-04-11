#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    queue<int> que;
    auto erase=[&](int K)->vector<int>{
        vector<int> deg(n,0),dead(n,0);
        for (int v=0;v<n;++v){
            deg[v]=G[v].size();
            if (deg[v]<K){
                que.emplace(v);
                dead[v]=1;
            }
        }
        while (!que.empty()){
            int v=que.front(); que.pop();
            for (int u:G[v]){
                if (dead[u]) continue;
                if (--deg[u]<K){
                    que.emplace(u);
                    dead[u]=1;
                }
            }
        }
        return dead;
    };

    vector<int> check1=erase(k),ans1;
    for (int i=0;i<n;++i){
        if (!check1[i]){
            ans1.emplace_back(i+1);
        }
    }
    if (!ans1.empty()){
        cout << 1 << ' ' << ans1.size() << '\n';
        cout << ans1 << '\n';
        return;
    }

    if ((ll)k*(k-1)/2>m){
        cout << -1 << '\n';
        return;
    }

    vector<int> check=erase(k-1),deg(n,0);
    for (int v=0;v<n;++v){
        if (check[v]) continue;
        sort(ALL(G[v]));
        for (int u:G[v]){
            if (check[u]) continue;
            ++deg[v];
        }
        if (deg[v]<k) que.emplace(v);
    }

    while (!que.empty()){
        int v=que.front(); que.pop();
        if (check[v]) continue;
        check[v]=1;
        vector<int> ans2;
        ans2.emplace_back(v);
        for (int u:G[v]){
            if (check[u]) continue;
            ans2.emplace_back(u);
            if (--deg[u]<k) que.emplace(u);
        }
        bool ok=true;
        if (ans2.size()<k) ok=false;
        else {
            for (int i=1;i<ans2.size();++i){
                for (int j=i+1;j<ans2.size();++j){
                    auto itr=lower_bound(ALL(G[ans2[i]]),(ans2[j]));
                    if (itr==G[ans2[i]].end()||*itr!=ans2[j]){
                        ok=false;
                    }
                }
            }
        }
        if (ok){
            cout << 2 << '\n';
            for (int i=0;i<k;++i) cout << ans2[i]+1 << (i+1==k?'\n':' ');
            return;
        }
    }

    cout << -1 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}
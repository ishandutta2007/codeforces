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

void solve(){
    int n,x,y; cin >> n >> x >> y;
    vector<int> b(n),c(n),cnt(n+2); cin >> b;
    vector<vector<int>> pos(n+2);
    for (int i=0;i<n;++i){
        c[i]=b[i];
        pos[b[i]].emplace_back(i);
    }
    int unused;
    priority_queue<pair<int,int>> pq;
    for (int i=1;i<=n+1;++i){
        cnt[i]=pos[i].size();
        if (pos[i].empty()) unused=i;
        else pq.emplace(pos[i].size(),i);
    }
    vector<int> ans(n),use;
    vector<pair<int,int>> skip;
    for (int i=0;i<x+(n-y);++i){
        auto p=pq.top(); pq.pop();
        int v=p.second;
        if (i<x) ans[pos[v].back()]=v,--cnt[v];
        else c[pos[v].back()]=unused,skip.emplace_back(v,pos[v].back());
        pos[v].pop_back();
        if (!pos[v].empty()) pq.emplace(pos[v].size(),v);
    }
    int Max=0;
    for (int i=1;i<=n+1;++i){
        if (cnt[i]+(int)pos[i].size()>n-x){
            cout << "NO" << '\n';
            return;
        }
        chmax(Max,pos[i].size());
    }
    for (int i=(int)skip.size()-1;i>=0;--i) pos[skip[i].first].emplace_back(skip[i].second);
    for (int i=1;i<=n+1;++i){
        for (int u:pos[i]){
            use.emplace_back(u);
        }
    }
    for (int i=0;i<n-x;++i) ans[use[i]]=c[use[(i+Max)%(n-x)]];
    cout << "YES" << '\n';
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
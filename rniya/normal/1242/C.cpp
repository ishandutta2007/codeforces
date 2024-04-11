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

using T=tuple<int,int,int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin >> k;
    vector<int> n(k);
    vector<vector<int>> a(k);
    map<int,int> mp;
    vector<ll> sum(k,0);
    ll whole=0;
    for (int i=0;i<k;++i){
        cin >> n[i];
        for (int j=0;j<n[i];++j){
            int A; cin >> A;
            a[i].emplace_back(A);
            mp[A]=i; sum[i]+=A;
        }
        whole+=sum[i];
    }

    if (whole%k!=0){cout << "No" << '\n'; return 0;}
    ll ave=whole/k;

    auto check=[&](int i,int A)->vector<T>{
        vector<T> res;
        map<int,int> take;
        while(1){
            take[i]=A;
            ll nxt=ave-(sum[i]-A);
            if (!mp.count(nxt)) return {};
            int j=mp[nxt];
            res.emplace_back(j,nxt,i);
            if (take.count(j)){
                if (take[j]!=nxt) return {};
                sort(res.begin(),res.end());
                return res;
            }
            i=j,A=nxt;
        }
    };

    pair<int,int> imp={-1,-1},ori={0,0};
    vector<pair<int,int>> dp(1<<k,imp);
    map<int,vector<T>> can;
    for (int i=0;i<k;++i){
        for (int j=0;j<n[i];++j){
            vector<T> used=check(i,a[i][j]);
            if (used.empty()) continue;
            vector<int> v;
            for (auto t:used) v.emplace_back(get<0>(t));
            int mask=0;
            for (int x:v) mask|=(1<<x);
            if (__builtin_popcount(mask)!=v.size()) continue;
            if (!can.count(mask)){
                can[mask]=used;
                dp[mask]=ori;
            }
        }
    }

    dp[0]=imp;
    for (int mask=1;mask<(1<<k);++mask){
        if (dp[mask]==ori) continue;
        for (int sub=mask;;sub=(sub-1)&mask){
            if (dp[sub]!=imp&&dp[mask^sub]!=imp) dp[mask]={sub,mask^sub};
            if (!sub) break;
        }
    }

    if (dp[(1<<k)-1]==imp){cout << "No" << '\n'; return 0;}
    cout << "Yes" << '\n';

    queue<int> que;
    que.emplace((1<<k)-1);
    vector<T> ans;
    while(!que.empty()){
        int mask=que.front(); que.pop();
        if (dp[mask]==ori){
            for (auto t:can[mask]){
                ans.emplace_back(t);
            }
        } else {
            que.emplace(dp[mask].first);
            que.emplace(dp[mask].second);
        }
    }

    sort(ans.begin(),ans.end());
    for (int i=0;i<k;++i) cout << get<1>(ans[i]) << ' ' << get<2>(ans[i])+1 << '\n';
}
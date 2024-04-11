#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
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
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    map<int,int> m;
    for (int i=0;i<n;++i) ++m[a[i]];
    vector<int> cnt;
    for (auto p:m) cnt.emplace_back(p.second);
    sort(all(cnt));
    int ans=0,s=cnt.size();
    for (int i=1;i<=cnt[s-1];++i){
        int now=-1,nxt=i,sum=0;
        while(now<s){
            int ub=s,lb=now;
            while(ub-lb>1){
                int mid=(ub+lb)>>1;
                (cnt[mid]>=nxt?ub:lb)=mid;
            }
            now=ub;
            if (now>=s) break;
            sum+=nxt; nxt<<=1;
        }
        chmax(ans,sum);
    }
    cout << ans << '\n';
}
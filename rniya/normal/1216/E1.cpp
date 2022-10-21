#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

const int MAX=1e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> sum(MAX,0),rui(MAX,0);
    int digit=1;
    for (int i=1;i<MAX;++i){
        sum[i]=sum[i-1]+digit;
        if (i==9||i==99||i==999||i==9999||i==99999) ++digit;
    }
    ll Sum=0;
    for (int i=1;i<MAX;++i){
        rui[i]=sum[i]+Sum;
        Sum+=sum[i];
    }
    int q; cin >> q;
    for (;q--;){
        ll k; cin >> k;
        auto itr=lower_bound(rui.begin(),rui.end(),k);
        k-=*(--itr);
        int id=lower_bound(sum.begin(),sum.end(),k)-sum.begin();
        k-=sum[id-1];
        string ans=to_string(id);
        cout << ans[k-1] << '\n';
    }
}
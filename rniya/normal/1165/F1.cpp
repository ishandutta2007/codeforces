#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int MAX=4e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> k(n);
    int sum=0;
    for (int i=0;i<n;++i) cin >> k[i],sum+=k[i];
    vector<set<int>> sale(n);
    for (int i=0;i<m;++i){
        int d,t; cin >> d >> t;
        sale[--t].emplace(-d);
    }
    int lb=0,ub=MAX;
    vector<pair<int,int>> mic;
    while(ub-lb>1){
        int mid=(ub+lb)>>1;
        mic.clear();
        for (int i=0;i<n;++i){
            auto itr=sale[i].lower_bound(-mid);
            if (itr!=sale[i].end()) mic.emplace_back(-(*itr),k[i]);
        }
        sort(mic.begin(),mic.end());
        mic.emplace_back(mid,0);
        int now=0,have=0,rest=sum;
        for (auto p:mic){
            have+=p.first-now; now=p.first;
            int buy=min(have,p.second);
            have-=buy; rest-=buy;
        }
        (rest*2<=have?ub:lb)=mid;
    }
    cout << ub << '\n';
}
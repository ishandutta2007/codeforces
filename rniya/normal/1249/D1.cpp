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

const int MAX_X=2e5+10;
using P=pair<int,pair<int,int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    priority_queue<P,vector<P>,greater<P>> pq;
    for (int i=0;i<n;++i){
        int l,r; cin >> l >> r;
        pq.push({l,{r,i+1}});
    }
    set<pair<int,int>> greedy;
    vector<int> ans;
    for (int i=1;i<MAX_X;++i){
        while(!pq.empty()&&pq.top().first==i){
            auto t=pq.top(); pq.pop();
            greedy.emplace(t.second);
        }
        while(k<greedy.size()){
            auto p=*greedy.rbegin(); greedy.erase(p);
            ans.emplace_back(p.second);
        }
        while(!greedy.empty()&&(*greedy.begin()).first==i){
            greedy.erase(greedy.begin());
        }
    }
    int m=ans.size();
    cout << m << '\n';
    for (int i=0;i<m;++i) cout << ans[i] << (i+1==m?'\n':' ');
}
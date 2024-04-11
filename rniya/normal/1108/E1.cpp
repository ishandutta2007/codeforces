#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
    int n,m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    vector<int> l(m),r(m);
    vector<pair<int,int>> seg;
    for (int i=0;i<m;++i){
        cin >> l[i] >> r[i];
        seg.emplace_back(--l[i],--r[i]);
    }
    sort(all(seg));
    int update=0,ans=-INF,pos,now=0,Max=*max_element(all(a));
    vector<int> imos(n+1,0),sum(n);
    for (int i=0;i<n;++i) sum[i]=a[i];
    priority_queue<P,vector<P>,greater<P>> pq;
    for (int i=0;i<n;++i){
        while(now<m&&seg[now].first==i){
            auto p=seg[now++];
            --imos[p.first]; ++imos[p.second+1];
            update=1;
            pq.emplace(p.second,p.first);
        }
        if (update){
            int rui=0;
            Max=-INF;
            for (int j=0;j<n;++j){
                rui+=imos[j];
                sum[j]=a[j]+rui;
                chmax(Max,sum[j]);
            }
        }
        if (chmax(ans,Max-sum[i])) pos=i;
        update=0;
        while(!pq.empty()&&pq.top().first==i){
            auto p=pq.top(); pq.pop();
            ++imos[p.second]; --imos[p.first+1];
            update=1;
        }
    }
    int maxi=*max_element(all(a)),mini=*min_element(all(a));
    if (chmax(ans,maxi-mini)){
        cout << ans << '\n';
        cout << 0 << '\n';
        cout << '\n';
        return 0;
    }
    cout << ans << '\n';
    vector<int> res;
    for (int i=0;i<m;++i){
        if (l[i]<=pos&&pos<=r[i]){
            res.emplace_back(i+1);
        }
    }
    cout << res.size() << '\n';
    cout << res << '\n';
}
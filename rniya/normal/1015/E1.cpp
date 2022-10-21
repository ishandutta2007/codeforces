#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
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
    vector<string> S(n); cin >> S;
    struct star{
        int x,y,s;
        star(int x,int y,int s):x(x),y(y),s(s){}
    };
    vector<vector<int>> row(n),col(m);
    for (int i=0;i<n;++i){
        row[i].emplace_back(-1);
        for (int j=0;j<m;++j) if (S[i][j]=='.'){
            row[i].emplace_back(j);
        }
        row[i].emplace_back(m);
    }
    for (int j=0;j<m;++j){
        col[j].emplace_back(-1);
        for (int i=0;i<n;++i) if (S[i][j]=='.'){
            col[j].emplace_back(i);
        }
        col[j].emplace_back(n);
    }
    vector<vector<int>> imos(n+2,vector<int>(m+2,0));
    vector<star> ans;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]=='.') continue;
            int posx=lower_bound(ALL(row[i]),j)-row[i].begin(),
                posy=lower_bound(ALL(col[j]),i)-col[j].begin();
            int L=row[i][posx-1],R=row[i][posx],U=col[j][posy-1],D=col[j][posy];
            int len=min({j-L-1,R-j-1,i-U-1,D-i-1});
            if (!len) continue;
            ans.emplace_back(i+1,j+1,len);
            ++imos[i+1][j-len+1]; --imos[i+1][j+len+2];
            --imos[i+2][j-len+1]; ++imos[i+2][j+len+2];
            ++imos[i-len+1][j+1]; --imos[i+len+2][j+1];
            --imos[i-len+1][j+2]; ++imos[i+len+2][j+2];
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            imos[i+1][j+1]+=imos[i+1][j]+imos[i][j+1]-imos[i][j];
            if (S[i][j]=='*'&&!imos[i+1][j+1]){
                cout << -1 << '\n'; return 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto st:ans) cout << st.x << ' ' << st.y << ' ' << st.s << '\n';
}
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

template<typename T>
struct CumulativeSum2D{
    int H,W;
    vector<vector<T>> dat;
    CumulativeSum2D(vector<vector<T>> v){
        H=v.size(),W=v[0].size();
        dat.assign(H+1,vector<T>(W+1,0));
        for (int i=0;i<H;++i){
            for (int j=0;j<W;++j){
                dat[i+1][j+1]=v[i][j];
                dat[i+1][j+1]+=dat[i+1][j]+dat[i][j+1]-dat[i][j];
            }
        }
    }
    T query(int sx,int gx,int sy,int gy){ //[sx,gx),[sy,gy)
        return dat[gx][gy]-dat[sx][gy]-dat[gx][sy]+dat[sx][sy];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> S(n,vector<int>(m));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            char c; cin >> c;
            S[i][j]=(c=='X');
        }
    }
    CumulativeSum2D<int> CSX(S);
    auto check=[&](int mid){
        vector<vector<int>> imos(n+1,vector<int>(m+1,0));
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (i-mid>=0&&i+mid<n&&j-mid>=0&&j+mid<m){
                    if (CSX.query(i-mid,i+mid+1,j-mid,j+mid+1)==(ll)(2*mid+1)*(2*mid+1)){
                        ++imos[i-mid][j-mid]; ++imos[i+mid+1][j+mid+1];
                        --imos[i-mid][j+mid+1]; --imos[i+mid+1][j-mid];
                    }
                }
            }
        }
        for (int i=0;i<=n;++i){
            for (int j=0;j<m;++j){
                imos[i][j+1]+=imos[i][j];
            }
        }
        for (int j=0;j<=m;++j){
            for (int i=0;i<n;++i){
                imos[i+1][j]+=imos[i][j];
            }
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (S[i][j]&&!imos[i][j]) return false;
            }
        }
        return true;
    };
    int lb=-1,ub=min(n,m);
    while(ub-lb>1){
        int mid=(ub+lb)>>1;
        (check(mid)?lb:ub)=mid;
    }
    cout << lb << '\n';
    vector<vector<char>> ans(n,vector<char>(m,'.'));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (i-lb>=0&&i+lb<n&&j-lb>=0&&j+lb<m){
                if (CSX.query(i-lb,i+lb+1,j-lb,j+lb+1)==(2*lb+1)*(2*lb+1)){
                    ans[i][j]='X';
                }
            }
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
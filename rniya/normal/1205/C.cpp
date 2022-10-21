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

const int dx[2]={1,0},dy[2]={0,1};
int n,a;

int ask(int x_1,int y_1,int x_2,int y_2){
    ++x_1,++y_1,++x_2,++y_2;
    assert(1<=x_1&&x_1<=n);
    assert(1<=y_1&&y_1<=n);
    assert(1<=x_1&&x_1<=n);
    assert(1<=y_2&&y_2<=n);
    assert(x_1+y_1+2<=x_2+y_2);
    cout << "? " << x_1 << ' ' << y_1 << ' ' << x_2 << ' ' << y_2 << endl;
    int res; cin >> res;
    if (res<0) exit(0);
    return res^1;
}

void answer(vector<vector<int>> v){
    cout << '!' << '\n';
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j) cout << v[i][j];
        if (i==n-1) cout << endl;
        else cout << '\n';
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;

    vector<vector<int>> ans(n,vector<int>(n,-1));
    ans[0][0]=1; ans[n-1][n-1]=0;

    for (int j=2;j<2*(n-1);j+=2){
        for (int i=0;i<=j;++i){
            int x=i,y=j-i,px,py;
            if (n<=x||n<=y) continue;
            if (x==0) px=x,py=y-2;
            else if (x==1) px=x-1,py=y-1;
            else px=x-2,py=y;
            a=ask(px,py,x,y);
            ans[x][y]=ans[px][py]^a;
        }
    }

    ans[0][1]=0;
    int p=ask(0,1,1,2),q=ask(1,0,1,2);
    ans[1][2]=ans[0][1]^p,ans[1][0]=ans[1][2]^q;
    for (int j=3;j<2*(n-1);j+=2){
        for (int i=0;i<=j;++i){
            int x=i,y=j-i,px,py;
            if (x==1&&y==2) continue;
            if (n<=x||n<=y) continue;
            if (x==0) px=x,py=y-2;
            else if (x==1) px=x-1,py=y-1;
            else px=x-2,py=y;
            a=ask(px,py,x,y);
            ans[x][y]=ans[px][py]^a;
        }
    }

    int ok=1,finished=0;
    auto dfs=[&](auto self,int x,int y,int sx,int sy,int c,int XOR)->void{
        if (finished) return;
        XOR^=ans[x][y];
        if (c==3){
            if (XOR) return;
            a=ask(sx,sy,x,y);
            if (!a&&ans[sx][sy]!=ans[x][y]) ok=0;
            if (a&&ans[sx][sy]==ans[x][y]) ok=0;
            finished=1;
            return;
        }
        for (int i=0;i<2;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (n<=nx||n<=ny) continue;
            self(self,nx,ny,sx,sy,c+1,XOR);
        }
    };
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            dfs(dfs,i,j,i,j,0,0);
        }
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (((i+j)&1)&&!ok){
                ans[i][j]^=1;
            }
        }
    }

    answer(ans);
}
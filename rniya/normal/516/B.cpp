#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

const string a="^<v>",b="v>^<";

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<string> S(n); cin >> S;

    auto count=[&](int x,int y){
        int res=0;
        for (int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            res+=(S[nx][ny]=='.');
        }
        return res;
    };
    queue<pair<int,int>> que;
    int odd=0,even=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]=='*') continue;
            ++((i+j)&1?odd:even);
            int margin=count(i,j);
            if (!margin){
                cout << "Not unique" << '\n';
                return 0;
            }
            if (margin==1) que.emplace(i,j);
        }
    }

    if (odd!=even){
        cout << "Not unique" << '\n';
        return 0;
    }

    auto check=[&](int x,int y){
        for (int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            if (S[nx][ny]!='.') continue;
            int margin=count(nx,ny);
            if (!margin){
                cout << "Not unique" << '\n';
                exit(0);
            }
            if (margin==1){
                que.emplace(nx,ny);
            }

        }
    };
    while (!que.empty()){
        auto p=que.front(); que.pop();
        int x=p.first,y=p.second;
        if (S[x][y]!='.') continue;
        for (int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            if (S[nx][ny]=='.'){
                S[x][y]=a[i];
                S[nx][ny]=b[i];
                check(x,y);
                check(nx,ny);
                --odd; break;
            }
        }
    }

    if (odd>1){
        cout << "Not unique" << '\n';
        return 0;
    }
    for (int i=0;i<n;++i) cout << S[i] << '\n';
}
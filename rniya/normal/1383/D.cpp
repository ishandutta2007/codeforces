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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m));
    vector<int> R(n),C(m);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> A[i][j];
            R[i]=max(R[i],A[i][j]);
            C[j]=max(C[j],A[i][j]);
        }
    }
    sort(R.begin(),R.end()); reverse(R.begin(),R.end());
    sort(C.begin(),C.end()); reverse(C.begin(),C.end());
    R.emplace_back(0); C.emplace_back(0);
    vector<vector<int>> ans(n,vector<int>(m,-1));
    vector<int> used(n*m+1,0);
    int r=0,c=0,now=1;
    while(r<n||c<m){
        if (R[r]==C[c]){
            ans[r][c]=R[r]; used[R[r]]=1;
            ++r,++c;
        } else if (R[r]<C[c]){
            ans[r-1][c]=C[c]; used[C[c]]=1;
            ++c;
        } else {
            ans[r][c-1]=R[r]; used[R[r]]=1;
            ++r;
        }
    }
    --r,--c;
    while(r>=0&&c>=0){
        if (R[r]<=C[c]){
            for (int j=0;j<=c;++j){
                if (ans[r][j]<0){
                    while(now<=n*m&&used[now]) ++now;
                    ans[r][j]=now++;
                }
            }
            --r;
        } else {
            for (int i=0;i<=r;++i){
                if (ans[i][c]<0){
                    while(now<=n*m&&used[now]) ++now;
                    ans[i][c]=now++;
                }
            }
            --c;
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cout << ans[i][j] << (j+1==m?'\n':' ');
        }
    }
}
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

const int MAX_S=255;
int dp[MAX_S][MAX_S][MAX_S];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    string S; cin >> S;

    vector<vector<int>> nxt(n+1,vector<int>(26,INF));
    for (int i=n-1;i>=0;--i){
        for (int j=0;j<26;++j) nxt[i][j]=nxt[i+1][j];
        nxt[i][S[i]-'a']=i;
    }
    auto next=[&](int x,char c){
        if (x==INF) return INF;
        return nxt[x][c-'a']+1;
    };

    for (int i=0;i<MAX_S;++i){
        for (int j=0;j<MAX_S;++j){
            for (int k=0;k<MAX_S;++k){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    vector<string> A(3,"");
    auto add=[&](int id,char c){
        int s=A[id].size();
        if (id==0){
            for (int j=0;j<MAX_S;++j){
                for (int k=0;k<MAX_S;++k){
                    chmin(dp[s+1][j][k],next(dp[s][j][k],c));
                }
            }
            for (int j=0;j<MAX_S;++j){
                for (int k=0;k<MAX_S;++k){
                    if (j<A[1].size()) chmin(dp[s+1][j+1][k],next(dp[s+1][j][k],A[1][j]));
                    if (k<A[2].size()) chmin(dp[s+1][j][k+1],next(dp[s+1][j][k],A[2][k]));
                }
            }
        } else if (id==1){
            for (int i=0;i<MAX_S;++i){
                for (int k=0;k<MAX_S;++k){
                    chmin(dp[i][s+1][k],next(dp[i][s][k],c));
                }
            }
            for (int i=0;i<MAX_S;++i){
                for (int k=0;k<MAX_S;++k){
                    if (i<A[0].size()) chmin(dp[i+1][s+1][k],next(dp[i][s+1][k],A[0][i]));
                    if (k<A[2].size()) chmin(dp[i][s+1][k+1],next(dp[i][s+1][k],A[2][k]));
                }
            }
        } else {
            for (int i=0;i<MAX_S;++i){
                for (int j=0;j<MAX_S;++j){
                    chmin(dp[i][j][s+1],next(dp[i][j][s],c));
                }
            }
            for (int i=0;i<MAX_S;++i){
                for (int j=0;j<MAX_S;++j){
                    if (i<A[0].size()) chmin(dp[i+1][j][s+1],next(dp[i][j][s+1],A[0][i]));
                    if (j<A[1].size()) chmin(dp[i][j+1][s+1],next(dp[i][j][s+1],A[1][j]));
                }
            }
        }
        A[id]+=c;
        return dp[A[0].size()][A[1].size()][A[2].size()]<INF;
    };
    auto del=[&](int id){
        int s=A[id].size();
        if (id==0){
            for (int j=0;j<MAX_S;++j){
                for (int k=0;k<MAX_S;++k){
                    dp[s][j][k]=INF;
                }
            }
        } else if (id==1){
            for (int i=0;i<MAX_S;++i){
                for (int k=0;k<MAX_S;++k){
                    dp[i][s][k]=INF;
                }
            }
        } else {
            for (int i=0;i<MAX_S;++i){
                for (int j=0;j<MAX_S;++j){
                    dp[i][j][s]=INF;
                }
            }
        }
        A[id].pop_back();
        return dp[A[0].size()][A[1].size()][A[2].size()]<INF;
    };
    for (;q--;){
        char type; int id; cin >> type >> id; --id;
        if (type=='+'){
            char c; cin >> c;
            cout << (add(id,c)?"YES":"NO") << '\n';
        } else {
            cout << (del(id)?"YES":"NO") << '\n';
        }
    }
}
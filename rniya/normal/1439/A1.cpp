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

void solve(){
    int n,m; cin >> n >> m;
    vector<string> S(n); cin >> S;

    vector<vector<int>> ans(3*n*m,vector<int>(6));
    int ope=0;
    auto flip=[&](int a){
        for (int i=0;i<6;i+=2){
            S[ans[a][i]][ans[a][i+1]]=(S[ans[a][i]][ans[a][i+1]]=='0'?'1':'0');
        }
    };
    auto flip1=[&](int x,int y){
        if (S[x][y]=='0'){
            if (S[x][y+1]=='0') return;
            ans[ope][0]=x+1; ans[ope][1]=y;
            ans[ope][2]=x; ans[ope][3]=y+1;
            ans[ope][4]=x+1; ans[ope][5]=y+1;
            flip(ope); ++ope;
            return;
        }
        ans[ope][0]=x; ans[ope][1]=y;
        ans[ope][2]=x+1; ans[ope][3]=y;
        if (S[x][y+1]=='1') ans[ope][4]=x,ans[ope][5]=y+1;
        else ans[ope][4]=x+1,ans[ope][5]=y+1;
        flip(ope); ++ope;
    };
    auto flip2=[&](int x,int y){
        if (S[x][y]=='0'&&S[x+1][y]=='0') return;
        ans[ope][0]=x; ans[ope][1]=y+1;
        if (S[x][y]=='1'&&S[x+1][y]=='1'){
            ans[ope][2]=x; ans[ope][3]=y;
            ans[ope][4]=x+1; ans[ope][5]=y;
        } else if (S[x][y]=='1'){
            ans[ope][2]=x; ans[ope][3]=y;
            ans[ope][4]=x+1; ans[ope][5]=y+1;
        } else {
            ans[ope][2]=x+1; ans[ope][3]=y;
            ans[ope][4]=x+1; ans[ope][5]=y+1;
        }
        flip(ope); ++ope;
    };
    auto flip3=[&](int x,int y){
        vector<vector<pair<int,int>>> pos(2);
        for (int i=0;i<2;++i){
            for (int j=0;j<2;++j){
                pos[S[x+i][y+j]-'0'].emplace_back(x+i,y+j);
            }
        }
        int cnt=pos[1].size();
        if (cnt==0) return;
        if (cnt==1){
            for (int k=0;k<3;++k){
                int ok=0;
                for (int i=0;i<2;++i){
                    for (int j=0;j<2;++j){
                        int nx=x+i,ny=y+j;
                        if (pos[0][k].first==nx&&pos[0][k].second==ny) continue;
                        ans[ope][ok++]=nx; ans[ope][ok++]=ny;
                    }
                }
                flip(ope); ++ope;
            }
        }
        if (cnt==2){
            for (int i=0;i<2;++i){
                ans[ope][0]=pos[0][0].first; ans[ope][1]=pos[0][0].second;
                ans[ope][2]=pos[0][1].first; ans[ope][3]=pos[0][1].second;
                ans[ope][4]=pos[1][i].first; ans[ope][5]=pos[1][i].second;
                flip(ope); ++ope;
            }
        }
        if (cnt==3){
            int ok=0;
            for (int i=0;i<2;++i){
                for (int j=0;j<2;++j){
                    int nx=x+i,ny=y+j;
                    if (S[nx][ny]=='1'){
                        ans[ope][ok++]=nx; ans[ope][ok++]=ny;
                    }
                }
            }
            flip(ope); ++ope;
        }
        if (cnt==4){
            int ok=0;
            for (int i=0;i<3;++i){
                ans[ope][ok++]=pos[1].back().first; ans[ope][ok++]=pos[1].back().second;
                pos[0].emplace_back(pos[1].back());
                pos[1].pop_back();
            }
            flip(ope); ++ope;
            for (int k=0;k<3;++k){
                int ok=0;
                for (int i=0;i<2;++i){
                    for (int j=0;j<2;++j){
                        int nx=x+i,ny=y+j;
                        if (pos[0][k].first==nx&&pos[0][k].second==ny) continue;
                        ans[ope][ok++]=nx; ans[ope][ok++]=ny;
                    }
                }
                flip(ope); ++ope;
            }
        }
    };
    for (int j=0;j<m-1;++j){
        for (int i=0;i<n-2;++i){
            flip1(i,j);
            // for (int k=0;k<n;++k) cerr << S[k] << '\n';
            // cerr << '\n';
        }
    }
    for (int i=0;i<m-2;++i){
        flip2(n-2,i);
    }
    // for (int i=0;i<n;++i) cerr << S[i] << '\n';
    flip3(n-2,m-2);

    cout << ope << '\n';
    for (int i=0;i<ope;++i){
        for (int j=0;j<6;++j){
            cout << ans[i][j]+1 << (j+1==6?'\n':' ');
        }
    }

    // for (int i=0;i<n;++i) cerr << S[i] << '\n';
    // cerr << '\n';

    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            assert(S[i][j]=='0');
        }
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}
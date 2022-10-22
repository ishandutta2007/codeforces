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
    cout << '(' << p.first << ',' << p.second << ')';
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

const int MAX_N=101;

vector<int> cand[MAX_N][MAX_N];

int det(vector<int> v,int a){return a==v[0]?v[1]:v[0];}

string solve(int l,int r){
    cout << "? " << l << ' ' << r << endl; --l,--r;
    auto num=[](int l,int r){return (r-l+1)*(r-l+2)/2;};
    vector<vector<string>> S(r-l+2);
    for (int i=0;i<num(l,r);++i){
        string s; cin >> s;
        S[s.size()].emplace_back(s);
    }
    vector<vector<int>> cnt(r-l+2,vector<int>(26,0));
    for (int i=1;i<r-l+2;++i){
        for (int j=0;j<S[i].size();++j){
            for (char c:S[i][j]){
                ++cnt[i][c-'a'];
            }
        }
    }
    for (int i=r-l,L=l,R=r,d=2;L<=R;--i,++L,--R,++d){
        if (i==r-l){
            for (int j=0;j<2;++j){
                vector<int> cnt2(26,0);
                for (char c:S[i][j]) ++cnt2[c-'a'];
                for (int k=0;k<26;++k){
                    if (cnt[i+1][k]!=cnt2[k]){
                        cand[L][R].emplace_back(k);
                    }
                }
            }
        } else {
            for (int ll=l,rr=r;ll<L;++ll,--rr){
                for (int j=0;j<2;++j){
                    cnt[i][cand[ll][rr][j]]-=ll-l+1;
                }
            }
            for (int j=0;j<26;++j){
                if (cnt[i][j]%d!=0){
                    cand[L][R].emplace_back(j);
                }
            }
        }
        if (cand[L][R].size()==1) cand[L][R].emplace_back(cand[L][R][0]);
        for (int j=0;j<2;++j) cand[R][L]=cand[L][R];
    }
    return S[r-l+1][0];
}

vector<int> solve_half(int n){
    if (n==1){
        cout << "? " << 1 << ' ' << 1 << endl;
        char res; cin >> res;
        return {res-'a'};
    }
    if (n==2){
        cout << "? " << 1 << ' ' << 1 << endl;
        char res1; cin >> res1;
        cout << "? " << 2 << ' ' << 2 << endl;
        char res2; cin >> res2;
        return {res1-'a',res2-'a'};
    }
    vector<vector<int>> cnt(2,vector<int>(26));
    for (int i=0;i<2;++i){
        string s=solve(i+1,n);
        for (char c:s) ++cnt[i][c-'a'];
    }
    vector<int> ans(n);
    for (int j=0;j<26;++j){
        if (cnt[0][j]!=cnt[1][j]){
            ans[0]=j;
        }
    }
    for (int i=0,L=0,R=n-1;i<n-1;++i){
        if (i&1){
            ans[L]=det(cand[L][R],ans[R]);
            --R;
        } else {
            ans[R]=det(cand[L][R],ans[L]);
            ++L;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n==1){
        cout << "? " << 1 << ' ' << 1 << endl;
        char res; cin >> res;
        cout << "! " << res << endl;
        return 0;
    }
    if (n==2){
        cout << "? " << 1 << ' ' << 1 << endl;
        char res1; cin >> res1;
        cout << "? " << 2 << ' ' << 2 << endl;
        char res2; cin >> res2;
        cout << "! " << res1 << res2 << endl;
        return 0;
    }
    int h=n/2;
    vector<int> half=solve_half(h);
    debug(half);
    solve(1,n);
    vector<int> ans(n);
    for (int i=0;i<h;++i) ans[i]=half[i];
    for (int i=h;i<n;++i){
        if ((n&1)&&i==h) ans[i]=cand[i][i][0];
        else ans[i]=det(cand[n-1-i][i],ans[n-1-i]);
    }
    cout << "! ";
    for (int i=0;i<n;++i) cout << (char)('a'+ans[i]);
    cout << endl;
}
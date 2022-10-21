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

vector<bool> prime_table(int n){
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int i=2;i<=n;++i) if (prime[i]){
        for (int j=i+i;j<=n;j+=i) prime[j]=false;
    }
    return prime;
}
vector<int> primes(int n){
    vector<int> res;
    vector<bool> pt=prime_table(n);
    for (int i=2;i<=n;++i) if (pt[i]){
        res.emplace_back(i);
    }
    return res;
}

const int MAX=2e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> P=primes(MAX);
    vector<int> near;
    for (int i=0;i<P.size();++i){
        for (int j=i+1;j<P.size();++j){
            if ((ll)P[i]*P[j]>=MAX) break;
            near.emplace_back(P[i]*P[j]);
        }
    }
    sort(ALL(near));
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        if (n>=100){
            cout << "YES" << '\n';
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n-30 << '\n';
            continue;
        }
        bool ok=false;
        for (int i=0;i<30;++i){
            for (int j=i+1;j<30;++j){
                for (int k=j+1;k<30;++k){
                    if (near[i]+near[j]+near[k]<n){
                        int rest=n-(near[i]+near[j]+near[k]);
                        if (rest!=near[i]&&rest!=near[j]&&rest!=near[k]){
                            cout << "YES" << '\n';
                            cout << near[i] << ' ' << near[j] << ' ' << near[k] << ' ' << rest << '\n';
                            ok=true;
                        }
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (!ok) cout << "NO" << '\n';
    }
}
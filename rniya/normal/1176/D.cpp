#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}
template<typename T>
T extgcd(T a,T b,T &x,T &y){
    T d=a;
    if (b!=0){d=extgcd(b,a%b,y,x); y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}
template<typename T>
int digit(T n){
    string cnt=to_string(n);
    return cnt.size();
}

template<typename T>
bool is_prime(T n){
    for (T i=2;i*i<=n;++i)
        if (n%i==0) return false;
    return 1<n;
}
template<typename T>
vector<T> divisor(T n){
    vector<T> res;
    for (T i=1;i*i<=n;++i) if (n%i==0){
        res.emplace_back(i);
        if (i!=n/i) res.emplace_back(n/i);
    }
    return res;
}
template<typename T>
map<T,int> prime_factor(T n){
    map<T,int> res;
    for (T i=2;i*i<=n;++i)
        while(n%i==0){++res[i]; n/=i;}
    if (n!=1) res[n]=1;
    return res;
}
struct sieve{
    int MAX_VALUE;
    vector<int> primes;
    vector<bool> is_prime;
    sieve(int M):MAX_VALUE(M),is_prime(M,true){}
    int build(){
        is_prime[0]=is_prime[1]=false;
        for (int i=2;i<MAX_VALUE;++i) if (is_prime[i]){
            primes.emplace_back(i);
            for (int j=i*2;j<MAX_VALUE;j+=i) is_prime[j]=false;
        }
        return primes.size();
    }
};

long long modpow(long long a,long long n,long long p){
    long long res=1;
    while(n>0){
        if (n&1LL) res=res*a%p;
        a=a*a%p; n>>=1LL;
    }
    return res;
}
long long modinv(long long a,long long p){
    return modpow(a,p-2,p);
}

template<typename T>
T eular_phi(T n){
    T res=n;
    for (T i=2;i*i<=n;++i) if (n%i==0){
        res=res/i*(i-1);
        while(n%i==0) n/=i;
    }
    if (n!=1) res=res/n*(n-1);
    return res;
}
struct eular_phi_table{
    int MAX_VALUE;
    vector<int> eular;
    eular_phi_table(int M):MAX_VALUE(M),eular(M){}
    void build(){
        iota(eular.begin(),eular.end(),0);
        for (int i=2;i<MAX_VALUE;++i) if (eular[i]==i){
            for (int j=i;j<MAX_VALUE;j+=i){
                eular[j]=eular[j]/i*(i-1);
            }
        }
    }
};

const int MAX=3e6+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> b(2*n); cin >> b;
    multiset<int> P,C;
    for (int i=0;i<2*n;++i){
        if (is_prime(b[i])) P.emplace(b[i]);
        else C.emplace(-b[i]);
    }
    sieve S(MAX); S.build();
    vector<int> Ps=S.primes;
    vector<int> ans;
    for (int c:C){
        ans.emplace_back(-c);
        c*=-1;
        int greatest_divisor;
        for (int i=2;i*i<=c;++i) if (c%i==0){
            greatest_divisor=c/i; break;
        }
        if (is_prime(greatest_divisor)){
            auto itr=P.lower_bound(greatest_divisor);
            P.erase(itr);
        } else {
            auto itr=C.lower_bound(-greatest_divisor);
            C.erase(itr);
        }
    }
    for (int p:P){
        ans.emplace_back(p);
        int super_prime=Ps[p-1];
        auto itr=P.lower_bound(super_prime);
        P.erase(itr);
    }
    for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?'\n':' ');
}
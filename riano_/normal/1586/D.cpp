#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
using Graph = vector<vector<ll>>;

const ll mod = 998244353;
template<uint64_t mod>
struct modint{
    uint64_t val;
    constexpr modint(const int64_t val_=0) noexcept:val((val_%int64_t(mod)+int64_t(mod))%int64_t(mod)){}
    constexpr modint operator-() const noexcept{
        return modint(*this)=mod-val;
    }
    constexpr modint operator+(const modint rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept{
        val+=rhs.val;
        val-=((val>=mod)?mod:0);
        return (*this);
    }
    constexpr modint &operator-=(const modint rhs) noexcept{
        val+=((val<rhs.val)?mod:0);
        val-=rhs.val;
        return (*this);
    }
    constexpr modint &operator*=(const modint rhs) noexcept{
        val=val*rhs.val%mod;
        return (*this);
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        uint64_t ex=mod-2;
        modint now=1;
        while(ex){
            now*=((ex&1)?rhs:1);
            rhs*=rhs,ex>>=1;
        }
        return (*this)*=now;
    }
    modint & operator++(){
        val++;
        if (val == mod) val = 0;
        return *this;
    }
    modint operator++(int){
        modint<mod> res = *this;
        ++*this;
        return res;
    }
    constexpr bool operator==(const modint rhs) noexcept{
        return val==rhs.val;
    }
    constexpr bool operator!=(const modint rhs) noexcept{
        return val!=rhs.val;
    }
    friend constexpr ostream &operator<<(ostream& os,const modint x) noexcept{
        return os<<(x.val);
    }
    friend constexpr istream &operator>>(istream& is,modint& x) noexcept{
        uint64_t t;
        is>>t,x=t;
        return is;
    }
};
typedef modint<mod> mint;


//
// nminfactor
vector<int> min_factor;
vector<ll> primes;
vector<int> sieve(int n) {
    vector<int> res(n+1);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i*i <= n; ++i) {
        if (res[i] < i) continue;
        for (int j = i*i; j <= n; j += i) {
            if (res[j] == j) res[j] = i;
        }
    }
    for(int i=2;i<=n;i++){
        if(res[i]==i){
            primes.push_back(i);
        }
    }
    return res;
}

// n("sieve")
// (p1,n1),(p2,n2),...
vector<pair<int,int>> factor(int n) {
    // min_factor  sieve() 
    vector<pair<int,int>> res; int p=-1,cnt=0;
    while (n > 1) {
        if(min_factor[n]!=p&&cnt>0){
            res.push_back(make_pair(p,cnt));
            p = min_factor[n]; cnt = 1;
        }
        else if(min_factor[n]!=p){
            p = min_factor[n]; cnt = 1;
        }
        else cnt++;
        n /= min_factor[n];
        // 
    }
    if(p!=-1) res.push_back(make_pair(p,cnt));
    return res;
}
    

int main() {
    riano_;
    ll N; cin >> N;
    vector<ll> ans(N,0);
    ll res = 0;
    int c = N+1;
    while(res==0){
        c--;
        vector<ll> cand(N,N);
        cand[N-1] = N+1-c;
        if(c==1) break;
        cout << "?" << " ";
        rep(i,N){
            cout << cand[i] << " ";
        }
        cout << endl;
        cin >> res;
    }
    ans[N-1] = c;
    rep(i,N){
        if(i+1==c) continue;
        vector<ll> cand(N,c);
        cand[N-1] = i+1;
        cout << "?" << " ";
        rep(i,N){
            cout << cand[i] << " ";
        }
        cout << endl;
        cin >> res;
        ans[res-1] = i+1;
    }
    cout << "!" << " ";
        rep(i,N){
            cout << ans[i] << " ";
        }
        cout << endl;
}
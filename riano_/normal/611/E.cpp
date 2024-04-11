#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
using Graph = vector<vector<Tp>>;

const ll mod = 1e9+7;
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
mint pw(long long a,long long b,long long m = mod){
    if(a%m==0) return mint(0);
    if(b==0) return mint(1);
    else if(b%2==0){
        long long x = pw(a,b/2,m).val;
        return mint(x*x);
    }
    else{
        long long x = pw(a,b-1,m).val;
        return mint(a*x);
    }
}
mint modinv(long long a, long long m = mod) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    return mint(u);
}
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))

int main() {
    riano_; ll ans = 0;
    ll N;
    cin >> N;
    vector<ll> a(3);
    vector<ll> t;
    rep(i,3){
        cin >> a[i];
    }
    sort(all(a)); reverse(all(a));
    
    
    rep(i,N){
        ll b; cin >> b; t.push_back(b);
    }
    sort(all(t)); reverse(all(t));
    
    ll cnt_ab = 0,cnt_ac = 0,cnt_bc = 0,cnt_a = 0,cnt_b = 0,cnt_c = 0;
    multiset<ll> ss; 
    rep(i,N){
        if(t[i]>a[0]+a[1]+a[2]){
            cout << -1 << endl; return 0;
        }
        if(t[i]>a[0]+a[1]){
            ans++; continue;
        }
        if(t[i]>a[0]+a[2]){
            cnt_ab++; continue;
        }
        if(t[i]>max(a[1]+a[2],a[0])){
            cnt_ac++; continue;
        }
        if(a[0]>=a[1]+a[2]){
            if(t[i]>a[1]+a[2]){
                cnt_a++; continue;
            }
            ss.insert(t[i]);
        }
        else{
            if(t[i]>a[0]){
                cnt_bc++; continue;
            }
            ss.insert(t[i]);
        }
    }

    // for(ll x:ss){
    //     cout << x << " ";
    // }
    // cout << endl;
    // auto itr = ss.begin(); ss.erase(itr);
    // for(ll x:ss){
    //     cout << x << " ";
    // }
    // cout << endl;
    // if(itr==ss.begin()){
    //     cout << "ok" << endl;
    // }

    if(a[0]<a[1]+a[2]){
        ans += cnt_ab+cnt_ac+cnt_bc;
        rep(i,cnt_ab){
            auto itr = ss.upper_bound(a[2]);
            if(itr==ss.begin()) break;
            itr--;
            //cout << *itr << endl;
            ss.erase(itr);
        }
        rep(i,cnt_ac){
            auto itr = ss.upper_bound(a[1]);
            if(itr==ss.begin()) break;
            itr--;
            ss.erase(itr);
        }
        rep(i,cnt_bc){
            auto itr = ss.upper_bound(a[0]);
            if(itr==ss.begin()) break;
            itr--;
            ss.erase(itr);
        }
        while(!ss.empty()){
            auto itr = ss.upper_bound(a[2]);
            if(itr==ss.begin()){
                itr = ss.upper_bound(a[1]+a[2]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
            else{
                itr--;
                ss.erase(itr);
                itr = ss.upper_bound(a[1]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
            itr = ss.upper_bound(a[0]);
            if(itr!=ss.begin()){
                itr--;
                ss.erase(itr);
            }
            ans++;
        }
    }
    else{
        ans += cnt_ab+cnt_ac+cnt_a;
        rep(i,cnt_ab){
            auto itr = ss.upper_bound(a[2]);
            if(itr==ss.begin()) break;
            itr--;
            ss.erase(itr);
        }
        rep(i,cnt_ac){
            auto itr = ss.upper_bound(a[1]);
            if(itr==ss.begin()) break;
            itr--;
            ss.erase(itr);
        }
        rep(i,cnt_a){
            auto itr = ss.upper_bound(a[2]);
            if(itr==ss.begin()){
                itr = ss.upper_bound(a[1]+a[2]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
            else{
                itr--;
                ss.erase(itr);
                itr = ss.upper_bound(a[1]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
        }
        while(!ss.empty()){
            auto itr = ss.upper_bound(a[2]);
            if(itr==ss.begin()){
                itr = ss.upper_bound(a[1]+a[2]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
            else{
                itr--;
                ss.erase(itr);
                itr = ss.upper_bound(a[1]);
                if(itr!=ss.begin()){
                    itr--;
                    ss.erase(itr);
                }
            }
            itr = ss.upper_bound(a[0]);
            if(itr!=ss.begin()){
                itr--;
                ss.erase(itr);
            }
            ans++;
        }
    }

    cout << ans << endl;

    
}
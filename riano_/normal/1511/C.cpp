#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;
 
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


//segment tree
//1-indexed all
class segtree {
public:
    ll n;
    vector<ll> A;
    segtree(ll k){
        n = 1;
        while(n<k){ n *= 2; }
        A=vector<ll>(2*n,0);
    }

    //a[i]x
    void add(ll i,ll x){
        int index = n-1+i;
        A[index] += x;
        while(index>1){
            index /= 2;
            A[index] = A[2*index]+A[2*index+1];
        }
    }

    //a[i]
    void replace(ll i,ll x){
        int index = n-1+i;
        A[index] = x;
        while(index>1){
            index /= 2;
            A[index] = A[2*index]+A[2*index+1];
        }
    }

    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        return rangesum(i,j,1,1,n);
    }

    // a,b k c,d(k=1,c=1,d=n)
    ll rangesum(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 0;
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return A[k];
        }
        else{
            //2
            ll p = rangesum(a,b,k*2,c,(c+d)/2)+rangesum(a,b,k*2+1,(c+d)/2+1,d);
            return p;
        }
    }

};

    
int main() {
    riano_; //ll ans = 2e9;
    ll N,Q; cin >> N >> Q;
    ll c[N];
    ll ip[51];
    bool called[51];
    rep(i,51){
        ip[i] = 2e9;
        called[i] = false;
    }
    rep(i,N){
        cin >> c[i];
        ip[c[i]] = min(ip[c[i]],(ll)i+1);
    }
    vector<ll> cnt(51,0LL);
    ll last[51];
    rep(i,51) last[i] = 0;
    //main
    segtree seq(N+1);
    rep(i,Q){
        ll t; cin >> t;
        if(!called[t]){
            cout << ip[t] + seq.sum(ip[t],N) << " ";
            seq.add(ip[t],1);
            
            rep(j,51){
                if(last[t]<last[j]){
                    cnt[j]++;
                }
            }
            last[t] = i+1;
            cnt[t] = 0;
            called[t] = true;
        }
        else{
            cout << cnt[t]+1 << " ";
            
            rep(j,51){
                if(last[t]<last[j]){
                    cnt[j]++;
                }
            }
            last[t] = i+1;
            cnt[t] = 0;
            called[t] = true;
        }
    }
    cout << endl;
}
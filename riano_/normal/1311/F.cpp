#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
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


//compression 
class compress {
public:
    map<ll,ll> label;
    vector<ll> inverse;
    set<ll> num;
    bool ready;
    compress(int a){
        num.insert(0);
        label[0] = 0;
        inverse.push_back(0);
        ready = false;
    }

    //x
    void add(ll x){
        num.insert(x); ready = false;
    }

    //sort
    void labeling(void){
        inverse.clear();
        int k = 0;
        for(ll x:num){
            inverse.push_back(x);
            label[x] = k; k++;
        }
    }

    //x
    ll lab(ll x){
        if(!ready){
            labeling(); ready = true;
        }
        return label[x];
    }

    //i
    ll inv(ll i){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse[i];
    }

    //size
    ll size(void){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse.size();
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

    //main
    //segtree seq(N);
    //  seq.replace(i,x);
    // 1-indexed !!!!!!

int main() {
    riano_; ll ans = 0;
    //main
    compress comp(1); //1
    //  comp.add(i,x);
    //
    ll N; cin >> N;
    ll x[N];
    vector<Tp> v;
    rep(i,N){
        cin >> x[i];
        comp.add(x[i]);
    }
    rep(i,N){
        ll u;
        cin >> u; v.push_back(make_tuple(u,x[i],i));
    }
    sort(v.begin(),v.end());
    segtree xs(N+2),cnt(N+2);
    rep(i,N){
        xs.add(comp.lab(x[i]),x[i]);
        cnt.add(i+1,1);
    }
    rep(i,N){
        ll k = get<2>(v[i]);
        ll s = comp.lab(x[k]);
        xs.replace(s,0);
        cnt.replace(s,0);
        ans += xs.sum(s+1,N+1)-x[k]*cnt.sum(s+1,N+1);
    }
    cout << ans << endl;
}
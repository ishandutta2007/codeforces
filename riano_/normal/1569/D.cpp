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
    riano_; //ll ans = 1;
    ll T; cin >> T;
    
    rep(ii,T){
        ll N,M,K; cin >> N >> M >> K;
        ll ans = 0;
        vector<vector<ll>> px(N,vector<ll>({}));
        vector<vector<ll>> py(M,vector<ll>({}));
        vector<ll> xs,ys;
        map<ll,ll> xl,yl;
        rep(i,N){
            ll x; cin >> x; xs.push_back(x);
            xl[x] = 0;
        }
        rep(i,M){
            ll x; cin >> x; ys.push_back(x);
            yl[x] = 0;
        }
        rep(i,K){
            ll x,y; cin >> x >> y;
            xl[x] = 0;
            yl[y] = 0;
            if(binary_search(xs.begin(),xs.end(),x)){
                if(binary_search(ys.begin(),ys.end(),y)){
                    continue;
                }
                else{
                    ll k = lower_bound(xs.begin(),xs.end(),x) - xs.begin();
                    px[k].push_back(y);
                }
            }
            else{
                ll k = lower_bound(ys.begin(),ys.end(),y) - ys.begin();
                py[k].push_back(x);
            }
        }
        ll id = 0;
        for(auto[s,t]:xl){
            xl[s] = id; id++;
        }
        id = 0;
        for(auto[s,t]:yl){
            yl[s] = id; id++;
        }

        //main
        segtree xp(xl.size()+1),yp(yl.size()+1);
        //  seq.replace(i,x);
        // 1-indexed !!!!!!


        vector<ll> pts;
        rep(i,N){
            for(ll y:px[i]){
                ll s = lower_bound(ys.begin(),ys.end(),y) - ys.begin();
                ll l = ys[s-1],r = ys[s];
                ans += (ll)yp.sum(yl[l],yl[r]);
            }
            for(ll y:px[i]){
                yp.add(yl[y],1LL);
            }
        }

        rep(i,M){
            for(ll x:py[i]){
                ll s = lower_bound(xs.begin(),xs.end(),x) - xs.begin();
                ll l = xs[s-1],r = xs[s];
                ans += (ll)xp.sum(xl[l],xl[r]);
            }
            for(ll x:py[i]){
                xp.add(xl[x],1LL);
            }
        }
        
        cout << ans << "\n";
    }
}
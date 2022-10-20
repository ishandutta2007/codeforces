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
#define Tp tuple<int,int,int>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)
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
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))


//ration operation stack
//
struct range_operaion_stack {
	vector<tuple<ll,ll,ll>> range;
	range_operaion_stack(ll start,ll size,ll inf) {
		range.push_back(make_tuple(inf,start,start));
	}

    ll add(ll i,ll x){
        int n = range.size() -1;
        ll k = get<0>(range[n]);
        ll i1 = i;
        while(k>=x){     //
            ll j1 = get<1>(range[n]);
            ll j2 = get<2>(range[n]);
            i1 = j1;
            range.pop_back();
            n = range.size() -1;
            k = get<0>(range[n]);
        }
        range.push_back(make_tuple(x,i1,i));
        return i1;
    }

    ll id(ll s){
        ll k = lower_bound(all(range),make_tuple(s,-1,-1))-range.begin();
        if(k==range.size()) return -1;
        return get<1>(range[k]);
    }
	
};
    

int main() {
    riano_; //string ans = "YES";
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N; ll ans = 0;
        ll a[N];
        rep(i,N) cin >> a[i];
        ll s[N+1]; s[0] = 0;
        vector<ll> ev,od;
        map<ll,vector<ll>> idx;
        ev.push_back(0);
        idx[0] = {0};
        rep(i,N){
            if((i+1)%2==0){
                s[i+1] = s[i]-a[i];
                ev.push_back(s[i+1]);
                if(idx.count(s[i+1])){
                    idx[s[i+1]].push_back(i+1);
                }
                else{
                    idx[s[i+1]] = {i+1};
                }
            }
            else{
                s[i+1] = s[i]+a[i];
                od.push_back(s[i+1]);
                if(idx.count(s[i+1])){
                    idx[s[i+1]].push_back(i+1);
                }
                else{
                    idx[s[i+1]] = {i+1};
                }
            }
        }
        //main 
        range_operaion_stack ran_ev(N+1,N+1,-2e18);
        range_operaion_stack ran_od(N+1,N+1,-2e18);
        for(int i=N;i>=0;i--){
            if(i%2==0){
                ll m1 = ran_ev.add(i,s[i]*(-1));
                ll m2 = ran_od.id(s[i]);
                //cout << m1 << " " << m2 << endl;
                chmin(m1,m2);
                
                ans += max(0LL,(ll)(lower_bound(all(idx[s[i]]),m1+2)-lower_bound(all(idx[s[i]]),i))-1);
            }
            else{
                ll m1 = ran_od.add(i,s[i]);
                ll m2 = ran_ev.id(s[i]*(-1));
                //cout << m1 << " " << m2 << endl;
                chmin(m1,m2);
                ans += max(0LL,(ll)(lower_bound(all(idx[s[i]]),m1+2)-lower_bound(all(idx[s[i]]),i))-1);
            }
        }
        cout << ans << "\n";
    }    
    
}
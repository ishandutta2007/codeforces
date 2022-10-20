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


//binary trie (dynamic segtree version)
class binary_trie {
public:
    ll n; ll len;
    vector<vector<int>> to;
    vector<int> content;
    vector<ll> count;
    vector<mint> sum;
    //vector<ll> lis;
    vector<int> emp = {-1,-1};
    binary_trie(ll k){
        n = 1;
        len = k;
        to.push_back(emp);
        content.push_back(0);
        count.push_back(0);
        sum.push_back(0);
    }

    ll size(void){
        return count[0];
    }

    //x true
    bool insert(ll x,ll cc = 1){
        bool ex = true;
        ll now = 0; count[now] += cc; sum[now] += mint(x*cc);
        for(int i=len-1;i>=0;i--){
            ll p = ((x&(1LL<<i))>>i);
            bool found = false;
            if(to[now][p]!=-1){
                found = true;
                now = to[now][p]; count[now] += cc; sum[now] += mint(x*cc);
            }
            if(found) continue;
            ex = false;
            to[now][p] = n;
            to.push_back(emp);
            content.push_back(p);
            count.push_back(cc);
            sum.push_back(mint(x*cc));
            now = n;
            n++;
        }
        return ex;
    }

    //k
    mint sum_under(ll k){
        if(k<0) return 0;
        insert(k,0);
        int now = 0; mint res = 0;
        for(int i=len-1;i>=0;i--){
            ll p = ((k&(1LL<<i))>>i);
            if(p==1&&to[now][0]!=-1){
                res += sum[to[now][0]];
            }
            now = to[now][p];
        }
        res += sum[now];
        return res;
    }

    //k
    ll count_under(ll k){
        if(k<0) return 0;
        insert(k,0);
        int now = 0; ll res = 0;
        for(int i=len-1;i>=0;i--){
            ll p = ((k&(1LL<<i))>>i);
            if(p==1&&to[now][0]!=-1){
                res += count[to[now][0]];
            }
            now = to[now][p];
        }
        res += count[now];
        return res;
    }

    //range count
    ll range_count(ll l,ll r){
        return count_under(r) - count_under(l-1);
    }

    //range sum
    mint range_sum(ll l,ll r){
        return sum_under(r) - sum_under(l-1);
    }

    //x+sum_under(x)>=k
    int binary_src(int k){
        if(count_under(0)>=k) return 0;
        int now = 0; int res = 0;
        int num = 0;
        for(int i=len-1;i>=0;i--){
            if(to[now][0]==-1){
                if(num+res+(1LL<<i)-1>=k){
                    return k-res;
                }
                else if(to[now][1]!=-1){
                    num += (1LL<<(i));
                    now = to[now][1];
                }
            }
            else{
                if(num+res+(1LL<<i)-1+count[to[now][0]]>=k){
                    now = to[now][0];
                }
                else{
                    if(to[now][1]!=-1){
                        res += count[to[now][0]];
                        num += (1LL<<(i));
                        now = to[now][1];
                    }
                    else{
                        return k-(res+count[to[now][0]]);
                    }
                }
            }
        }
        return num;
    }

};

binary_trie bt(32);

int main() {
    riano_; ll ans = 0;
    ll N; cin >> N;
    rep(i,N){
        ll T; cin >> T;
        ll l1 = bt.binary_src(T);
        ll l2 = bt.binary_src(T+1);
        // cout << "-----------" << endl;
        // cout << l1 << endl;
        // cout << l2 << endl;
        bt.insert(0,1);
        bt.insert(l1,-1);
        bt.insert(l2,-1);
        
        ll K; cin >> K;
        rep(j,K){
            ll x; cin >> x;
            x = (ans+x)%(ll)(1e9+1);
            ans = x+bt.count_under(x);
            cout << ans << "\n";
        }
    }
    //cout << ans << endl;
}
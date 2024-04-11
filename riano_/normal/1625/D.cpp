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
void out(vector<ll> &v){
    for(ll x:v) cout << x << " ";
    cout << endl; return;
}


//binary trie
class binary_trie {
public:
    ll n; ll len;
    vector<vector<int>> to;
    vector<int> content;
    vector<int> emp = {-1,-1};
    binary_trie(ll k){
        n = 1;
        len = k;
        to.push_back(emp);
        content.push_back(0);
    }

    //x true
    bool insert(ll x){
        bool ex = true;
        ll now = 0;
        for(int i=len-1;i>=0;i--){
            ll p = ((x&(1LL<<i))>>i);
            bool found = false;
            if(to[now][p]!=-1){
                found = true;
                now = to[now][p];
            }
            if(found) continue;
            ex = false;
            to[now][p] = n;
            to.push_back(emp);
            content.push_back(p);
            now = n;
            n++;
        }
        return ex;
    }

    ll match(ll x,ll k){
        //cout << x << " " << k << endl;
        ll res = -1; ll tmp = 0;
        ll now = 0; bool ok = false;
        for(int i=len-1;i>=0;i--){
            ll p = ((x&(1LL<<i))>>i);
            ll q = ((k&(1LL<<i))>>i);
            if(ok){
                if(to[now][0]!=-1){
                    now = to[now][0];
                    continue;
                }
                else{
                    now = to[now][1];
                    tmp += (1LL<<i);
                    continue;
                }
            }
            if(q==1){
                if(to[now][(1-p)]!=-1){
                    now = to[now][(1-p)];
                    tmp += (1-p)*(1LL<<i);
                    if(i==0) ok = true;
                    continue;
                }
                else{
                    break;
                }
            }
            else{
                if(to[now][(1-p)]!=-1){
                    now = to[now][(1-p)]; ok = true;
                    tmp += (1-p)*(1LL<<i);
                    continue;
                }
                else if(to[now][p]!=-1){
                    now = to[now][p];
                    tmp += (p)*(1LL<<i);
                    if(i==0) ok = true;
                    continue;
                }
                else{
                    break;
                }
            }
        }
        if(ok){
            res = tmp;
        }
        return res;
    }
};



int main() {
    riano_; //ll ans = 2e18;
    vector<ll> ans,ch;
    ll N,M,K,L; cin >> N >> K;
    
    map<ll,ll> idx;
    map<ll,set<ll>> a;
    M = 1;
    rep(i,32){
        if(M>=K) break;
        M *= 2LL;
    }
    rep(i,N){
        ll b; cin >> b; a[b/M].insert(b);
        //cout << b << " " << b/M << endl;
        idx[b] = i+1;
    }

    if(K==0){
        cout << N << endl;
        rep(i,N){
            cout << i+1 << " ";
        }
        cout << endl;
        return 0;
    }
    
    //cout << M << endl;
    for(auto[v,s]:a){
        //cout << v << endl;
        // if(s.size()==1||M==K){
        //     for(ll x:s){
        //         //cout << x << endl;
        //         ans.push_back(idx[x]);
        //         ch.push_back(x);
        //         break;
        //     }
        // }
        // else{
            bool match = false;
            binary_trie bt(31);
            for(ll x:s){
                //cout << x << endl;
                ll tmp = bt.match(x%M,K);
                if(tmp!=-1){
                    match = true;
                    ans.push_back(idx[v*M+tmp]);
                    ans.push_back(idx[x]);
                    ch.push_back(x);
                    ch.push_back(v*M+tmp);
                    break;
                }
                bt.insert(x%M);
            }
            if(!match){
                for(ll x:s){
                    ans.push_back(idx[x]);
                    ch.push_back(x);
                    break;
                }
            }
        // }
    }

    if(ans.size()<=1){
        cout << -1 << endl; return 0;
    }
    cout << ans.size() << endl;
    out(ans);
    //out(ch);
    //cout << ans << endl;
}
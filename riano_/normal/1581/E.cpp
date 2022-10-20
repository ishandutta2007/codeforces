#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;

const ll mod = 1000000007;
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

int main() {
    riano_; ll ans = 0;
    ll N,M; cin >> N >> M;
    int x[N+1],y[N+1];
    rep(i,N){
        cin >> x[i+1] >> y[i+1];
    }
    //train  in/out sqrt(M)
    int ch[N+1][2];
    rep(i,N+1){
        rep(j,2) ch[i][j] = 0;
    }
    ll s = 3*ceil(sqrt(M));

    //
    vector<vector<int>> sum;
    rep(i,s+1){
        sum.push_back(vector<int>(i+1,0));
    }
    //s
    vector<vector<ll>> op(M+1);
    //s remove 
    int inv[N+1];
    bool ment[N+1];
    bool app[s+1];
    rep(i,s+1) app[i] = false;
    rep(i,N+1) inv[i] = 0;
    rep(i,N+1) ment[i] = false;
    rep(i,M){
        ll now = i+1;
        ll t,k; cin >> t >> k;
        if(x[k]+y[k]<=s){
            ll m = x[k] + y[k];
            ll d = (i+1)%m;
            if(t==1){
                app[m] = true;
                ans++; //base  +1 
                sum[m][d]--; sum[m][(d+x[k])%m]++; // -1 
                ch[k][0] = d; ch[k][1] = (d+x[k])%m; //
            }
            else{
                sum[m][ch[k][0]]++; sum[m][ch[k][1]]--;
                bool in_op = false; //
                if(ch[k][0]<ch[k][1]){ //0 
                    if((ch[k][0]<d)&&(d<=ch[k][1])) in_op = true;
                }
                else{
                    in_op = true;
                    if((ch[k][1]<d)&&(d<=ch[k][0])) in_op = false;
                }
                if(!in_op){ //
                    ans--;
                }
            }
        }
        else{
            if(t==1){ // x  1 , inv 
                if(now+x[k]<=M) op[now+x[k]].push_back((k<<20)+inv[k]);
            }
            else{
                if(ment[k]){
                    ment[k] = false; ans--;
                }
                inv[k]++;
            }
        }
        rep(i2,s){
            if(!app[i2+1]) continue;
            ans += sum[i2+1][now%(i2+1)];
        }
        for(ll xx:op[now]){
            ll p = 1;
            if(xx<0){
                p = -1; xx *= -1;
            }
            ll k1 = (xx>>20); ll ii = xx-(k1<<20);
            // cout << now << endl;
            // cout << xx << " " << p << " " << k1 << " " << ii << endl;
            if(ii!=inv[k1]) continue;
            ans += p;
            if(p==1){
                ment[k1] = true;
                if(now+y[k1]<=M) op[now+y[k1]].push_back((-1)*((k1<<20)+ii));
            }
            else{
                ment[k1] = false;
                if(now+x[k1]<=M) op[now+x[k1]].push_back((k1<<20)+ii);
            }
        }
        cout << ans << "\n";
        
    }
    //cout << ans << endl;
}
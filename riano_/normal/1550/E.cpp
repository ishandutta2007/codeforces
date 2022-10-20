#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
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
    riano_; //mint ans = 0;
    ll N,K; cin >> N >> K;
    string S; cin >> S; S += "$";
    vector<Pr> s;
    s.push_back(make_pair(-1,(-2)*N));
    int con = 0; int pr = -1;
    int qm = '?'-'a';
    rep(i,N+1){
        int n = S[i]-'a';
        if(i!=0&&pr!=n){
            s.push_back(make_pair(pr,con)); con = 0;
        }
        pr = n; con++;
    }
    s.push_back(make_pair(-1,(-2)*N));

    // binary search
    //"r"
    ll l,r,ans;
    l = 0; r = N+1; //
    while(l<r){
        ll c = (l+r)/2;
        //cout << c << endl;
        //c
        ll nx[K][N];
        rep(i,K){
            char ch = 'a'+i;
            int k = 0;
            rep(j,N){
                if(j==0){
                    int cc = 0;
                    while(cc<c){
                        cc++; k++;
                        if(k>N) break;
                        if(S[k-1]!=ch&&S[k-1]!='?'){
                            cc = 0;
                        }
                    }
                    nx[i][0] = k;
                }
                else{
                    int cc = c;
                    if(k-cc<j){
                        cc--;
                    }
                    while(cc<c){
                        if(k>N) break;
                        cc++; k++;
                        if(k>N) break;
                        if(S[k-1]!=ch&&S[k-1]!='?'){
                            cc = 0;
                        }
                    }
                    nx[i][j] = k;
                }
            }
        }

        // if(c<=10){
        //     rep(i,K){
        //         rep(j,N){
        //             cout << nx[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        //bitDP  n(bit)
        int n = K; //
        long long dp[(1<<n)];
        long long inf = N+1;
        for(int tmp=0;tmp<(1<<n);tmp++){
            dp[tmp]=inf;
        }
        dp[0]=0;  //
  
        for(int tmp=0;tmp<(1<<n);tmp++){
            for(int i=0;i<n;i++){
                if(tmp&(1<<i)){
                    int bit = (tmp^(1<<i));
                    if(dp[bit]>=N) continue;
                    // if(c==3){
                    //     cout << tmp << " " << bit << " " << dp[tmp] << endl;
                    //     cout << dp[bit] << " " << nx[i][dp[bit]] << endl;
                    // }
                    dp[tmp] = min(dp[tmp],nx[i][dp[bit]]);
                    // if(c==3){
                    //     cout << tmp << " " << bit << " " << dp[tmp] << endl;
                    // }
                }
            }   
        }

        // if(c==3){
        //     rep(tmp,(1<<n)){
        //         cout << dp[tmp] << endl;
        //     }
        // }
        if(dp[(1<<n)-1]<inf){//c"l"
            l = c+1;
        }
        else r = c;
    }
    ans = l-1;
    cout << ans << endl;
}
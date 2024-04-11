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
using Graph = vector<vector<Pr>>;

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

int main() {
    riano_; //ll ans = 0;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        auto ans = vll(N+1,-1);
        ll b = -1,w = -1;
        vector<ll> maj(N/3);
        rep(i,N/3){
            cout << "?" << " " << 3*i+1 << " " << 3*i+2 << " " << 3*i+3 << endl;
            ll a; cin >> a;
            maj[i] = 1-a;
            if(a==0) b = i;
            else w = i;
        }
        ll fb = -1,fw = -1;
        vector<pair<int,int>> p = {make_pair(1,2),make_pair(1,3),make_pair(2,3)};
        if(b>=0&&w>=0){
            auto lab = v2ll(3,3,0);
            
            rep(i,3){
                rep(j,3){
                    cout << "?" << " " << 3*b+p[i].first << " " << 3*b+p[i].second << " " << 3*w+(j+1) << endl;
                    cin >> lab[i][j];
                }
                if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==0){
                    ans[3*b+p[i].first] = 1; ans[3*b+p[i].second] = 1; fb = 3*b+p[i].first;
                    break;
                }
                else if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==1){
                    rep(j,3){
                        ans[3*w+(j+1)] = 0; fw = 3*w+(j+1);
                    }
                    rep(j,3){
                        cout << "?" << " " << 3*b+p[j].first << " " << 3*b+p[j].second << " " << 3*w+1 << endl;
                        ll bb; cin >> bb;
                        if(bb==0){
                            ans[3*b+p[j].first] = 1; ans[3*b+p[j].second] = 1; fb = 3*b+p[j].second;
                        }
                    }
                    break;
                }
                else{
                    rep(j,3){
                        if(lab[i][j]==0){
                            ans[3*w+(j+1)] = 1; fb = 3*w+(j+1);
                        }
                        else{
                            ans[3*w+(j+1)] = 0; fw = 3*w+(j+1);
                        }
                    }
                    break;
                }
            }
            if(fw==-1){
                rep(j,3){
                    cout << "?" << " " << 3*w+p[j].first << " " << 3*w+p[j].second << " " << fb << endl;
                    cin >> lab[1][j];
                    if(lab[1][j]==1){
                        ans[3*w+p[j].first] = 0; ans[3*w+p[j].second] = 0; fw = 3*w+p[j].first;
                        break;
                    }
                }
            }
        }
        else if(w>=0){
            b = 0;
            if(w==0) b = 1;
            auto lab = v2ll(3,3,0);
            rep(i,3){
                rep(j,3){
                    cout << "?" << " " << 3*b+p[i].first << " " << 3*b+p[i].second << " " << 3*w+(j+1) << endl;
                    cin >> lab[i][j];
                }
                if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==0){
                }
                else if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==1){
                }
                else{
                    rep(j,3){
                        if(lab[i][j]==0){
                            ans[3*w+(j+1)] = 1; fb = 3*w+(j+1);
                        }
                        else{
                            ans[3*w+(j+1)] = 0; fw = 3*w+(j+1);
                        }
                    }
                    break;
                }
            }
        }
        else{
            w = 0;
            if(b==0) w = 1;
            auto lab = v2ll(3,3,0);
            rep(i,3){
                rep(j,3){
                    cout << "?" << " " << 3*b+p[i].first << " " << 3*b+p[i].second << " " << 3*w+(j+1) << endl;
                    cin >> lab[i][j];
                }
                if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==0){
                }
                else if(lab[i][0]==lab[i][1]&&lab[i][1]==lab[i][2]&&lab[i][0]==1){
                }
                else{
                    rep(j,3){
                        if(lab[i][j]==0){
                            ans[3*w+(j+1)] = 1; fb = 3*w+(j+1);
                        }
                        else{
                            ans[3*w+(j+1)] = 0; fw = 3*w+(j+1);
                        }
                    }
                    break;
                }
            }
        }
        ll cnt = 0;
        // rep(i,N){
        //     cout << ans[i+1] << endl;
        // }
        // cout << fw << " " << fb << endl;
        rep(i,N/3){
            // if(ans[i+1]!=-1){
            //     if(ans[i+1]==1) cnt++;
            //     continue;
            // }
            // cout << "?" << " " << fw << " " << fb << " " << i+1 << endl;
            // ll aa; cin >> aa;
            // ans[i+1] = 1-aa;
            // if(ans[i+1]==1) cnt++;
            if(ans[3*i+1]!=-1||ans[3*i+2]!=-1||ans[3*i+3]!=-1){
                rep(j,3){
                    if(ans[3*i+j+1]!=-1) continue;
                    cout << "?" << " " << fw << " " << fb << " " << 3*i+j+1 << endl;
                    ll rr; cin >> rr;
                    ans[3*i+j+1] = 1-rr;
                }
                continue;
            }
            ll r;
            if(maj[i]==0){
                cout << "? " << 3*i+1 << " " << 3*i+2 << " " << fb << endl;
                cin >> r;
                if(r==1){
                    ans[3*i+1] = 0; ans[3*i+2] = 0;
                    cout << "? " << 3*i+3 << " " << fw << " " << fb << endl;
                    cin >> r;
                    ans[3*i+3] = 1-r;
                }
                else{
                    cout << "? " << 3*i+3 << " " << 3*i+2 << " " << fb << endl;
                    cin >> r;
                    if(r==0){
                        ans[3*i+1] = 0; ans[3*i+2] = 1; ans[3*i+3] = 0;
                    }
                    else{
                        ans[3*i+1] = 1; ans[3*i+2] = 0; ans[3*i+3] = 0;
                    }
                }
            }
            else{
                cout << "? " << 3*i+1 << " " << 3*i+2 << " " << fw << endl;
                cin >> r;
                if(r==0){
                    ans[3*i+1] = 1; ans[3*i+2] = 1;
                    cout << "? " << 3*i+3 << " " << fw << " " << fb << endl;
                    cin >> r;
                    ans[3*i+3] = 1-r;
                }
                else{
                    cout << "? " << 3*i+3 << " " << 3*i+2 << " " << fw << endl;
                    cin >> r;
                    if(r==1){
                        ans[3*i+1] = 1; ans[3*i+2] = 0; ans[3*i+3] = 1;
                    }
                    else{
                        ans[3*i+1] = 0; ans[3*i+2] = 1; ans[3*i+3] = 1;
                    }
                }
            }
        }
        rep(i,N){
            if(ans[i+1]==1) cnt++;
        }
        cout << "! " << cnt << " ";
        rep(i,N){
            if(ans[i+1]==1){
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }    
    //cout << ans << endl;
}
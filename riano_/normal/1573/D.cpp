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
    riano_; //ll ans = 2e9;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        string S;
        ll cc = 0;
        rep(i,N){
            char c; cin >> c; S += c;
            if(c=='1'){
                cc++;
            }
        }
        if(cc%2==1){
            cout << "NO" << "\n"; continue;
        }
        //runlength compress
        vector<Pr> s;
        S += "$";
        int con = 0; int pr = -1;
        rep(i,N+1){
            int n = S[i]-'0';
            if(i!=0&&pr!=n){
                s.push_back(make_pair(pr,con)); con = 0;
            }
            pr = n; con++;
        }
        if(s.size()==1){
            if(s[0].first==1){
                cout << "NO" << "\n"; continue;
            }
            else{
                cout << "YES" << "\n"; 
                cout << 0 << "\n";
                continue;
            }
        }
        bool cl = true; int id = 0;
        int os = 0,ones = 0;
        vector<ll> ans;
        bool ok = true;
        rep(i,s.size()){
            if(cl&&s[i].first==0){
                id += s[i].second; os = id;
                continue;
            }
            if(!cl&&s[i].first==0){
                ll sz = s[i].second;
                if(sz%2==1){
                    rep(i,sz/2+1){
                        ans.push_back(id-1+2*i);
                    }
                    rep(i,sz/2){
                        ans.push_back(id+sz-4-2*i);
                    }
                    for(int j=id-3;j>=os;j-=2){
                        ans.push_back(j);
                    }
                    auto[p,q] = s[i+1];
                    s[i+1] = make_pair(p,q-1);
                    id += 1; os = id+sz; ones = 0; cl = true;
                }
                else{
                    rep(i,sz/2){
                        ans.push_back(id-1+2*i);
                    }
                }
                id += sz;
            }
            if(s[i].first==1){
                ones += s[i].second; id += s[i].second;
                if(ones%2==0){
                    //cout << os << " " << id << "\n";
                    if(os!=0){
                        for(int j=os-1;j<=id-3;j+=2){
                            ans.push_back(j);
                        }
                    }
                    else if(id!=N){
                        for(int j=id-2;j>=os;j-=2){
                            ans.push_back(j);
                        }
                    }
                    else{
                        ok = false;
                    }
                    cl = true; ones = 0;
                }
                else{
                    if(cl){
                        os = id-s[i].second;
                    }
                    cl = false; 
                }
            }
        }
        if(!ok){
            cout << "NO" << "\n"; continue;
        }
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        rep(i,ans.size()){
            cout << ans[i]+1 << " ";
        }
        cout << "\n";
    }
    //cout << ans << endl;
}
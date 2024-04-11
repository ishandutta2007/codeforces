#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr uint32_t mod = 998244353;
struct Modint{
    uint32_t num = 0;
    constexpr Modint() noexcept {}
    constexpr Modint(const Modint &x) noexcept : num(x.num){}
    constexpr operator ll() const noexcept { return num; }
    constexpr Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    constexpr Modint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    constexpr Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    constexpr Modint operator-() const noexcept { return Modint(0) -= *this; }
    constexpr Modint& operator-=(Modint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    constexpr Modint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    constexpr Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    constexpr Modint& operator*=(Modint x) noexcept { num = uint64_t(num) * x.num % mod; return *this; }
    constexpr Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = uint32_t(y);
    }
    template<class T> constexpr Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> constexpr Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> constexpr Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> constexpr Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> constexpr Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> constexpr Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> constexpr Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> constexpr Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    constexpr Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    constexpr Modint pow(uint64_t x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::vector<Modint> fac(1, 1), inv(1, 1);
void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= mod) a = mod;
    while(fac.size() < a) fac.push_back(fac.back() * Modint(fac.size()));
    inv.resize(fac.size());
    inv.back() = fac.back().inv();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
Modint perm(ll n, ll r){
    if(r < 0 || n < r) return 0;
    if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
    reserve(n + 1); return fac[n] * inv[n - r];
}
Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; r = min(r, n - r); reserve(r + 1); return perm(n, r) * inv[r]; }
Modint Mcomb(ll n, ll r){ return comb(n + r - 1, r); } // r balls into n boxes
Modint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> D(N);
    for(ll& d : D) cin >> d;
    D.insert(D.begin(), 0);
    for(ll i = 0; i < N; i++) D[i + 1] += D[i];
    const ll R = D[N];
    for(ll& d : D) d *= 2;
    ll one = N, two = 0;
    unordered_set s(D.begin(), D.end());
    for(ll d : D) if(d < R && s.count(d + R)){
        two++;
        one -= 2;
    }
    Modint ans = 0;
    for(ll k = 0; k <= two; k++){
        if(k > M) break;
        const ll c = M - k;
        ans += comb(two, k) * perm(M, k) * perm(c, 2).pow(two - k) * Modint{c}.pow(one);
    }
    cout << ans << endl;
}
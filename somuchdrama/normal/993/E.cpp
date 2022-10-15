//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;
#define ff first
#define ss second
#define pb emplace_back
template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}
template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#endif
}}init;
const int MAXLOG = 19;
const int MAXN = 1 << MAXLOG;
const int BLEN = 4;
const int BASE = 1e4;

struct cpx {
    double x, y;
    cpx() { }
    cpx(double angle) : x(cos(angle)), y(sin(angle)) { }
    cpx(double _x_, double _y_) : x(_x_), y(_y_) { }
    cpx operator * (double k)     const { return cpx(x * k, y * k); }
    cpx operator + (const cpx &a) const { return cpx(x + a.x, y + a.y); }
    cpx operator - (const cpx &a) const { return cpx(x - a.x, y - a.y); }
    cpx operator * (const cpx &a) const { return cpx(x * a.x - y * a.y, x * a.y + y * a.x); }
    cpx conj() { return cpx(x, -y); }
};
ll r[MAXN];
cpx fft_from[MAXN], fft_to[MAXN], root[MAXN];
int rev[MAXN];
ll fft_res[MAXN];
struct fft_init{
    fft_init() {
        for (int i = 0; i < MAXN; ++i)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (MAXLOG - 1));
        for (int k = 1; k < MAXN; k *= 2) {
            cpx tmp(3.1415926535897932384626433 / k);
            root[k] = {1, 0};
            for (int i = 1; i < k; i++)
                root[k + i] = (i & 1) ? root[(k + i) >> 1] * tmp : root[(k + i) >> 1];
        }        
    }
} fft_init;

void fft(const cpx *a, cpx *res) {
    for (int i = 0; i < MAXN; ++i)
        res[rev[i]] = a[i];
    for (int k = 1; k < MAXN; k *= 2)
        for (int i = 0; i < MAXN; i += 2 * k)
            for (int j = 0; j < k; ++j) {
                cpx tmp = root[k + j] * res[i + j + k];
                res[i + j + k] = res[i + j] - tmp;
                res[i + j] = res[i + j] + tmp;
            }
}

ll ans[MAXN];
int32_t main() {

    int n, x;
    cin >> n >> x;
    int s = 0, c = 1;
    for (int i = 1; i <= n; ++i) {
        int y;
        cin >> y;
        if (y < x) {
            r[s++] = c;
            c = 1;
        } else {
            c++;
        }
    }

    r[s++] = c;

    for (int i = 0; i < s; ++i)
        ans[0] += (r[i] * (r[i] - 1)) / 2;
    cout << ans[0] << ' ';

    for (int i = 0; i < s; ++i) {
        fft_from[i].x = r[i];
        fft_from[i].y = r[s - i - 1];
        // dbg(fft_from[i].x, fft_from[i].y);
    }

    fft(fft_from, fft_to);
    for (int i = 0; i <= MAXN / 2; ++i) {
        int j = i ? MAXN - i : 0;
        cpx z0 = fft_to[i], z1 = fft_to[j];
        fft_to[i] = cpx(z0.x + z1.x, z0.y - z1.y) * cpx(z0.y + z1.y, z1.x - z0.x) * 0.25;
        fft_to[j] = fft_to[i].conj();
    }
    fft(fft_to, fft_from);
    for (int i = 0; i < MAXN; ++i)  {
        // dbg(fft_from[i].x);
        fft_from[i].x /= MAXN;
    }
    std::reverse(fft_from + 1, fft_from + MAXN);

    for (int i = 0; i + 1 < s; ++i) {
        // dbg(i, fft_from[i + s].x);
        cout << ((ll)(fft_from[i + s].x + 0.5)) << ' ';
    }

    for (int i = s + 1; i <= n + 1; ++i)
        cout << "0 ";
    cout << '\n';

    return 0;
}
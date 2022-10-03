#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=55;
const ll INF=1LL<<40;

// https://nyaannyaan.github.io/library/ntt/complex-fft.hpp

#pragma once

namespace ArbitraryModConvolution {
    
    template <typename T>
    struct Cp {
        T x, y;
        constexpr Cp() : x(0), y(0) {}
        constexpr Cp(T _x, T _y) : x(_x), y(_y) {}
        constexpr inline Cp operator+(const Cp& c) const {
            return Cp(x + c.x, y + c.y);
        }
        constexpr inline Cp operator-(const Cp& c) const {
            return Cp(x - c.x, y - c.y);
        }
        constexpr inline Cp operator*(const Cp& c) const {
            return Cp(x * c.x - y * c.y, x * c.y + y * c.x);
        }
        constexpr inline Cp operator-() const { return Cp(-x, -y); }
        constexpr inline Cp conj() const { return Cp(x, -y); }
        constexpr inline Cp rotl() const { return Cp(-y, x); }
        friend ostream& operator<<(ostream& os, const Cp& c) {
            os << "(" << c.x << ", " << c.y << ")" << endl;
            return os;
        }
    };
    
    using C = Cp<long double>;
    const long double PI = acosl(-1);
    
    struct CooleyTukey {
        static vector<C> w;
        
        static void setw(int k) {
            --k;
            if ((int)w.size() >= (1 << k)) return;
            w.resize(1 << k);
            vector<Cp<long double>> base(k);
            const long double arg = PI / (1 << k);
            for (int i = 0, j = 1 << (k - 1); j; i++, j >>= 1) {
                complex<long double> z = exp(complex<long double>(1i) * (arg * j));
                base[i] = Cp<long double>{z.real(), z.imag()};
            }
            genw(0, k - 1, Cp<long double>{1, 0}, base);
        }
        
        static void genw(int i, int b, Cp<long double> z,
                         const vector<Cp<long double>>& base) {
            if (b == -1) {
                w[i].x = z.x, w[i].y = z.y;
            } else {
                genw(i, b - 1, z, base);
                genw(i | (1 << b), b - 1, z * base[b], base);
            }
        }
        
        static void fft(vector<C>& a, int k) {
            if (k <= 0) return;
            if (k == 1) {
                C a1 = a[1];
                a[1] = a[0] - a[1];
                a[0] = a[0] + a1;
                return;
            }
            if (k & 1) {
                int v = 1 << (k - 1);
                for (int j = 0; j < v; ++j) {
                    C ajv = a[j + v];
                    a[j + v] = a[j] - ajv;
                    a[j] = a[j] + ajv;
                }
            }
            int u = 1 << (k & 1), v = 1 << (k - 2 - (k & 1));
            while (v) {
                {
                    int j0 = 0;
                    int j1 = v;
                    int j2 = j1 + v;
                    int j3 = j2 + v;
                    int je = v;
                    for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
                        C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
                        C t0p2 = t0 + t2, t1p3 = t1 + t3;
                        C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
                        a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
                        a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
                    }
                }
                // jh >= 1
                for (int jh = 1; jh < u; ++jh) {
                    int j0 = jh * v * 4;
                    int j1 = j0 + v;
                    int j2 = j1 + v;
                    int j3 = j2 + v;
                    int je = j1;
                    C ww = w[jh];
                    C xx = w[jh << 1];
                    C wx = ww * xx;
                    for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
                        C t0 = a[j0], t1 = a[j1] * xx, t2 = a[j2] * ww, t3 = a[j3] * wx;
                        C t0p2 = t0 + t2, t1p3 = t1 + t3;
                        C t0m2 = t0 - t2, t1m3 = (t1 - t3) * w[1];
                        a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
                        a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
                    }
                }
                u <<= 2, v >>= 2;
            }
        }
        
        static void ifft(vector<C>& a, int k) {
            if ((int)a.size() <= 1) return;
            if (k == 1) {
                C a1 = a[1];
                a[1] = a[0] - a[1];
                a[0] = a[0] + a1;
                return;
            }
            int u = 1 << (k - 2);
            int v = 1;
            while (u) {
                // jh = 0
                {
                    int j0 = 0;
                    int j1 = v;
                    int j2 = j1 + v;
                    int j3 = j2 + v;
                    for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
                        C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
                        C t0p1 = t0 + t1, t2p3 = t2 + t3;
                        C t0m1 = t0 - t1, t2m3 = (t2 - t3) * w[1].conj();
                        a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
                        a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
                    }
                }
                // jh >= 1
                for (int jh = 1; jh < u; ++jh) {
                    int j0 = (jh * v) << 2;
                    int j1 = j0 + v;
                    int j2 = j1 + v;
                    int j3 = j2 + v;
                    int je = j1;
                    C ww = w[jh].conj();
                    C xx = w[jh << 1].conj();
                    C yy = w[(jh << 1) + 1].conj();
                    for (; j0 < je; ++j0, ++j1, ++j2, ++j3) {
                        C t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
                        C t0p1 = t0 + t1, t2p3 = t2 + t3;
                        C t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
                        a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
                        a[j1] = t0m1 + t2m3, a[j3] = (t0m1 - t2m3) * ww;
                    }
                }
                u >>= 2;
                v <<= 2;
            }
            if (k & 1) {
                u = 1 << (k - 1);
                for (int j = 0; j < u; j++) {
                    C ajv = a[j] - a[j + u];
                    a[j] = a[j] + a[j + u];
                    a[j + u] = ajv;
                }
            }
        }
        
        static void fft_real(vector<C>& AL, vector<C>& AH, int k) {
            fft(AL, k);
            AH[0] = C{AL[0].y * 2.0, 0};
            AL[0] = C{AL[0].x * 2.0, 0};
            AH[1] = C{AL[1].y * 2.0, 0};
            AL[1] = C{AL[1].x * 2.0, 0};
            for (int i = 2, y = 2; y < (1 << k); y <<= 1) {
                for (; i < 2 * y; i += 2) {
                    int j = i ^ (y - 1);
                    AH[i] = (AL[j].conj() - AL[i]).rotl();
                    AL[i] = (AL[j].conj() + AL[i]);
                    AH[j] = AH[i].conj();
                    AL[j] = AL[i].conj();
                }
            }
        }
        
        // naive convolution for int
        template <typename T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr>
        static vector<long long> multiply(const vector<T>& s, const vector<T>& t) {
            int l = s.size() + t.size() - 1;
            if (min(s.size(), t.size()) <= 40) {
                vector<long long> u(l);
                for (int i = 0; i < (int)s.size(); i++) {
                    for (int j = 0; j < (int)t.size(); j++) u[i + j] += 1LL * s[i] * t[j];
                }
                return u;
            }
            
            int k = 2, M = 4;
            while (M < l) M <<= 1, ++k;
            setw(k);
            auto round = [](double x) -> long long {
                return (long long)(x + (x > 0 ? 0.5 : -0.5));
            };
            
            vector<C> a(M);
            for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];
            for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];
            fft(a, k);
            
            a[0].y = 4.0 * a[0].x * a[0].y;
            a[1].y = 4.0 * a[1].x * a[1].y;
            a[0].x = a[1].x = 0.0;
            for (int i = 2; i < M; i += 2) {
                int c = 1 << (31 - __builtin_clz(i));
                int j = i ^ (c - 1);
                a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());
                a[j] = -a[i].conj();
            }
            
            vector<C> b(M / 2);
            for (int j = 0; j < M / 2; j++) {
                C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];
                C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();
                b[j] = tmp1 + tmp2.rotl();
            }
            ifft(b, k - 1);
            
            vector<long long> u(l);
            for (int i = 0; i < l; i++) {
                if (i & 1) {
                    u[i] = round(-b[i >> 1].x / (4.0 * M));
                } else {
                    u[i] = round(b[i >> 1].y / (4.0 * M));
                }
            }
            return u;
        }
        
        static vector<long double> multiply(const vector<long double>& s,
                                       const vector<long double>& t) {
            int l = s.size() + t.size() - 1;
            if (min(s.size(), t.size()) <= 40) {
                vector<long double> u(l);
                for (int i = 0; i < (int)s.size(); i++) {
                    for (int j = 0; j < (int)t.size(); j++) u[i + j] += s[i] * t[j];
                }
                return u;
            }
            
            int k = 2, M = 4;
            while (M < l) M <<= 1, ++k;
            setw(k);
            
            vector<C> a(M);
            for (int i = 0; i < (int)s.size(); i++) a[i].x = s[i];
            for (int i = 0; i < (int)t.size(); i++) a[i].y = t[i];
            fft(a, k);
            
            a[0].y = 4.0 * a[0].x * a[0].y;
            a[1].y = 4.0 * a[1].x * a[1].y;
            a[0].x = a[1].x = 0.0;
            for (int i = 2; i < M; i += 2) {
                int c = 1 << (31 - __builtin_clz(i));
                int j = i ^ (c - 1);
                a[i] = (a[i] + a[j].conj()) * (a[i] - a[j].conj());
                a[j] = -a[i].conj();
            }
            
            vector<C> b(M / 2);
            for (int j = 0; j < M / 2; j++) {
                C tmp1 = a[j * 2 + 0] + a[j * 2 + 1];
                C tmp2 = (a[j * 2 + 0] - a[j * 2 + 1]) * w[j].conj();
                b[j] = tmp1 + tmp2.rotl();
            }
            ifft(b, k - 1);
            
            vector<long double> u(l);
            for (int i = 0; i < l; i++) {
                if (i & 1) {
                    u[i] = -b[i >> 1].x / (4.0 * M);
                } else {
                    u[i] = b[i >> 1].y / (4.0 * M);
                }
            }
            return u;
        }
        
        template <unsigned int MOD>
        static vector<int> multiply_15bit(const vector<int>& a,
                                          const vector<int>& b) {
            using u64 = unsigned long long;
            constexpr u64 B = 32000;
            int l = a.size() + b.size() - 1;
            int k = 2, M = 4;
            while (M < l) M <<= 1, ++k;
            setw(k);
            auto round = [](double x) -> u64 { return u64(x + 0.5); };
            
            vector<C> AL(M), AH(M), BL(M), BH(M);
            for (int i = 0; i < (int)a.size(); i++) {
                AL[i] = C{double(a[i] % B), double(a[i] / B)};
            }
            for (int i = 0; i < (int)b.size(); i++) {
                BL[i] = C{double(b[i] % B), double(b[i] / B)};
            }
            
            fft_real(AL, AH, k);
            fft_real(BL, BH, k);
            
            for (int i = 0; i < M; i++) {
                C tmp = AL[i] * BL[i] + (AH[i] * BH[i]).rotl();
                BH[i] = AL[i] * BH[i] + (AH[i] * BL[i]).rotl();
                BL[i] = tmp;
            }
            
            ifft(BL, k);
            ifft(BH, k);
            
            vector<int> u(l);
            double im = 1.0 / (4.0 * M);
            for (int i = 0; i < l; i++) {
                BL[i].x *= im, BL[i].y *= im;
                BH[i].x *= im, BH[i].y *= im;
                int x1 = u64(round(BL[i].x)) % MOD;
                int x2 = u64(round(BH[i].x) + round(BH[i].y)) % MOD * B % MOD;
                int x3 = u64(round(BL[i].y)) % MOD * (B * B % MOD) % MOD;
                if ((x1 += x2) >= (int)MOD) x1 -= MOD;
                if ((x1 += x3) >= (int)MOD) x1 -= MOD;
                u[i] = x1;
            }
            return u;
        }
    };
    vector<C> CooleyTukey::w;
    
}  // namespace ArbitraryModConvolution

//#define double long double

int N,M,T,X;

vector<pair<pair<int,int>,pair<int,vector<long double>>>> G[MAX];

pair<int,int> E[105];
long double pre[105][80005];
long double dp[MAX][80005];

void solve(int l,int r){
    if(l+1==r){
        if(l>=T) return;
        for(int j=0;j<N;j++) dp[j][l]=INF;
        for(int j=0;j<M;j++){
            chmin(dp[E[j].fi][l],pre[j][l]+E[j].se);
        }
        dp[N-1][l]=0;
        return;
    }
    int m=(l+r)/2;
    solve(m,r);
    
    for(int j=0;j<N;j++){
        for(auto &to:G[j]){
            
            vector<long double> A(r-m);
            for(int i=0;i<r-m;i++) A[i]=dp[to.fi.fi][m+i];
            int L=min(si(to.se.se),r-l+1);
            vector<long double> B(L);
            for(int i=0;i<L;i++) B[L-1-i]=to.se.se[i];
            vector<long double> C=ArbitraryModConvolution::CooleyTukey::multiply(A,B);
            
            for(int i=l;i<min(T,m);i++){
                if(L-1-(m-i)<si(C)&&0<=L-1-(m-i)) pre[to.fi.se][i]+=C[L-1-(m-i)];
            }
        }
    }
    
    solve(l,m);
}

ll dis[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>T>>X;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) dis[i][j]=INF;
        dis[i][i]=0;
    }
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        E[i]=mp(a,c);
        vector<long double> co(T+1);
        for(int j=1;j<=T;j++){
            int x;cin>>x;
            co[j]=(double)(x)/100000;
        }
        chmin(dis[a][b],(ll)c);
        G[a].push_back(mp(mp(b,i),mp(c,co)));
    }
    for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++) chmin(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=0;i<M;i++){
        for(int j=T;j<=3*T+2;j++) pre[i][j]=dis[E[i].fi][N-1]+X;
    }
    for(int i=0;i<N;i++){
        for(int j=T;j<=3*T+2;j++) dp[i][j]=dis[i][N-1]+X;
    }
    dp[N-1][T]=0;
    
    solve(0,2*T);
    
    cout<<fixed<<setprecision(25)<<dp[0][0]<<endl;
}
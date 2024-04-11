#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const double PI = acos(-1);
const long long MAXN = (1 << 21);

struct complex_base
{
    double x, y;
    complex_base(double _x = 0, double _y = 0) { x = _x; y = _y; }
    friend complex_base operator-(const complex_base &a, const complex_base &b) { return complex_base(a.x - b.x, a.y - b.y); }
    friend complex_base operator+(const complex_base &a, const complex_base &b) { return complex_base(a.x + b.x, a.y + b.y); }
    friend complex_base operator*(const complex_base &a, const complex_base &b) { return complex_base(a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x); }
    friend void operator/=(complex_base &a, const double &P) { a.x /= P; a.y /= P; }
};

long long bit_rev[MAXN];

void fft(complex_base *a, long long lg)
{
    long long n = (1 << lg);
    for(long long i = 1; i < n; i++)
    {
        bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
        if(bit_rev[i] < i) swap(a[i], a[bit_rev[i]]);
    }

    for(long long len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len;
        complex_base w(1, 0), wn(cos(ang), sin(ang));
        for(long long j = 0; j < (len >> 1); j++, w = w * wn)
            for(long long i = 0; i < n; i += len)
            {
                complex_base u = a[i + j], v = w * a[i + j + (len >> 1)];
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
            }
    }
}

void inv_fft(complex_base *a, long long lg)
{
    long long n = (1 << lg);
    for(long long i = 1; i < n; i++)
    {
        bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
        if(bit_rev[i] < i) swap(a[i], a[bit_rev[i]]);
    }

    for(long long len = 2; len <= n; len <<= 1)
    {
        double ang = -2 * PI / len;
        complex_base w(1, 0), wn(cos(ang), sin(ang));

        for(long long j = 0; j < (len >> 1); j++, w = w * wn)
            for(long long i = 0; i < n; i += len)
            {
                complex_base u = a[i + j], v = w * a[i + j + (len >> 1)];
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
            }
    }

    for(long long i = 0; i < n; i++)
        a[i] /= n;
}

complex_base A[MAXN], B[MAXN];

vector<long long> mult(vector<long long> a, vector<long long> b)
{
    if(a.size() * b.size() <= 256)
    {
        vector<long long> ans(a.size() + b.size(), 0);
        for(long long i = 0; i < (long long)a.size(); i++)
            for(long long j = 0; j < (long long)b.size(); j++)
                ans[i + j] += a[i] * b[j];

        return ans;
    }

    long long lg = 0; while((1 << lg) < (a.size() + b.size())) ++lg;
    for(long long i = 0; i < (1 << lg); i++) A[i] = B[i] = complex_base(0, 0);
    for(long long i = 0; i < (long long)a.size(); i++) A[i] = complex_base(a[i], 0);
    for(long long i = 0; i < (long long)b.size(); i++) B[i] = complex_base(b[i], 0);

    fft(A, lg); fft(B, lg);
    for(long long i = 0; i < (1 << lg); i++)
        A[i] = A[i] * B[i];
    inv_fft(A, lg);

    vector<long long> ans(a.size() + b.size(), 0);
    for(long long i = 0; i < (long long)ans.size(); i++)
        ans[i] = (long long)(A[i].x + 0.5);

    return ans;
}
long long aa[400009],s[400009],x[400009];
vector<long long> A1,B1,res;
main(){
    long long n,x;
    cin>>n >> x;
    for(long long i = 0; i <= n; i++)
        A1.push_back(0),B1.push_back(0);
    A1[0] ++;
    for(long long i = 1; i <= n; i++){
        cin>>aa[i];
        if(aa[i] < x) aa[i] = 1;
        else aa[i] = 0;
        s[i] = s[i-1]+aa[i];
        A1[s[i]] ++;

    }
    for(long long i = 0; i <= n; i++){
    B1[n-s[i]]++;
    }
   res = mult(A1,B1);
    long long S = 0;
    for(long long i = 1; i <= n; i++){
        S += res[n + i];
    }
    res[n] = n * (n + 1)/ 2  - S;
    for(long long i =0; i <=n; i++)
        cout <<res[i+n] << " ";
    cout<<endl;

}
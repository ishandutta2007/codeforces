//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979


typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int BASE = 1000;
const double EPS = 1e-7;
const int MAX = 1500007;

typedef complex<double> base;
const int LEN = 1<<20; // max length, power of 2
base PW[LEN]; // LEN-th roots of -1
void fft(vector<base>& a, bool invert)
{
    int lg = 0;
    while((1<<lg) < SZ(a)) lg++;
    FOR (i, 0, SZ(a))
    {
        int x=0;
        FOR (j, 0, lg)
        x |= ((i>>j)&1)<<(lg-j-1);
        if(i<x)
            swap(a[i], a[x]);
    }
    for (int len = 2; len <= SZ(a); len *= 2)
    {
        int diff = LEN / len;
        if (invert) diff = LEN - diff;
        for (int i = 0; i < SZ(a); i += len)
        {
            int pos = 0;
            FOR (j, 0, len/2)
            {
                base v = a[i+j];
                base u = a[i+j+len/2] * PW[pos];
                a[i+j] = v + u;
                a[i+j+len/2] = v - u;
                pos += diff;
                if (pos >= LEN) pos -= LEN;
            }
        }
    }
    if (invert)
        FOR (i, 0, SZ(a))
        a[i] /= SZ(a);
}
void initFFT()
{
    double angle = 2 * Pi / LEN;
    FOR (i, 0, LEN)
    {
        double ca = angle * i;
        PW[i] = base(cos(ca), sin(ca));
    }
}

VI mult(VI A)
{
    int l = 1;
    while (l <= SZ(A)) l *= 2;
    l *= 2;
    
    vector<base> P(l);
    
    FOR(i,0,SZ(A))
        P[i] = A[i];
    fft(P , 0);
    FOR(i,0,l)
    {
        P[i] *= P[i];
    }
    fft(P  , 1);
    vector<Int> C(l);
    FOR(i,0,l)
    {
        C[i] = (Int)(P[i].real() + .5);
    }
    
    FOR(i,0,SZ(C))
    {
        if (C[i] >= BASE)
        {
            if (i + 1 == SZ(C)) C.push_back(0);
            C[i + 1] += C[i] / BASE;
            C[i] %= BASE;
        }
    }
    while (C.back() == 0 && C.size() > 1) C.pop_back();
    
    VI CC(C.size());
    FOR(i,0,C.size()) CC[i] = C[i];
    
    return CC;
}

VI mult(VI A, int x)
{
    FOR(i,0,SZ(A))
    {
        A[i] *= x;
    }
    FOR(i,0,SZ(A))
    {
        if (A[i] >= BASE)
        {
            if (i + 1 == SZ(A)) A.push_back(0);
            A[i + 1] += A[i] / BASE;
            A[i] %= BASE;
        }
    }
    return A;
}


bool Less(VI A, VI B)
{
    if (SZ(A) < SZ(B)) return true;
    if (SZ(A) > SZ(B)) return false;
    RFOR(i,SZ(A) , 0)
    {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }
    return false;
}

char s[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    
    initFFT();
    
    
    
    scanf("%s" , s);
    int n = strlen(s);
    
    /*int n = 1500000;
    FOR(i,0,n)
    {
        s[i] = '9';
    }*/
    
    
    int pw3 = (double)n * log(10.0) / log(3.0);
    FOR(i,0,7)
    {
        if (pw3 > 0) -- pw3;
    }
    
    
    VI B(1,1);
    RFOR(i,23,0)
    {
        B = mult(B);
        if (pw3 & (1 << i))
        {
            B = mult(B, 3);
        }
    }
    
    
    
    VI A;
    
    while (n > 0)
    {
        int x = 0;
        FOR(i,0,3)
        {
            if (n - 3 + i < 0) continue;
            x = 10 * x + s[n - 3 + i] - '0';
        }
        A.push_back(x);
        n -= 3;
    }
    
    if (SZ(A) == 1 && A[0] == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    
    int res = 1e9;
    
    
    //cout << SZ(A) << ' ' << SZ(B) << endl;
    //cout << A.back() << ' ' << B.back() << endl;
    
    /*RFOR(i,SZ(A) , 0)
    {
        printf("%04d" , A[i]);
    }
    cout << endl;
    RFOR(i,SZ(B) , 0)
    {
        printf("%04d" , B[i]);
    }
    cout << endl;*/
    
    FOR(c,0,3)
    {
        VI C = B;
        int r = 3 * pw3 + 2 * c;
        while (Less(C , A))
        {
            C = mult(C, 3);
            r += 3;
        }
        res = min(res , r);
        B = mult(B , 2);
    }
    
    cout << res << endl;
    
    
    return 0;
}
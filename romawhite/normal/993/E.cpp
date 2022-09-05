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
const int MAX = 400007;
const int INF = 1000000000;


typedef complex<double> base;
const int LEN = 1<<18; // max length, power of 2
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

Int res[MAX];


int n , x;

void mult(VI A, VI B)
{
    
    int l = 1;
    while (l <= max(SZ(A) , SZ(B))) l *= 2;
    l *= 2;
    
    vector<base> AA(l) , BB(l);
    
    FOR(i,0,SZ(A))
        AA[i] = A[i];
    FOR(i,0,SZ(B))
        BB[i] = B[i];
    fft(AA , 0);
    fft(BB , 0);
    FOR(i,0,l)
    {
        AA[i] *= BB[i];
    }
    fft(AA  , 1);
    FOR(i,0,l)
    {
        res[i] += (Int)(AA[i].real() + .5);
    }
    
}

int T[MAX];

void solve(int l, int r)
{
    if (r - l < 100)
    {
        FOR(i, l , r + 1)
        {
            int cnt = 0;
            FOR(j,i,r + 1)
            {
                if (T[j] < x)
                {
                    ++ cnt;
                }
                res[cnt] ++;
            }
        }
        return;
    }
    
    
    VI A((r - l) / 2 + 7);
    VI B((r - l) / 2 + 7);
    
    int s = 0;
    int m = (l + r) / 2;
    RFOR(i,m + 1 , l)
    {
        if (T[i] < x) ++ s;
        A[s] ++;
    }
    s = 0;
    FOR(i,m + 1 , r + 1)
    {
        if (T[i] < x) ++ s;
        B[s] ++;
    }
    
    mult(A, B);
    
    solve(l, m);
    solve(m + 1 , r);
    
}

int main()
{
    //freopen("in.txt", "r", stdin);

    initFFT();
    
    cin >> n >> x;
    //n = 200000;
    //x = rand();
    
    FOR(i,0,n)
    {
        scanf("%d" , &T[i]);
        //T[i] = rand();
    }
    
    
    solve(0, n - 1);
    
    
    FOR(i,0,n + 1)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
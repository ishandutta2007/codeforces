

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 7801;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

int inv(vector<int> p)
{
    /*FOR(i,0,p.size())
    {
        cout << p[i] << ' ';
    }
    cout << endl;*/

    int r = 0;
    FOR(i,0,p.size())
    {
        FOR(j,i + 1,p.size())
        {
            if (p[j] < p[i])
                ++r;
        }
    }
    return r;
}

vector<pair<int,int> > A;

double run(vector<int> p, int k)
{
    if (k == 0)
    {
        return inv(p);
    }
    double val = 0.0;
    FOR(id,0,A.size())
    {
        vector<int> b = p;
        int L = A[id].first;
        int R = A[id].second;
        while (L < R)
        {
            swap(b[L] , b[R]);
            ++L;
            --R;
        }
        val += run(b, k - 1);
    }
    return val / A.size();
}

int main()
{
   // freopen("in.txt", "r", stdin);

    int n , k;
    cin >> n >> k;
    vector<int> p(n);
    FOR(i,0,n)
    {
        cin >> p[i];
        --p[i];
    }

    FOR(i,0,p.size())
    {
        FOR(j,i,p.size())
        {
            A.push_back(MP(i, j));
        }
    }
    printf("%.10f\n" , run(p, k));

    return 0;
}
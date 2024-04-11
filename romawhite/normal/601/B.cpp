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
#include <cassert>
#include<complex>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 100007;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int a[MAX];
int b[MAX];
int L[MAX];
int R[MAX];


int main()
{
    //freopen("in.txt", "r", stdin);

    int n , q;
    cin >> n >> q;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    FOR(i,0,n - 1)
    {
        b[i] = abs(a[i + 1] - a[i]);
    }
    --n;

    vector<PII> A;
    FOR(i,0,n)
    {
        while (A.size() && A.back().first < b[i]) A.pop_back();
        L[i] = -1;
        if (A.size()) L[i] = A.back().second;
        A.push_back(MP(b[i] , i));
    }
    A.clear();
    RFOR(i,n,0)
    {
        while (A.size() && A.back().first <= b[i]) A.pop_back();
        R[i] = n;
        if (A.size()) R[i] = A.back().second;
        A.push_back(MP(b[i] , i));
    }

    FOR(i,0,q)
    {
        int l , r;
        cin >> l >> r;
        --l;--r;--r;

        Int res = 0;
        FOR(i,l, r + 1)
        {
            int ll = max(l, L[i] + 1);
            int rr = min(R[i] - 1 , r);
            res += 1LL * b[i] * (i - ll + 1) * (rr - i + 1);
        }
        cout << res << endl;
    }


    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
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

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;

Int gcd(Int a , Int b)
{
    if (!b) return a;
    return gcd(b , a % b);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("huffman.in" , "r" , stdin);

    Int C, H1, H2, W1, W2;
    cin >> C >> H1 >> H2 >> W1 >> W2;
    Int res = 0;

    Int L = W1 * W2 / gcd(W1, W2);
    Int t = max(0LL , C / L - 2);
    Int a = L / W1 * H1;
    Int b = L / W2 * H2;
    res += t * max(a , b);
    C -= t * L;
    if (W1 < W2)
    {
        swap(W1, W2);
        swap(H1,H2);
    }
    //cout << res << ' ' << C << endl;
    Int r1 = 0;
    for(int x = 0;; ++x)
    {
        if (x * W1 > C) break;
        int y = (C - x * W1) / W2;
        r1 = max(r1 , x * H1 + y * H2);
    }

    cout << res + r1 << endl;

    return 0;
}
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



int main()
{
    //freopen("in.txt", "r", stdin);

    set<pair<Int, Int> > S;

    Int x;
    cin >> x;
    x *= 6;

    FOR(m,1,4000000)
    {
        Int xx = x;
        if (xx % m) continue;
        xx /= m;
        if (xx % (m + 1) ) continue;
        xx /= (m + 1);
        Int n = m - 1 + xx;
        if (n % 3) continue;
        n /= 3;
        if (n < m) break;
        S.insert(MP(n , m));
        S.insert(MP(m , n));
    }

    cout << S.size() << endl;
    for(set<pair<Int, Int> >::iterator it = S.begin(); it != S.end(); ++it)
        printf("%I64d %I64d\n" , it->first , it->second);

    return 0;
}
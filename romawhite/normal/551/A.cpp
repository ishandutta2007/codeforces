#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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
const int MAX = 2007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int cnt[MAX];
int a[MAX];

int main()
{
    //freopen("in.txt" , "r", stdin);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    FOR(i,0,n)
    {
        int c = 0;
        FOR(j,a[i] + 1,MAX)
        {
            c += cnt[j];
        }
        cout << c + 1 << ' ';
    }
    cout << endl;

    return 0;
}
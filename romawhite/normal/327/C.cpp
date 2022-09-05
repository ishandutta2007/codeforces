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
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1<<30;
const int MAX = 1<<17;
const int MOD = 1000000007;

int a[107];

Int bpow(Int a, Int k){
    if (!k) return 1;
    if (k & 1) return (a * bpow(a , k - 1)) % MOD;
    return bpow ((a * a) % MOD , k / 2);
}

int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    string s;
    Int k;
    cin >> s >> k;
    Int n = s.size();

    Int a = (bpow(2 , k * n) - 1 + MOD) % MOD;
    a *= bpow( (bpow(2 , n) - 1 + MOD) % MOD , MOD - 2);
    a %= MOD;

    Int b = 0;
    FOR(i,0,s.size())
        if (s[i] == '0' || s[i] == '5')
            b = (b + bpow(2 , i) ) % MOD;

    cout << a * b % MOD << endl;

    return 0;
}
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
const int MAX = 200007;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 2000003;
const int CNT = 1000;

map<string, int> M;

string lowerCase(string s)
{
    string r = s;
    FOR(i,0,r.size())
    {
        if (r[i] >= 'A' && r[i] <= 'Z')
            r[i] = r[i] - 'A' + 'a';
    }
    return r;
}

int main()
{
   //freopen("in.txt", "r", stdin);


    int n;
    cin >> n;
    int res = 1;
    M["polycarp"] = 1;
    FOR(i,0,n)
    {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        s1 = lowerCase(s1);
        s3 = lowerCase(s3);
        M[s1] = M[s3] + 1;
        res = max(res , M[s1]);
    }
    cout << res << endl;

    return 0;
}
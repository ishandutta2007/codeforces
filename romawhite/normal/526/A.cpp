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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("huffman.in" , "r" , stdin);

    int n;
    cin >> n;
    string s;
    cin >> s;
    bool a = 0;

    FOR(i,0,s.size())
    {
        FOR(j,i + 1 , s.size())
        {
            bool ok = 1;
            if (s[i] == '.') ok = 0;
            if (s[j] == '.') ok = 0;
            if (j + (j - i) >= s.size() || s[j + (j - i)] == '.') ok = 0;
            if (j + 2 * (j - i) >= s.size() || s[j + 2 * (j - i)] == '.') ok = 0;
            if (j + 3 * (j - i) >= s.size() || s[j + 3 * (j - i)] == '.') ok = 0;
            if (ok) a = 1;
        }
    }
    if (a) cout << "yes" << endl;
    else cout << "no" << endl;


    return 0;
}
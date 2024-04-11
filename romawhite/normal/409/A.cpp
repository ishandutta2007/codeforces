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
#include <fstream>
#include <time.h>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int INF = 1000000000;
const int MOD = 1000000007;

int res[1007];
int dp[1007];
int p[1007];

int main()
{

    string s1 , s2;
    cin >> s1 >> s2;

    int k1 = 0;
    int k2 = 0;
    for(int i = 0; i < s1.size(); i += 2){
            if (s1[i] == '8' && s2[i] == '(')
                ++k2;
            if (s1[i] == '8' && s2[i] == '[')
                ++k1;
            if (s1[i] == '(' && s2[i] == '8')
                ++k1;
            if (s1[i] == '(' && s2[i] == '[')
                ++k2;
            if (s1[i] == '[' && s2[i] == '8')
                ++k2;
            if (s1[i] == '[' && s2[i] == '(')
                ++k1;
    }
    if (k1 > k2)
        cout << "TEAM 1 WINS\n";
    if (k1 == k2)
        cout << "TIE\n";
    if (k1 < k2)
        cout << "TEAM 2 WINS\n";
}
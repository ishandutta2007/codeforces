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

const int MAX = 100007;
const int MOD = 1000000007;

string s[6];


int main()
{
  //  freopen("in.txt" , "r" , stdin);
  //  freopen("out.txt" , "w" , stdout);

    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";

    int k;
    cin >> k;

    int x = 1;
    int y = 1;
    FOR(i,0,k)
    {
        s[x][y] = 'O';
        ++x;
        if (x == 3 && y > 1) ++x;
        if (x == 5)
        {
            x = 1;
            y += 2;
        }
    }
    FOR(i,0,6)
    {
        cout << s[i] << endl;
    }

    return 0;
}
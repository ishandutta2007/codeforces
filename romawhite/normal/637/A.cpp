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
#include <cassert>
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

const int INF = 1000000000;
const int MAX = 1000047;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
    //freopen("queens.in" , "r" , stdin);
    //freopen("queens.out" , "w" , stdout);

    int mx = 0;
    int id = 0;
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        int x;
        cin >> x;
        a[x]++;
        if (a[x] > mx)
        {
            mx = a[x];
            id = x;
        }
    }
    cout << id << endl;

	return 0;
}
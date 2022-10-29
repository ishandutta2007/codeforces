#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, t;
int m[1000][1000];

bool read()
{
    cin >> n >> t;
    return true;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void calc(int x, int y)
{
    int l = m[x][y];
    l >>= 2;
    m[x][y] &= 3;
    if (l)
    {
        forn (i, 4)
        {
            int nx = x + dx[i], ny = y + dy[i];
            m[nx][ny] += l;
            calc (nx, ny);
        }
    }
}

void solve()
{
    m[500][500] = n;
    calc(500, 500);
    forn (i, t)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", (abs(a) < 300 && abs(b) < 300 ? m[a + 500][b + 500] : 0));
    }
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}
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
#define y1 adsfadsfadfs

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 15000000;

vector<int> gen(int l , int r, int n)
{
    vector<int> a;
    if(l <= 0 && r >= 0)
    {
        a.push_back(0);
        if (n == 1) return a;
        FOR(i,1,n + 7)
        {
            if (i >= l && i <= r)
            {
                a.push_back(i);
                if (a.size() == n) break;
            }
            if (-i >= l && -i <= r)
            {
                a.push_back(-i);
                if (a.size() == n) break;
            }
        }
        sort(ALL(a));
        return a;
    }
    if (l > 0)
    {
        FOR(i,l,l + n)
        {
            a.push_back(i);
        }
        return a;
    }
    FOR(i,0,n)
    {
        a.push_back(r - i);
    }
    sort(ALL(a));
    return a;
}

int parse(string s)
{
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

int a[MAX];
vector<int> b[MAX];
char buf[15];
int ptr[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif


    int n , k;
    cin >> n >> k;
    FOR(i,0,n)
    {
        int x;
        scanf("%s" , buf);
        if (buf[0] == '?') x = INF + 7;
        else x  = parse(buf);
        a[i] = x;
        b[i % k].push_back(x);
    }
    bool ok = 1;
    FOR(i,0,k)
    {
        Int l = -2 * INF;
        Int r = 2 * INF;
        int cnt = 0;
        FOR(j,0,b[i].size())
        {
            if (b[i][j] == INF + 7)
            {
                ++cnt;
            }
            else
            {
                if (cnt)
                {
                    r = b[i][j] - 1;
                    if (r - l + 1 < cnt)
                    {
                        ok = 0;
                        break;
                    }
                    vector<int> c = gen(l, r , cnt);
                    FOR(t,0,c.size())
                    {
                        b[i][j - c.size() + t] = c[t];
                    }
                    cnt = 0;
                }
                l = b[i][j] + 1;
            }
        }
        if (cnt)
        {
            vector<int> c = gen(l, 2 * INF , cnt);
            FOR(t,0,c.size())
            {
                b[i][b[i].size() - c.size() + t] = c[t];
            }
        }
    }

    FOR(i,0,k)
    {
        FOR(j,0,(int)b[i].size() - 1)
        {
            if (b[i][j + 1] <= b[i][j])
                ok = 0;
        }
    }

    if (!ok)
    {
        cout << "Incorrect sequence" << endl;
        return 0;
    }

    FOR(i,0,n)
    {
        printf("%d " , b[i % k][ptr[i % k]++]);
    }
    cout << endl;

    return 0;
}
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
const int MAX = 200000;
const int MAX2 = 2000;
const int BASE = 1000000000;

int f(string s)
{
    int H = 10 * (s[0] - '0') + s[1] - '0';
    int M = 10 * (s[3] - '0') + s[4] - '0';
    int S = 10 * (s[6] - '0') + s[7] - '0';
    return S + 60 * M + 60 * 60 * H;
}

int A[90000];
char buf[10];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n , m , T;
    cin >> n >> m >> T;

    FOR(i,0,n)
    {
        scanf("%s" , buf);
        string s = buf;
        int t = f(s);
       // cout << t << endl;
        A[t]++;
    }

    set<pair<int, int> > cur;
    vector<int> res;
    int cnt = 0;
    bool ok = 0;
    FOR(i,0,90000)
    {
        while (1)
        {
            if (cur.size() == 0) break;
            pair<int,int> p = *cur.begin();
            if (p.first == i - T)
            {
                cur.erase(cur.find(p));
            }
            else
            {
                break;
            }
        }
        FOR(j,0,A[i])
        {
            if (cur.size() < m)
            {
                res.push_back(cnt++);
                cur.insert(MP(i , cnt - 1));
            }
            else
            {
                pair<int,int> last = *cur.rbegin();
                res.push_back(last.second);
                cur.erase(cur.find(last));
                cur.insert(MP(i, last.second));
            }
        }
        if (cur.size() == m)
        {
            ok = 1;
        }
    }

    if (!ok) cout << "No solution" << endl;
    else
    {
        cout << cnt << endl;
        FOR(i,0,res.size())
        {
            cout << res[i] + 1 << endl;
        }
    }


    return 0;
}
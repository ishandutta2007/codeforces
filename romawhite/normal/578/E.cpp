#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

char s[MAX];

vector<int> res;
int ans = INF;


void f(set<int> L, set<int> R)
{
    if (L.size() < R.size()) return;
    int cnt = 0;
    vector<int> path;
    while (L.size() || R.size())
    {
        //cout << path.size() << ' ' << L.size() <<  ' '  << R.size() << endl;
        int id = (path.size() ? path.back() : -1);
        if (path.size() % 2 == 0)
        {
            set<int>::iterator it = L.lower_bound(id);
            if (it != L.end())
            {
                path.push_back(*it);
                L.erase(it);
            }
            else
            {
                ++cnt;
                if (R.size() && *R.begin() < *L.begin())
                {
                    R.insert(path.back());
                    path.pop_back();
                    path.push_back(*R.begin());
                    R.erase(R.begin());
                }
                else
                {
                    path.push_back(*L.begin());
                    L.erase(L.begin());
                }
            }
        }
        else
        {
            set<int>::iterator it = R.lower_bound(id);
            if (it != R.end())
            {
                path.push_back(*it);
                R.erase(it);
            }
            else
            {
                ++cnt;
                if (L.size() && *L.begin() < *R.begin())
                {
                    L.insert(path.back());
                    path.pop_back();
                    path.push_back(*L.begin());
                    L.erase(L.begin());
                }
                else
                {
                    path.push_back(*R.begin());
                    R.erase(R.begin());
                }
            }
        }
    }
    if (cnt < ans)
    {
        ans = cnt;
        res = path;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%s" , s);

    int n = strlen(s);

    set<int> L;
    set<int> R;

    FOR(i,0,n)
    {
        if (s[i] == 'L')
            L.insert(i);
        else R.insert(i);
    }

    f(L, R);
    f(R, L);

    cout << ans << endl;
    FOR(i,0,res.size())
    {
        printf("%d " , res[i] + 1);
    }
    cout << endl;

    return 0;
}
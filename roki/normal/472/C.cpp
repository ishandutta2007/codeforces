#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9;
const ld EPS = 1e-10;

int n;
char c[100000][105];

int ord[100000];

bool read()
{
    scanf("%d\n", &n);

    forn (i, n)
        gets(c[i]);

    forn (i, n)
    {
        scanf("%d", &ord[i]);
        ord[i]--;
    }

    return true;
}

void solve() 
{
    string prev = "";

    forn (i, n)
    {
        string s[2];
        int l = -1;
        forn (j, 2)
        {
            l++;
            while(c[ord[i]][l] >= 'a' && c[ord[i]][l] <= 'z')
                s[j] += c[ord[i]][l++];
        }

        if (s[0] > s[1])
            swap(s[0], s[1]);
        if (i > 0 && s[0] < prev)
            swap(s[0], s[1]);
        if (i > 0 && prev > s[0])
        {
            puts("NO");
            return;
        }
        prev = s[0];
    }
    cout << "YES" << endl;
}   

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    read();
    solve();

    return 0;
}
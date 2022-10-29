#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

char c[111][111];
int n, m;

vector<bool> p(100000, 0);

void f(int a, int b)
{   
    if(a > 0)
    {
        p[c[a - 1][b]] = 1;
    }
    if(a < n)
    {
        p[c[a + 1][b]] = 1;
    }
    if(b > 0)
    {
        p[c[a][b - 1]] = 1;
    }
    if(b < m)
    {
        p[c[a][b + 1]] = 1;
    }
}

int main()
{
    char pr;
    cin >> n >> m >> pr;
    forn (i, n)
        forn (j, m)
            cin >> c[i][j];
    forn (i, n)
        forn (j, m)
        {
            if(c[i][j] == pr)
                f(i, j);
        }
    int ans = 0;
    for (char q = 'A'; q <= 'Z'; ++q)
    {
        if(p[q] && q != pr)
            ans++;
    }
    cout << ans << endl;
}
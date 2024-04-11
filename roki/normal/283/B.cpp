#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
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

bool u[200100][2];
li d[200100][2];
int n;
li a[200100];

li INF = 1e18;

void fill(int v, int p)
{
    if(u[v][p])
    {
        d[v][p] = -1;
        return;
    }
    u[v][p] = true;
    if(p == 0 && v + a[v] > n)
    {
        d[v][p] = a[v];
        return;
    }
    if(p == 1 && v - a[v] <= 0)
    {
        d[v][p] = a[v];
        return;
    }
    if(p == 0 && d[v + a[v]][1] == INF)
        fill(v + a[v], 1);
    if(p == 1 && d[v - a[v]][0] == INF)
        fill(v - a[v], 0);
    if(p == 0)
    {
        if(d[v + a[v]][1] == -1)
            d[v][0] = -1;
        else
            d[v][0] = d[v + a[v]][1] + a[v];
    }
    else
    {
        if(d[v - a[v]][0] == -1)
            d[v][1] = -1;
        else
            d[v][1] = d[v - a[v]][0] + a[v];
    }
}

int main()
{
    
    cin >> n;
    for (int i = 2; i <= n; ++i)
        cin >> a[i];
    
    forn (i, 200100)
        d[i][0] = d[i][1] = INF;

    for (int i = 2; i <= n; ++i)
    {
        if(d[i][0] == INF)
            fill(i, 0);
        if(d[i][1] == INF)
            fill(i, 1);
    }
    
    for (int i = 1; i < n; ++i)
    {
        a[1] = i;
        u[1][0] = u[1][1] = false;
        d[1][0] = d[1][1] = INF;
        fill(1, 0);
        fill(1, 1);
        if(1 + a[1] > n)
            cout << a[1] << endl;
        else
        {
            if(d[1 + a[1]][1] == -1)
                cout << -1 << endl;
            else
                cout << d[1 + a[1]][1] + a[1] << endl;
        }
    }

    return 0;
}
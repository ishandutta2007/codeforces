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

int p[100100];

bool prime(int a)
{
    if(a == 1)
        return 0;
    if(a == 2)
        return 1;
    if(a % 2 == 0)
        return 0;
    for (int i = 3; i * i <= a; i += 2)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a[500][500];
    int n, m;
    cin >> n >> m;
    forn (i, n)
        forn (j, m)
            cin >> a[i][j];
    int k = 100001;
    while(!prime(k))
        k++;
    for (int i = 100000; i > 0; --i)
    {
        if(prime(i))
            k = i;
        p[i] = k;
    }
    int ans = 1e9;
    
    forn(i, n)
    {
        int q = 0;
        forn (j, m)
            q += p[a[i][j]] - a[i][j];
        if(q < ans)
            ans = q;
    }
    forn(j, m)
    {
        int q = 0;
        forn (i, n)
            q += p[a[i][j]] - a[i][j];
        if(q < ans)
            ans = q;
    }
    cout << ans << endl;
    return 0;
}
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

int f(int a)
{
    if(a == 1)
        return 1;
    if(a == 0)
        return 0;
    if(a % 2 == 0)
        return f(a / 2);
    return 1 + f(a / 2);
}

int main()
{
    int n;
    cin >> n;
    vector<li> v(100000, 0);
    forn (i, n)
    {
        int a;
        cin >> a;
        v[f(a)]++;
    }
    li ans = 0;
    forn (i, 100000)
        ans += v[i] * (v[i] - 1) / 2;
    cout << ans << endl;
    return 0;
}
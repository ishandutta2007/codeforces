#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
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

int mod = 1e9 + 7;

li f(li a)
{
    li res = 1;
    for (int i = 2; i <= a; ++i)
    {
        res *= i;
        res %= mod;
    }
    return res % mod;
}

int main()
{
    li p[] = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925, 1606008513, 87656896891, 5778121715415, 452794797220965, 41609568918940625};
    int n;
    cin >> n;
    if(n % 2 == 0)
        cout << 0;
    else
        cout << p[n / 2] * f(n) % mod << endl;
    return 0;
}
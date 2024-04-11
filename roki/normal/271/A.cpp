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

bool f(int a)
{
    vector<bool> u(10, 0);
    while(a)
    {
        if(u[a % 10])
            return false;
        u[a % 10] = 1;
        a /= 10;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    n++;
    while(!f(n))
        n++;
    cout << n;
    return 0;
}
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

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    forn (i, n)
    {
        int a;
        cin >> a;
        sum += a;
    }
    int ans = 0;
    forn (i, 5)
    {
        if((sum + i) % (n + 1) != 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
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
    int n, ans = 0;
    cin >> n;
    int a[100], b[100];
    forn (i, n)
        cin >> a[i] >> b[i];
    forn (i, n)
        forn (j, n)
        {
            if(a[i] == b[j])
                ans++;
        }
    cout << ans << endl;
    return 0;
}
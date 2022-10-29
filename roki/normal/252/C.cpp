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

#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair

typedef long long li;

int main()
{   
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];
    li j = 0, l = 0, ans = 0;
    for(li i = 0;i < n - 2;++i)
    {
        while(j < n && a[j] - d <= a[i])
            j++;
        ans += (j - i - 1) * (j - 2 - i) / 2;
    }
    cout << ans << endl;
    return 0;
}
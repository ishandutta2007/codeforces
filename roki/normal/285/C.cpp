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

int main()
{
    
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];
    sort(a.begin(), a.end());
    li ans = 0;
    forn (i, n)
        ans += abs(a[i] - i - 1);
    cout << ans << endl;
    return 0;
}
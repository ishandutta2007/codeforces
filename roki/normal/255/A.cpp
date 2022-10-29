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

int main()
{
    string s[3] = {"chest", "biceps", "back"};
    vector<int> a(3, 0);
    int n;
    cin >> n;
    forn(i, n)
    {
        int w;
        cin >> w;
        a[i % 3] += w;
    }
    if(a[0] > a[1] && a[0] > a[2])
        cout << s[0];
    if(a[1] > a[0] && a[1] > a[2])
        cout << s[1];
    if(a[2] > a[1] && a[2] > a[0])
        cout << s[2];
    return 0;
}
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
    int M = 334;
    vector<li> a(n);
    vector<li> p(n, 0);
    forn (i, n)
    {
        cin >> a[i];
        if(i > 0)
            p[i] = max(p[i - 1], a[i]);
        else
            p[i] = a[i];
    }
    int m;
    cin >> m;
    int j = 0;
    li biggest = 0;
    forn (i, m)
    {
        li h, w;
        cin >> w >> h;
        if(p[w - 1] > biggest)
            biggest = p[w - 1];
        cout << biggest << endl;
        biggest += h;
    }

    return 0;
}
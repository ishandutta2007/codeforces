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
    int a[3][3];
    forn (i, 3)
    {
        forn (j, 3)
        {
            cin >> a[i][j];
        }
    }
    int S = (a[0][1] + a[0][2] + a[1][0] + a[1][2] + a[2][0] + a[2][1]) / 2;
    a[0][0] = S - a[0][1] - a[0][2];
    a[1][1] = S - a[1][0] - a[1][2];
    a[2][2] = S - a[2][0] - a[2][1];
    forn (i, 3)
    {
        forn (j, 3)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
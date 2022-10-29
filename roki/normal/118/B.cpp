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
    int ans[20][20];
    int n;
    cin >> n;
    forn (i, 2 * n + 1)
        forn (j, 2 * n + 1)
            ans[i][j] = n - (abs(n - i) + abs(n - j));
    forn (i, 2 * n + 1)
        forn (j, 2 * n + 1)
        {
            if(ans[i][j] > 0)
                cout << ans[i][j] << ' ';
            if(ans[i][j] == 0)
            {
                if(j < 2 * n - 1)
                    if(ans[i][j + 1] == 1)
                        cout << "0 ";
                    else
                    {
                        cout << "0\n";
                        break;
                    }
                else
                {
                    cout << "0\n";
                    break;
                }
            }
            if(ans[i][j] < 0)
                cout << "  ";
        }
    return 0;
}
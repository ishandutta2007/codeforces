#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ios>
using namespace std;
vector<int> a[1000000];
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int num = 1;
        bool p = 1;
        int st;
        for (int j = 0;j < k; j++)
        {
            int x;
            cin >> x;
            if (j==0)
            st=x;
            a[i].push_back(x);
            if (j > 0)
            {
                if (a[i][j] - a[i][j - 1] == 1 && p)
                    num++;
                else p = 0;

                if (st!=1)
                    num = 0;
            }
        }
        mx = max(mx, num);
        ans += k - 1;
    }
    ans += n - 2*mx+1;
    cout << ans << endl;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int two[1000][1000],five[1000][1000];
    cin >> n;
    bool is_zero = false;
    int zero_i, zero_j;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            two[i][j] = 0;
            five[i][j] = 0;
            int t;
            cin >> t;
            if (t)
            {
                while (t % 2 == 0)
                {
                    ++two[i][j];
                    t >>= 1;
                }
                while (t % 5 == 0)
                {
                    ++five[i][j];
                    t /= 5;
                }
            }
            else
            {
                two[i][j] = 100;
                five[i][j] = 100;
                if (!is_zero)
                {
                    is_zero = true;
                    zero_i = i;
                    zero_j = j;
                }
            }
            //cout << i << " " << j << " " << two[1][1] << endl;
        }
    }
    int ans1[n][n], ans2[n][n];
    char a1[n][n], a2[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ans1[i][j] = ans2[i][j] = 10000000;
    ans1[0][0] = two[0][0];
    ans2[0][0] = five[0][0];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if (i)
            {
                if (ans1[i][j] > ans1[i - 1][j] + two[i][j])
                {
                    a1[i][j] = 'D';
                    ans1[i][j] = ans1[i - 1][j] + two[i][j];
                }
                if (ans2[i][j] > ans2[i - 1][j] + five[i][j])
                {
                    a2[i][j] = 'D';
                    ans2[i][j] = ans2[i - 1][j] + five[i][j];
                }
            }
            if (j)
            {
                if (ans1[i][j] > ans1[i][j - 1] + two[i][j])
                {
                    a1[i][j] = 'R';
                    ans1[i][j] = ans1[i][j - 1] + two[i][j];
                }
                if (ans2[i][j] > ans2[i][j - 1] + five[i][j])
                {
                    a2[i][j] = 'R';
                    ans2[i][j] = ans2[i][j - 1] + five[i][j];
                }
            }
        }
    if (is_zero && min(ans1[n-1][n-1], ans2[n-1][n-1]))
    {
        cout << "1\n";
        int i = 0, j = 0;
        while (i < zero_i)
        {
            putchar('D');
            ++i;
        }
        while(j < zero_j)
        {
            putchar('R');
            ++j;
        }
        while (i < n - 1)
        {
            putchar('D');
            ++i;
        }
        while(j < n - 1)
        {
            putchar('R');
            ++j;
        }
        return 0;
    }
    vector <char> ans;
    if (ans1[n-1][n-1] < ans2[n-1][n-1])
    {
        cout << ans1[n-1][n-1] << endl;
        int i = n - 1, j = n - 1;
        while (i || j)
        {
            ans.push_back(a1[i][j]);
            if (a1[i][j] == 'R')
                --j;
            else
                --i;
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < (int)ans.size(); ++i)
            putchar(ans[i]);
    }
    else
    {
        cout << ans2[n-1][n-1] << endl;
        int i = n - 1, j = n - 1;
        while (i || j)
        {
            ans.push_back(a2[i][j]);
            if (a2[i][j] == 'R')
                --j;
            else
                --i;
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < (int)ans.size(); ++i)
            putchar(ans[i]);
    }
    
    return 0;
}
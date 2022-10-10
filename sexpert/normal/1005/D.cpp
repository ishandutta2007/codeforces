#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int dp[200009];
    dp[0] = 0;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        int d, aux = 0;
        for(int j = i; j >= 0; j--)
        {
            aux += (s[j] - '0');
            if(aux % 3 == 0)
            {
                d = dp[j] + 1;
                break;
            }
        }
        dp[i + 1] = max(dp[i], d);
    }
    cout << dp[n];
}
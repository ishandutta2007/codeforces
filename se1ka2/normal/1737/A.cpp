#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        char ans[205];
        for (int i = 0; i < k; i++)
        {
            ans[i] = 'a';
        }
        for (char c = 'a'; c < 'z'; c++)
        {
            if (c - 'a' == n / k)
            {
                break;
            }
            int d = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c)
                {
                    d++;
                }
            }
            for (int i = 0; i < min(k, d); i++)
            {
                if (ans[i] == c)
                {
                    ans[i]++;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        n *= 2;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (i == 0 || s[i - 1] == '(')
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if(n == 2)
        {
            cout << s[1] << endl;
        }
        else
        {
            char ans = '9';
            for(int i = 0; i < n; i++)
            {
                ans = min(ans, s[i]);
            }
            cout << ans << endl;
        }
    }
}
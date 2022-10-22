#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int c = 0;
        for(int i = 0; i < k; i++)
        {
            if(s[i] == 'W')
            {
                c++;
            }
        }
        int ans = c;
        for(int i = k; i < n; i++)
        {
            if(s[i] == 'W')
            {
                c++;
            }
            if(s[i - k] == 'W')
            {
                c--;
            }
            ans = min(ans, c);
        }
        cout << ans << endl;
    }
}
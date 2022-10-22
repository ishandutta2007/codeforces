#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s0[100005], s1[100005];
        s0[0] = s1[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            s0[i] = s0[i - 1] + (a[i - 1] == 0);
            s1[i] = s1[i - 1] + (a[i - 1] == 1);
        }
        int ans = n;
        for(int i = 0; i <= n; i++)
        {
            ans = min(ans, s1[i] + max(0, s0[n] - s0[i] - s1[i]));
        }
        cout << ans << endl;
    }
}
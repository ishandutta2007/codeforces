#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            ans = max(ans, a | x);
        }
        cout << ans << endl;
    }
}
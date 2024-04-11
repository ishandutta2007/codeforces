#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int p[100005], q[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
            q[p[i]] = i;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            cout << q[i] + 1 << " ";
        }
        cout << "\n";
    }
}
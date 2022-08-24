#include <iostream>

using namespace std;
const int MAXN = 2100;

int parent[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = i;
        int count = 0;
        while (cur >= 0)
        {
            cur = parent[cur];
            count++;
        }
        ans = max (ans, count);
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}
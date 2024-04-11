#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int N;
string a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> a >> b;

    int ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] != b[i] && a[i+1] != b[i+1])
        {
            if (a[i] == b[i+1] && a[i+1] == b[i])
            {
                swap (a[i], a[i+1]);
                ans++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] != b[i])
        {
            a[i] = b[i];
            ans++;
        }
    }
    cout << ans << "\n";
}
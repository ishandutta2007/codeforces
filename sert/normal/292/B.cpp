#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x, ans, m, v1, v2;
int a[100010];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        a[v1 - 1]++;
        a[v2 - 1]++;
    }
    sort(a, a + n);
    if (a[n - 1] == n - 1 && a[n - 2] == 1)
        cout << "star topology";
    else if (a[1] == 1 && a[2] == 2 && a[n - 1] == 2)
        cout << "bus topology";
    else if (a[0] == a[n - 1] && a[0] == 2)
        cout << "ring topology";
    else
        cout << "unknown topology";
    return 0;
}
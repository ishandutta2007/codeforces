#include <iostream>

using namespace std;

int a[100500], n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = 2;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            ans++;
            if (a[i - 1] == 0)
                ans++;
        }
    }
    cout << max(0, ans - 1);
    return 0;
}
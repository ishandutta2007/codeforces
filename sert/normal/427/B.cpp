#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 34;

int n, a[N], k, ans;
int pr = -1, len, c;


int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> k >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    a[n] = k + 1;

    for (int i = 0; i <= n; i++) {
        if (a[i] > k) {
            //cerr << len << " ";
            ans += max(0, len + 1 - c);
            len = 0;
            pr = a[i];
        } else
            len++;
    }
    cout << ans;

    return 0;
}
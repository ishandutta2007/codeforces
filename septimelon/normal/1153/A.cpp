#include <iostream>

using namespace std;

int main()
{
    int n, t;
    int s[101], d[101];
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> d[i];
    for (int i = 1; i <= n; i++) {
        while (s[i] < t)
            s[i] += d[i];
    }
    int mint, mini;
    mint = 1000000;
    for (int i = 1; i <= n; i++) {
        if (s[i] < mint) {
            mint = s[i];
            mini = i;
        }
    }
    cout << mini;
    return 0;
}
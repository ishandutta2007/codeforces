#include <bits/stdc++.h>
using namespace std;

string s = "I love bananas";
int n, a, b;
int main()  {
    cin >> n >> a >> b >> s;
    int k = -1;
    while (true) {
        k++;
        if (n < 0) {
            cout << "-1";
            return 0;
        }
        if (n % b == 0)
            break;
        n -= a;
    }

    cout << k + n / b << "\n";
    int t = n / b;
    n = s.length();

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < a; j++)
            cout << s[i * a + j];
        cout << "\n";
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < b; j++)
            cout << s[a * k + i * b + j];
        cout << "\n";
    }

    return 0;
}
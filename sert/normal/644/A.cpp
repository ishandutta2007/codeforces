#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;

int n, k;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    /*for (int i = 0; i < 50; i++)
        for (int j = 0; j < 40; j++)
            cout << 50 + i << " " << 40 + j << "\n";
    return 0;*/
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < a; i++) {
        if (i % 2 == 0)
            for (int j = 0; j < b; j++)
                if (i * b + j < n)
                    cout << i * b + j + 1 << " ";
                else
                    cout << "0 ";
        else
            for (int j = b - 1; j >= 0; j--)
                if (i * b + j < n)
                    cout << i * b + j + 1 << " ";
                else
                    cout << "0 ";
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    vector <int> ans(n, 0);
    int sum1, sum2, sum3;
    cout << "? 1 2" << endl;
    cin >> sum1;
    cout << "? 2 3" << endl;
    cin >> sum2;
    cout << "? 1 3" << endl;
    cin >> sum3;
    int razn1 = sum2 - sum1;
    int razn2 = sum3 - sum1;
    c = (razn1 + razn2 + sum1) / 2;
    b = sum2 - c;
    a = sum3 - c;
    ans[0] = a;
    ans[1] = b;
    ans[2] = c;
    for (int i = 3; i < n; i++) {
        cout << "? 1 " << i + 1 << endl;
        int sum;
        cin >> sum;
        ans[i] = sum - a;
    }
    cout << "! ";
    for (int i = 0 ; i < n; i++) {
        cout << ans[i] << " ";
    }
}
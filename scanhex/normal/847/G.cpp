#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 0; i < a[0].length(); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += a[j][i] - '0';
        }
        mx = max(mx, cnt);
    }

    cout << mx << endl;

    return 0;
}
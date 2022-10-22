#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> data(n, 0), b(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        if (data[i] <= m) {
            b[data[i]]++;
        }
    }
    int num = n / m;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (b[i] >= num) continue;
        for (int j = 0; j < n; j++) {
            if (b[i] == num) break;
            if (data[j] > m || b[data[j]] > num) {
                if (data[j] <= m) b[data[j]]--;
                data[j] = i;
                b[i]++;
                cnt++;
            }
        }
    }
    cout << num << " " << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
}
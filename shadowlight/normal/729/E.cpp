#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, s;
    cin >> n >> s;
    int reserve = 0, errors = 0;
    vector <int> data;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i + 1 == s) {
            if (x != 0) {
                errors++;
            }
        } else if (x == 0) {
            reserve++;
            errors++;
        } else {
            data.push_back(x);
        }
    }
    sort(data.begin(), data.end());
    int now = 0;
    int i = 0;
    while (i < data.size()) {
        if (now + 1 >= data[i]) {
            now = data[i];
            i++;
            continue;
        }
        if (reserve) {
            reserve--;
            now++;
            continue;
        } else {
            errors++;
            data.pop_back();
            now++;
        }
    }
    cout << errors;
}
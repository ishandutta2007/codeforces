#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, a, b, k, cnt = 0;
    cin >> n >> a >> b >> k;
    vector <int> poses;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '1') {
            cnt = 0;
            continue;
        }
        cnt++;
        if (cnt == b) {
            poses.push_back(i + 1);
            cnt = 0;
        }
    }
    int x = poses.size();
    //cout << x << endl;
    cout << x - a + 1<< endl;
    for (int i = 0; i < x - a + 1; i++) {
        cout << poses[i] << " ";
    }
}
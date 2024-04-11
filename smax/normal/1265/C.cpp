#include <bits/stdc++.h>
using namespace std;

map<int, int, greater<int>> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cnt.clear();

        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            cnt[p]++;
        }

        int maxMedal = n / 2, g = 0, s = 0, b = 0;
        auto it = cnt.begin();
        while (true) {
            if (g == 0) {
                g += it->second;
                if (g + s + b > maxMedal) {
                    g -= it->second;
                    break;
                }
            } else if (s <= g) {
                s += it->second;
                if (g + s + b > maxMedal) {
                    s -= it->second;
                    break;
                }
            } else {
                b += it->second;
                if (g + s + b > maxMedal) {
                    b -= it->second;
                    break;
                }
            }
            it++;
        }

        if (g == 0 || s == 0 || b == 0 || b <= g)
            cout << "0 0 0\n";
        else
            cout << g << " " << s << " " << b << "\n";
    }

    return 0;
}
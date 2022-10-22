#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector <int> not_seen(n, 0);
    vector <int> deleted(n, -1);
    vector <int> all;
    int it = -1;
    for (int i = 0; i < m; i++) {
        int type, x;
        cin >> type >> x;
        x--;
        if (type == 1) {
            not_seen[x]++;
            sum++;
            all.push_back(x);
        } else if (type == 2) {
            sum -= not_seen[x];
            deleted[x] = all.size() - 1;
            not_seen[x] = 0;
        } else if (it < x) {
            int l = it + 1, r = x;
            for (int i = l; i <= r; i++) {
                if (deleted[all[i]] >= i) continue;
                not_seen[all[i]]--;
                sum--;
            }
            it = x;
        }
        cout << sum << endl;
    }
}
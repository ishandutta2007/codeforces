#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    unordered_map <long long, vector <long long> > comp_pos;
    vector <bool> nums(1000000, 0);
    vector <long long> poses(n + 1, 0);
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (comp_pos.find(x) == comp_pos.end()) {
            comp_pos[x] = vector <long long>(0);
        }
        comp_pos[x].push_back(i + 1);
        if (x <= 1e6) {
            nums[x] = 1;
        }
    }
    vector <pair <long long, long long> > rozets(m);
    for (long long i = 0; i < m; i++) {
        cin >> rozets[i].first;
        rozets[i].second = i + 1;
    }
    sort(rozets.begin(), rozets.end());
    vector <long long> glushs(m + 1, 0);
    long long sum = 0, cnt = 0;
    for (long long i = 0; i < m; i++) {
        long long x = rozets[i].first, u = rozets[i].second;
        while (x > 1) {
            if (x <= 1e6) {
                if (nums[x]) break;
            } else {
                if (comp_pos.find(x) != comp_pos.end()) break;
            }
            if (x % 2 == 1) {
                x++;
            }
            glushs[u]++;
            x /= 2;
        }
        if (x == 1) {
            if (comp_pos.find(x) == comp_pos.end()) x = 0;
        }
        if (x > 0) {
            poses[comp_pos[x].back()] = u;
            comp_pos[x].pop_back();
            if (comp_pos[x].size() == 0) {
                comp_pos.erase(x);
                if (x <= 1e6) {
                    nums[x] = 0;
                }
            }
            cnt++;
        } else {
            glushs[u] = 0;
        }
        sum += (long long) glushs[u];
    }
    cout << cnt << " " << sum << endl;
    for (long long i = 1; i <= m; i++) {
        cout << glushs[i] << " ";
    }
    cout << endl;
    for (long long j = 1; j <= n; j++) {
        cout << poses[j] << " ";
    }
}
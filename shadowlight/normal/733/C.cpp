#include <bits/stdc++.h>

using namespace std;

vector <int> sum;

int main() {
    int n;
    cin >> n;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int m;
    cin >> m;
    int now = 0, sum = 0;
    vector <int> last(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> last[i];
    }
    int maxk = 0, pos = 0;
    int st = 0, cnt = 0;
    bool fl = 1;
    int lpos = 0;
    vector <pair <int, char> > ans;
    for (int i = 0; i < n; i++) {
        sum += data[i];
        if (now == m) break;
        if (data[i] >= maxk) {
            if (data[i] == maxk) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxk = data[i];
            if (i != st && data[i - 1] < maxk) {
                pos = i;
            }
            lpos = i;
        }
        if (sum == last[now]) {
            if (cnt == 1 && i - st == 0) {
                st = i + 1;
                pos = st;
                maxk = 0;
                sum = 0;
                now++;
                continue;
            }
            if (cnt == i - st + 1) {
                cout << "NO";
                return 0;
            }
            if (lpos != i) {
                pos = lpos;
                for (int j = pos + 1; j <= i; j++) {
                    ans.push_back({pos - st + 1 + now, 'R'});
                }
                int ud = 0;
                for (int j = pos - 1; j >= st; j--) {
                    ans.push_back({pos - st - ud + now + 1, 'L'});
                    ud++;
                }
            } else {
                int ud = 0;
                for (int j = pos - 1; j >= st; j--) {
                    ans.push_back({pos - st - ud + now + 1, 'L'});
                    ud++;
                }
                for (int j = pos + 1; j <= i; j++) {
                    ans.push_back({now + 1, 'R'});
                }
            }
            st = i + 1;
            pos = st;
            maxk = 0;
            sum = 0;
            now++;
        } else if (sum > last[now]) {
            cout << "NO";
            return 0;
        }
    }
    if (sum != 0 || now != m) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
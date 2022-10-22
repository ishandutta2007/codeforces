#include <bits/stdc++.h>

using namespace std;

deque <int> conv(vector <int> a) {
    deque <int> b;
    for (int i = 0; i < a.size(); i++) {
        b.push_back(a[i]);
    }
    return b;
}

vector <int> conv(deque <int> a) {
    vector <int> b;
    while (!a.empty()) {
        b.push_back(a.front());
        a.pop_front();
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    vector <int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int len = sqrt(1e5);
    int now = 0;
    vector <vector <int> > cnt;
    vector <deque <int> > q;
    vector <pair <int, int> > seg;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (now == len || i == n - 1) {
            cnt.push_back(vector <int> (1e5 + 7, 0));
            q.push_back(deque <int>(0));
            for (int j = prev; j <= i; j++) {
                cnt.back()[data[j]]++;
                q.back().push_back(data[j]);
            }
            now = 0;
            seg.push_back({prev, i});
            prev = i + 1;
            continue;
        }
        now++;
    }
    int la = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l1, r1, k1 = 0;
        int id;
        cin >> id;
        cin >> l1 >> r1;
        if (id == 2) {
            cin >> k1;
        }
        int l, r, k;
        l = (l1 + la - 1) % n;
        r = (r1 + la - 1) % n;
        k = (k1 + la - 1) % n + 1;
        if (l > r) swap(l, r);
        int first = -1;
        int elem = 0;
        int ans = 0;
        int in_start;
        for (int j = 0; j < q.size(); j++) {
            int l2 = seg[j].first, r2 = seg[j].second;
            if (l2 <= l && r <= r2) {
                vector <int> mas = conv(q[j]);
                if (id == 2) {
                    for (int e = l - l2; e <= r - l2; e++) {
                        if (mas[e] == k) ans++;
                    }
                } else {
                    int last = mas[r - l2];
                    for (int e = r - l2; e >= l - l2 + 1; e--) {
                        mas[e] = mas[e - 1];
                    }
                    mas[l - l2] = last;
                }
                q[j] = conv(mas);
                break;
            }
            if (l2 <= l && l <= r2) {
                first = j;
                if (id == 1) {
                    elem = q[j].back();
                    cnt[j][elem]--;
                    q[j].pop_back();
                } else {
                    for (int e = l - l2; e < q[j].size(); e++) {
                        if (q[j][e] == k) ans++;
                    }
                }
                continue;
            }
            if (l2 <= r && r <= r2) {
                if (id == 1) {
                    in_start = q[j][r - l2];
                    cnt[j][in_start]--;
                    //q[j].erase(q[j].begin() + r - l2);
                    for (int e = r - l2; e < q[j].size() - 1; e++) {
                        q[j][e] = q[j][e + 1];
                    }
                    q[j].pop_back();
                    q[j].push_front(elem);
                    cnt[j][elem]++;
                } else {
                    for (int e = 0; e <= r - l2; e++) {
                        if (q[j][e] == k) ans++;
                    }
                }
                break;
            }
            if (l < l2 && r2 < r) {
                if (id == 1) {
                    q[j].push_front(elem);
                    cnt[j][elem]++;
                    elem = q[j].back();
                    cnt[j][elem]--;
                    q[j].pop_back();
                } else {
                    ans += cnt[j][k];
                }
                continue;
            }
        }
        if (id == 1 && first >= 0 && first < q.size()) {
            //q[first].insert(q[first].begin() + l - seg[first].first, in_start);
            q[first].push_back(0);
            for (int e = q[first].size() - 1; e > l - seg[first].first; e--) {
                q[first][e] = q[first][e - 1];
            }
            q[first][l - seg[first].first] = in_start;
            cnt[first][in_start]++;
        } else if (id == 2) {
            cout << ans << endl;
            la = ans;
        }
    }
    return 0;
}
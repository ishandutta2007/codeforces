#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <pair <pair <int, int>, pair <int, int> > > data(n);
    int maxc = 0, cnt = 1;
    pair <int, int> num;
    for (int i = 0; i < n; i++) {
        vector <int> p(3);
        cin >> p[0] >> p[1] >> p[2];
        sort(p.begin(), p.end());
        data[i] = {{p[1], p[2]}, {p[0], i + 1}};
        if (p[0] > maxc) {
            maxc = p[0];
            num.first = i + 1;
        }
    }
    sort(data.begin(), data.end());
    for (int i = 1; i < n; i++) {
        if (data[i].first == data[i - 1].first) {
            int x = min(data[i].first.first, data[i].second.first + data[i - 1].second.first);
            if (x > maxc) {
                cnt = 2;
                maxc = x;
                num.first = data[i].second.second;
                num.second = data[i - 1].second.second;
            }
        }
    }
    cout << cnt << endl;
    if (cnt == 2) {
        cout << num.first << " " << num.second;
    } else {
        cout << num.first;
    }
}
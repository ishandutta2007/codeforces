#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, long long>> stuff;
    vector<long long> huts(N), huts_acc(N+1);
    for (int i = 0; i < N; i++) {
        long long p;
        cin >> p;
        stuff.emplace_back(100*i, 1, p);
        huts[i] = p;
        huts_acc[i+1] = huts_acc[i] + huts[i];
    }
    vector<int> shops;
    for (int j = 0; j < M; j++) {
        int x;
        cin >> x;
        stuff.emplace_back(x, 0, 0ll);
        shops.emplace_back(x);
    }
    sort(shops.rbegin(), shops.rend());
    vector<int> shop_to_right(N);
    {
        int i = N-1;
        for (int j = 0; j < M; j++) {
            int curshop = shops[j];
            int nextshop = (j == M-1 ? (int) -2e9 : shops[j+1]);
            while (100*i > curshop) {
                shop_to_right[i] = 2e9;
                i--;
            }
            while (i >= 0 && 100*i > nextshop) {
                shop_to_right[i] = curshop;
                i--;
            }
        }
    }
    sort(stuff.begin(), stuff.end());
    int lastshop = -2e9;
    int hr = 0;
    long long ans = 0ll;
    for (auto [x, type, p] : stuff) {
        if (type == 0) {
            lastshop = x;
        } else if (x > lastshop) {
            int maxpos = min(x + (x - lastshop), shop_to_right[x/100] - 1);
            int maxright = shop_to_right[x/100];
            //cout << maxpos << " " << maxright << "\n";
            while (hr < N && hr*100 < maxpos) {
                hr++;
            }
            while (hr < N && hr*100 < maxright && shop_to_right[hr] - hr*100 > hr*100 - maxpos) {
                hr++;
            }
            //cout << x << " " << huts_acc[hr] - huts_acc[x / 100] << endl;
            ans = max(ans, huts_acc[hr] - huts_acc[x / 100]);
        }
    }
    cout << ans << endl;
}
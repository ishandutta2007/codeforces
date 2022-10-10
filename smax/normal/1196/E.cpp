#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int b, w;
        cin >> b >> w;

//        if (abs(b - w) > 5) {
//            cout << "NO\n";
//        } else {
//            cout << "YES\n";
        vector<pair<int, int>> v;
            if (b > w) {
                int extra = 1;
                for (int i=1; i<=w; i++) {
//                    cout << 2*i << " 2\n" << 2*i+1 << " 2\n";
                    v.emplace_back(2*i, 2);
                    v.emplace_back(2*i+1, 2);
                    extra += 2;
                }
                int diff = b - w;
                if (diff > extra) {
                    cout << "NO\n";
                    continue;
                }
                if (diff > 0)
                v.emplace_back(1, 2);
                diff--;

                int i = 0;
                while (diff > 0) {
                    v.emplace_back(v[i].first, 1);
                    diff--;
                    if (diff == 0)
                        break;
                    v.emplace_back(v[i].first, 3);
                    diff--;
                    i+=2;
                }
//                cout << "2 1\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "1 2\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "2 3\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "4 1\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "4 3\n";
//                diff--;
            } else {
                int extra = 1;
                for (int i=1; i<=b; i++) {
//                    cout << 2*i+1 << " 2\n" << 2*i+2 << " 2\n";
                    v.emplace_back(2*i+1, 2);
                    v.emplace_back(2*i+2, 2);
                    extra += 2;
                }
                int diff = w - b;
                if (diff > extra) {
                    cout << "NO\n";
                    continue;
                }
                if (diff > 0)
                v.emplace_back(2, 2);
                diff--;
//                cout << "3 1\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "2 2\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "3 3\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "5 1\n";
//                diff--;
//                if (diff == 0)
//                    continue;
//                cout << "5 3\n";
//                diff--;
                int i = 0;
                while (diff > 0) {
                    v.emplace_back(v[i].first, 1);
                    diff--;
                    if (diff == 0)
                        break;
                    v.emplace_back(v[i].first, 3);
                    diff--;
                    i+=2;
                }
            }

        cout << "YES\n";
        for (auto p : v)
            cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
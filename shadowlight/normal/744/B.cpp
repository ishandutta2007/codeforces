#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int x = 1;
    int now = 0;
    bool fl = 0;
    vector <vector <int> > data, d;
    while (x < n) {
        now = 0;
        fl = 1;
        vector <int> d1, d2;
        vector <int> p(n, 0);
        for (int i = 0; i < n; i++) {
            if (fl) {
                d1.push_back(i + 1);
                p[i] = 1;
            } else {
                d2.push_back(i + 1);
            }
            now++;
            if (now == x) {
                fl ^= 1;
                now = 0;
            }
        }
        cout << d1.size() << endl;
        for (int i = 0; i < d1.size(); i++) {
            cout << d1[i] << " ";
        }
        cout << endl;
        data.push_back(vector <int> (n));
        for (int i = 0; i < n; i++) {
            cin >> data.back()[i];
        }
        cout << d2.size() << endl;
        for (int i = 0; i < d2.size(); i++) {
            cout << d2[i] << " ";
        }
        cout << endl;
        data.push_back(vector <int> (n));
        for (int i = 0; i < n; i++) {
            cin >> (data.back())[i];
        }
        d.push_back(vector <int>(0));
        d.back() = d1;
        d.push_back(vector <int>(0));
        d.back() = d2;
        x *= 2;
    }
    cout << -1 << endl;
    for (int i = 0; i < n; i++) {
        int mink = INF;
        for (int j = 0; j < data.size(); j++) {
            bool fl1 = 0;
            for (int k = 0; k < d[j].size(); k++) {
                //cout << d[j][k] << " ";
                if (d[j][k] == i + 1) {
                    fl1 = 1;
                    break;
                }
            }
            //cout << endl;
            if (!fl1) {
                //cout << data[j][i] << endl;
                //cout << "kek" << endl;
                mink = min(mink, data[j][i]);
            }
        }
        cout << mink << " ";
    }
    cout << endl;
}
/*
3
0 5 0
3 0 8
0 0 4
2 7 0
*/
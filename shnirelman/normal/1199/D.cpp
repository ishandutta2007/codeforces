#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i< n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b;
    vector<pair<int, int>> upd(n);
    for(int i = 0; i < n; i++) {
        upd[i] = {0, i};
        //cout << i << ' ' << upd[i].first << ' ' << upd[i].second << endl;
    }


    for(int i = 0; i < m; i++) {
        int beh;
        cin >> beh;

        if(beh == 1) {
            int ind, x;
            cin >> ind >> x;

            ind--;

            a[ind] = x;
            upd[ind].first = b.size();
        } else {
            int x;
            cin >> x;
            b.push_back(x);
        }
    }

    sort(upd.begin(), upd.end());

    int mx = -1;
    int j = b.size() - 1;
    for(int i = n - 1; i >= 0; i--) {
        //cout << i << ' ' << j << ' ' << upd[i].second << endl;
        for(; j >= upd[i].first; j--)
            mx = max(mx, b[j]);
//cout << i << ' ' << j << endl;
        int ind = upd[i].second;
        //cout << ind << endl;
        a[ind] = max(a[ind], mx);
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
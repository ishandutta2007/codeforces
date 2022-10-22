#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<pair<long long,int>> s;
    vector<pair<long long,int>> t;
    cin >> n;
    long long bu;
    long long sums = 0;
    long long sumt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> bu;
        sums += bu;
        s.push_back(pair<long long,int>(bu,i));
    }
    for (int i = 1; i <= n; i++) {
        cin >> bu;
        sumt += bu;
        t.push_back(pair<long long,int>(bu,i));
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (sums != sumt || s[0].first > t[0].first) {
        cout << "NO" << endl;
        return 0;
    }
    int m = 0;
    vector<int> ansi;
    vector<int> ansj;
    vector<int> ansd;
    int curt, curs1, curs2;
    curs1 = 0;
    curs2 = 1;
    curt = 0;
    vector<bool> placed(n, false);
    long long curd;
    while (curt < n) {
        if (s[curs1].first > t[curt].first) {
            cout << "NO" << endl;
            return 0;
        }
        while (s[curs2].first < t[curt].first || placed[curs2]) {
            curs2++;
        }
        curd = min(s[curs2].first-t[curt].first, t[curt].first-s[curs1].first);
        if (curd > 0) {
            m++;
            ansi.push_back(s[curs1].second);
            ansj.push_back(s[curs2].second);
            ansd.push_back(curd);
        //cout << ansi[m-1] << " " << ansj[m-1] << " " << ansd[m-1] << endl;
            s[curs1].first += curd;
            s[curs2].first -= curd;
        }
        if (s[curs1].first == t[curt].first) {
            placed[curs1] = true;
        }
        else {
            placed[curs2] = true;
        }
        curt++;
        while (placed[curs1])
            curs1++;
    }
    cout << "YES" << endl;
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ansi[i] << " " << ansj[i] << " " << ansd[i] << endl;
    }
    return 0;
}
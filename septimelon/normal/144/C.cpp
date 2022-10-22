#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

void lmin(int& x, int& y) {
    if (x > y) {
        swap(x, y);
    }
}

int sdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, p;
    cin >> s >> p;
    set<int> over;
    vector<int> cous(27, 0);
    vector<int> coup(27, 0);
    if (p.size() > s.size()) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < p.size(); ++i) {
        ++coup[p[i] - 'a'];
    }
    for (int i = 0; i < p.size(); ++i) {
        if (s[i] != '?') {
            ++cous[s[i] - 'a'];
            if (cous[s[i] - 'a'] > coup[s[i] - 'a']) {
                over.insert(s[i] - 'a');
            }
        }
    }
    int cl = 0;
    int ans = (over.empty() ? 1 : 0);
    for (int i = p.size(); i < s.size(); ++i) {
        if (s[i] != '?') {
            ++cous[s[i] - 'a'];
            if (cous[s[i] - 'a'] > coup[s[i] - 'a']) {
                over.insert(s[i] - 'a');
            }
        }
        if (s[cl] != '?') {
            --cous[s[cl] - 'a'];
            if (cous[s[cl] - 'a'] == coup[s[cl] - 'a']) {
                over.erase(s[cl] - 'a');
            }
        }
        ++cl;
        ans += (over.empty() ? 1 : 0);
    }
    cout << ans << '\n';

    return 0;
}
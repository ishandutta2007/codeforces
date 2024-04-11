#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

bool isSuf(string s, string t) {
    if (s.size() > t.size()) {
        return false;
    }
    for (int i = (int) s.size() - 1, j = (int) t.size() - 1; i >= 0; i--, j--) {
        //cout << s[i] << " " << t[j] << "\n";
        if (s[i] != t[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    map <string, set <string> > data;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string num;
            cin >> num;
            vector <string> er;
            bool fl = 0;
            for (string t : data[s]) {
                //cout << num << " " << t << " " << isSuf(num, t) << "\n";
                if (isSuf(t, num)) {
                    er.push_back(t);
                } else if (isSuf(num, t)) {
                    fl = true;
                    break;
                }
            }
            if (!fl) {
                for (auto t : er) {
                    data[s].erase(t);
                }
                data[s].insert(num);
            }
        }
    }
    cout << data.size() << "\n";
    for (auto p : data) {
        cout << p.first << " " << p.second.size() << " ";
        for (auto x : p.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
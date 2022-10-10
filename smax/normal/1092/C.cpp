#include <bits/stdc++.h>
using namespace std;

int n;
char ret[200];
pair<string, int> s[200];

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.first.length() < b.first.length();
}

bool check(string pref, string suff) {
    vector<bool> mark(n);
    for (int i=0; i<pref.length(); i++) {
        string str = pref.substr(0, i + 1);
        if (s[2*i].first == str)
            mark[2*i] = true;
        else if (s[2*i+1].first == str)
            mark[2*i+1] = true;
        else
            return false;
    }
    for (int i=0; i<suff.length(); i++) {
        string str = suff.substr(suff.length() - i - 1, i + 1);
        if (s[2*i].first == str && !mark[2*i])
            mark[2*i] = true;
        else if (s[2*i+1].first == str && !mark[2*i+1])
            mark[2*i+1] = true;
        else
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    n = 2 * n - 2;
    for (int i=0; i<n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }

    sort(s, s + n, cmp);
    string pref, suff;
    if (check(s[n-1].first, s[n-2].first))
        pref = s[n-1].first, suff = s[n-2].first;
    else
        pref = s[n-2].first, suff = s[n-1].first;

    for (int i=0; i<n; i+=2) {
        if (s[i].first == pref.substr(0, i / 2 + 1))
            ret[s[i].second] = 'P', ret[s[i+1].second] = 'S';
        else
            ret[s[i].second] = 'S', ret[s[i+1].second] = 'P';
    }

    for (int i=0; i<n; i++)
        cout << ret[i];
    cout << "\n";

    return 0;
}
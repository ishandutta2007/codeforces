#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()

set<int> alive;

int getNext(int x) {
    auto it = alive.upper_bound(x);
    return it == alive.end() ? -1 : *it;
}

int getPrev(int x) {
    auto it = alive.find(x);
    return it == alive.begin() ? -1 : *prev(it);
}

string s;

set<int> toKill;

void check(int x) {
    if (getNext(x) != -1 && s[getNext(x)] != s[x]) toKill.insert(x);
    if (getPrev(x) != -1 && s[getPrev(x)] != s[x]) toKill.insert(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < sz(s); ++i) alive.insert(i);
    for (int i = 0; i < sz(s); ++i) check(i);
    int ans = 0;
    while (!toKill.empty()) {
        set<int> toCheck;
        ++ans;
        for (auto e : toKill) {
            if (getNext(e) != -1) toCheck.insert(getNext(e));
            if (getPrev(e) != -1) toCheck.insert(getPrev(e));
        }
        for (auto e : toKill) alive.erase(e);
        toKill.clear();
        for (auto e : toCheck) {
            if (alive.count(e)) check(e);
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int A[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    int len = 1, turns = 0;
    set<pair<int, int>> nxt, segs;
    for(int i = 1; i < n; i++) {
        if(A[i] == A[i + 1])
            len++;
        else {
            nxt.insert({-len, i - len + 1});
            segs.insert({i - len + 1, len});
            len = 1;
        }
    }
    nxt.insert({-len, n - len + 1});
    segs.insert({n - len + 1, len});
    while(!nxt.empty()) {
        turns++;
        pair<int, int> p = *(nxt.begin()), op = {p.second, -p.first};
        nxt.erase(p);
        segs.erase(op);
        if(segs.size() <= 1)
            continue;
        auto it = segs.upper_bound(op);
        if(it == segs.end() || it == segs.begin())
            continue;
        pair<int, int> p1 = *(it--), p2 = *it;
        if(A[p1.first] == A[p2.first]) {
            pair<int, int> p3 = {p2.first, p1.second + p2.second};
            segs.erase(p1);
            segs.erase(p2);
            segs.insert(p3);
            nxt.erase(make_pair(-p1.second, p1.first));
            nxt.erase(make_pair(-p2.second, p2.first));
            nxt.insert(make_pair(-p3.second, p3.first));
        }
    }
    cout << turns << endl;
}
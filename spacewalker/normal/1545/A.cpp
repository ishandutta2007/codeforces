#include <bits/stdc++.h>

using namespace std;

pair<map<int, int>, map<int, int>> seqHash(vector<int> &s) {
    map<int, int> odds, evens;
    for (int i = 0; i < s.size(); ++i) {
        (i % 2 == 0 ? evens : odds)[s[i]]++;
    }
    return make_pair(evens, odds);
}

bool solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<int> sarr = arr;
    sort(begin(sarr), end(sarr));
    return seqHash(arr) == seqHash(sarr);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES" : "NO");
}
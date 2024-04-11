#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void solve() {
    int n; scanf("%d", &n);
    vector<int> genre(n);
    for (int i = 0; i < n; ++i) scanf("%d", &genre[i]);
    set<int> notDeleted;
    for (int i = 0; i < n; ++i) notDeleted.insert(i);
    auto getNextSong = [&] (int i) {
        if (i < *notDeleted.rbegin()) return *notDeleted.upper_bound(i);
        else return *notDeleted.begin();
    };
    set<int> potentialBreaks;
    auto moveToBreak = [&] (int i) {
        if (i <= *potentialBreaks.rbegin()) return *potentialBreaks.lower_bound(i);
        else return *potentialBreaks.begin();
    };
    for (int i = 0; i < n; ++i) if (gcd(genre[i], genre[(i+1) % n]) == 1) potentialBreaks.insert(i);
//    for (int v : potentialBreaks) printf("%d is break\n", v);
    vector<int> ans;
    for (int iter = 0, cbreak = 0; potentialBreaks.size() > 0; ++iter) {
        cbreak = moveToBreak(cbreak);
        int nextSong = getNextSong(cbreak);
//        printf("iter %d cb %d next %d\n", iter, cbreak, nextSong);
        if (gcd(genre[cbreak], genre[nextSong]) == 1) {
            notDeleted.erase(nextSong);
            potentialBreaks.erase(nextSong);
            ans.push_back(nextSong);
//            printf("deleted %d\n", nextSong);
        } else {
//            printf("%d not break\n", cbreak);
            potentialBreaks.erase(cbreak);
        } 
        if (potentialBreaks.size() > 0) cbreak = getNextSong(cbreak);
//        printf("> moved cb to %d\n", cbreak);
    }
    printf("%lu", ans.size());
    for (int v : ans) printf(" %d", v + 1);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}
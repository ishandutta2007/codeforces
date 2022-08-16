#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

set<int> points;
multiset<int> gaps;

void insert(int pos) {
    if (points.size() == 0) {
        points.insert(pos);
        return;
    }
    auto rit = points.upper_bound(pos);
    auto lit = rit; --lit;
    if (rit == points.end()) {
        gaps.insert(pos-*lit);
    } else if (rit == points.begin()) {
        gaps.insert(*rit-pos);
    } else {
        gaps.erase(gaps.find(*rit-*lit));
        gaps.insert(pos-*lit);
        gaps.insert(*rit-pos);
    }
    points.insert(pos);
}

void remove(int pos) {
    if (points.size() == 1) {
        points.erase(pos);
        return;
    }
    auto rit = points.upper_bound(pos);
    auto lit = rit; --lit;
    if (rit == points.end()) {
        --lit;
        gaps.erase(gaps.find(pos-*lit));
    } else if (lit == points.begin()) {
        gaps.erase(gaps.find(*rit-pos));
    } else {
        --lit;
        gaps.erase(gaps.find(pos-*lit));
        gaps.erase(gaps.find(*rit-pos));
        gaps.insert(*rit-*lit);
    }
    points.erase(pos);
}

int solve() {
    if (points.size() <= 2)
        return 0;
    int mn = *points.begin();
    int mx = *points.rbegin();
    int mxGap = *gaps.rbegin();
    return mx - mn - mxGap;
}

int main() {
    setIO();
    int n, q;
    cin>>n>>q;
    while (n--) {
        int x; cin>>x;
        insert(x);
    }

    cout<<solve()<<"\n";
    while (q--) {
        int op, x; cin>>op>>x;
        if (op) insert(x);
        else remove(x);
        cout<<solve()<<"\n";
    }
    
    return 0;
}
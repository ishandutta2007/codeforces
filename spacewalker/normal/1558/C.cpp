/*
n n-1

X X X n-1 n X X X

mula sa magkatabi:

 S N S N S N   (2)
 |   |   |
X 6 7 X X X X
7 6 X X X X X
X X X X X 6 7

OR

 S N S N S N   (3)
 |   |   |
X X 7 6 X X X
X X X 6 7 X X
proceed as in above


X 6 X X 7 X X
7 X X 6 X X X
X X 7 6 X X X proceed as in x3 swap case

X X 7 X X 6 X
7 X X X X 6 X
X X X X 7 6 X proceed as in x3 swap case
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < n; ++i) --arr[i];
    auto indexOf = [&] (int i) {
        for (int k = 0; k < n; ++k) if (arr[k] == i) return k;
        return -1;
    };
    for (int i = 0; i < n; ++i) {
        if (indexOf(i) % 2 != i % 2) {
            printf("-1\n");
            return;
        }
    }
    vector<int> ans;
    auto operate = [&] (int v) {
        assert(v % 2 == 1);
        reverse(begin(arr), begin(arr) + v);
        ans.push_back(v);
    };
    for (int remElem = n; remElem > 1; remElem -= 2) {
        int th = remElem - 1, th2 = remElem - 2;
        int thpos = indexOf(th), th2pos = indexOf(th2);
        auto updatePositions = [&] () {
            thpos = indexOf(th), th2pos = indexOf(th2);
        };
        operate(thpos + 1);
        updatePositions();
        operate(th2pos);
        updatePositions();
        operate(remElem); // 2nd phase
        updatePositions();
        operate(thpos + 1);
        updatePositions();
        operate(remElem);
        updatePositions();
    }
    printf("%lu\n", ans.size());
    for(int v : ans) printf(" %d", v);
    printf("\n");
    for (int i = 0; i < n; ++i) assert(arr[i] == i);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}
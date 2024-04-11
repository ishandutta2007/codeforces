#include <bits/stdc++.h> 

using namespace std;

int k;

int edgeColor(int i, int j) {
    if (i == j) return 0;
    else return 1 + edgeColor(i / k, j / k);
}

int main() {
    int n; scanf("%d %d", &n, &k);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans.push_back(edgeColor(i, j));
        }
    }
    set<int> s(begin(ans), end(ans));
    printf("%lu\n", s.size());
    for (int v : ans) printf("%d ", v);
    printf("\n");
}
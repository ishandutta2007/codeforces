#include <bits/stdc++.h>
using namespace std;

string s[200000];
unordered_map<string, int> encode;

int parent[200026], Rank[200026];

int Find(int k) {
    // if k is not the root
    if (parent[k] != k)
        parent[k] = Find(parent[k]);

    // recurse for parent to find root
    return parent[k];
}

void Union(int a, int b) {
    // find roots of the sets in which elements a and b belong in
    int x = Find(a), y = Find(b);

    // if x and y are in the same set
    if (x == y)
        return;

    // always attach smaller depth tree under root of deeper tree
    if (Rank[x] > Rank[y])
        parent[y] = x;
    else if (Rank[x] < Rank[y])
        parent[x] = y;
    else {
        parent[x] = y;
        Rank[y]++;
    }
}

unordered_set<int> components;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i=0; i<26; i++) {
        parent[200000+i] = 200000 + i;
        Rank[200000+i] = 0;
    }

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        encode[s[i]] = i;
        parent[i] = i;
        Rank[i] = 0;
        for (char c : s[i])
            Union(i, 200000 + c - 'a');
    }

    for (int i=0; i<n; i++)
        components.insert(Find(i));

    cout << components.size() << "\n";

    return 0;
}
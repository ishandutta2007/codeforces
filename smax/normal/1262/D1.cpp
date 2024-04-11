#include <bits/stdc++.h>
using namespace std;

int n, BIT[200001] = {};

int getSum(int index) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += BIT[index];
        index -= index & (-index);
    }
    return sum;
}

void update(int index, int val) {
    index++;
    while (index <= n) {
        BIT[index] += val;
        index += index & (-index);
    }
}

int kthElement(int k) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (k <= getSum(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int ret[200000], orig[200000];
pair<int, int> a[200000];
pair<pair<int, int>, int> queries[200000];
//vector<pair<int, int>> subsequence;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        orig[i] = a[i].first;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    sort(a, a + n, cmp);
    sort(queries, queries + m);

    int j = 0;
    for (int i=0; i<n; i++) {
//        subsequence.push_back(a[i]);
//        sort(subsequence.begin(), subsequence.end(), cmp2);
        update(a[i].second, 1);
        while (j < m && queries[j].first.first == i + 1) {
            ret[queries[j].second] = orig[kthElement(queries[j].first.second)];
            j++;
        }
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}
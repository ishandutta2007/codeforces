#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;


class suffix_array {
    static bool compare_sa(int n, const vector<int>& rank, int i, int j, int d) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        return rank[i ^ d] < rank[j ^ d];
    }
public:
    static vector<int> construct_sa(const string& s) {
        int n = s.size();
        vector<int> sa(n + 1), rank(n + 1);
        for (int i = 0; i <= n; ++i) {
            sa[i] = i;
            rank[i] = i < n ? s[i] : -1;
        }
        for (int k = 1; k < n; k <<= 1) {
            sort(sa.begin(), sa.end(), [&n, &k, &rank](const int& a, const int& b){ return compare_sa(n, rank, a, b, k); });

            vector<int> tmp(n + 1);
            for (int i = 1; i <= n; ++i)
                tmp[sa[i]] = tmp[sa[i - 1]] + compare_sa(n, rank, sa[i - 1], sa[i], k);
            for (int i = 0; i <= n; ++i)
                rank[i] = tmp[i];
        }
        return sa;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;
    n = 1 << n;
    vector<int> sa = suffix_array::construct_sa(s);
    int k = sa[1];
    for (int i = 0; i < n; ++i) {
        cout << s[i ^ k];
    }
    cout << '\n';


    return 0;
}
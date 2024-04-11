#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include "queue"
#include <climits>
#define all(x) (x).begin(), (x).end()
using namespace std;
vector<int> perm(vector<int> a, vector<int> b) {
    vector<int> c(b.size());
    for (int i = 0; i < b.size(); ++i) {
        c[b[i]] = a[i];
    }
    return c;
}
vector<vector<int>> permspeedup;
map<vector<int>, int> permind;
map<int, vector<int>> permfromind;
int sz = 0;
void makepermind(int k) {
    sz = 1;
    for (int i = 2; i <= k; ++i) {
        sz *= i;
    }
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        a[i] = i;
    }
    int t = 0;
    do {
        permfromind[t] = a;
        permind[a] = t++;
    } while (next_permutation(all(a)));
    permspeedup.assign(sz, vector<int>(sz));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            permspeedup[i][j] = permind[perm(permfromind[i], permfromind[j])];
        }
    }
}
struct snm {
    vector<int> parent, rank, sizeik;
    void make(int szz) {
        parent.assign(szz, 0);
        sizeik.assign(szz, 1);
        rank.assign(szz, 0);
        for (int i = 0; i < szz; ++i) {
            parent[i] = i;
        }
    }
    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }

    bool union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap (a, b);
            parent[b] = a;
            sizeik[a] += sizeik[b];
            if (rank[a] == rank[b])
                ++rank[a];
            return 1;
        }
        return 0;
    }
};
int acc(snm sn) {
    return sn.sizeik[sn.find_set(0)];
}
bool addperm(int prm, snm &sn) {
    bool ch = 0;
    if (sn.find_set(prm) == sn.find_set(0))
       return 0;
    for (int i = 0; i < sz; ++i) {
        int v = permspeedup[i][prm];
        ch |= sn.union_sets(i, v);
    }
    return ch;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    makepermind(k);
    vector<vector<int>> prm(n, vector<int>(k));
    vector<int> prnums(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> prm[i][j];
            prm[i][j]--;
        }
        prnums[i] = permind[prm[i]];
    }
    vector<vector<long long>> changeme(n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        snm sn;
        sn.make(sz);
        addperm(prnums[i], sn);
        changeme[i].push_back(i);
        vector<int> val;
        val.push_back(acc(sn));
        int r1 = res;
        //res += val[0];
        if (i != 0) {
            for (auto j : changeme[i - 1]) {
                if (addperm(prnums[j], sn)) {
                    changeme[i].push_back(j);
                    val.push_back(acc(sn));
                }
            }
        }
        if (changeme[i].size() > 6)
            return 1;
        for (int t = 0; t + 1 < changeme[i].size(); ++t) {
            res += val[t] * (changeme[i][t] - changeme[i][t + 1]);
        }
        res += val.back() * (changeme[i].back() + 1);
        //cout << res - r1 << endl;
    }
    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r){
        return read(r) - read(l-1);
    }
};

const int MAXN = 1e5 + 100;

int N;
vector<int> vals;
vector<int> times[MAXN];

int type[MAXN], when[MAXN], val[MAXN];

void clean(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int index(vector<int> &v, int val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> type[i] >> when[i] >> val[i];
        vals.push_back(val[i]);
    }

    clean(vals);

    for (int i = 0; i < N; i++) {
        times[index(vals, val[i])].push_back(when[i]);
    }

    vector<BIT<int>> trees;

    for (int i = 0; i < vals.size(); i++) {
        clean(times[i]);
        trees.emplace_back(times[i].size());
    }

    for (int i = 0; i < N; i++) {
        int vinx = index(vals, val[i]);
        int tinx = index(times[vinx], when[i]);

        if (type[i] == 1) {
            trees[vinx].update(tinx, 1);
        } else if (type[i] == 2) {
            trees[vinx].update(tinx, -1);
        } else {
            cout << trees[vinx].read(tinx) << "\n";
        }
    }

    return 0;
}
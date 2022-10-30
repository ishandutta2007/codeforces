
#include <bits/stdc++.h>
using namespace std;

void add_swap(vector<long long> &v, vector<long long> &loc, vector<pair<long long, long long>> &swaps, long long i, long long j){
    swaps.push_back({i + 1, j + 1});
    loc[v[i]] = j; loc[v[j]] = i;
    swap(v[i], v[j]);
}

int main(){
    long long n;
    cin >> n;
    vector<long long> v(n), loc(n);
    for (long long i = 0; i < n; ++i){
        long long x;
        cin >> x;
        --x;
        v[i] = x;
        loc[x] = i;
    }

    vector<pair<long long, long long>> swaps;
    for (long long i = n / 2; i < n - 1; ++i){
        long long j = loc[i];
        if (j < n / 2){
            add_swap(v, loc, swaps, j, n - 1);
            add_swap(v, loc, swaps, 0, n - 1);
            add_swap(v, loc, swaps, 0, i);
        }
        else{
            add_swap(v, loc, swaps, 0, j);
            add_swap(v, loc, swaps, 0, i);
        }
    }
    for (long long i = 1; i < n / 2; ++i){
        long long j = loc[i];
        if (j < n / 2){
            add_swap(v, loc, swaps, j, n - 1);
            add_swap(v, loc, swaps, i, n - 1);
        }
        else{
            add_swap(v, loc, swaps, 0, j);
            add_swap(v, loc, swaps, 0, n - 1);
            add_swap(v, loc, swaps, i, n - 1);
        }
    }
    if (v[0] != 0) add_swap(v, loc, swaps, 0, n - 1);

    cout << swaps.size() << endl;
    for (pair<long long, long long> &p : swaps) cout << p.first << ' ' << p.second << endl;

    return 0;
}
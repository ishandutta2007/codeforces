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

const int MAXN = 1e6 + 100;

BIT<int> elt(MAXN);
bool pres[MAXN];
int value[MAXN];

int N, M, P, T, V;

void rem(int idx) {
    int loc = -1;
    int lo = 0, hi = T;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        if (elt.read(mi) > idx) {
            loc = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    pres[loc] = false;
    elt.update(loc, -1);
    P--;
}

vector<int> idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;
    idx.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> idx[i];
        idx[i]--;
    }

    for (int i = 0; i < N; i++) {
        cin >> V;

        if (V == -1) {
            auto it = lower_bound(idx.begin(), idx.end(), P);

            while (it != idx.begin()) {
                it = prev(it);
                rem(*it);
            }
        } else {
            value[T] = V;
            pres[T] = true;
            elt.update(T, 1);
            T++;
            P++;
        }
    }

    vector<int> res;

    for (int i = 0; i < MAXN; i++) 
        if (pres[i])
            res.push_back(value[i]);

    if (!res.size()) cout << "Poor stack!\n";
    else {
        for (int v : res)
            cout << v;
        cout << "\n";
    }
}
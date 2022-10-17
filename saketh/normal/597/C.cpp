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

int N, K;
int val[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;
    K++;

    for (int i = 0; i < N; i++) 
        cin >> val[i];

    vector<BIT<ll>> ways(K + 1, BIT<ll>(MAXN));

    ways[0].update(0, 1);

    for (int i = 0; i < N; i++) {
        for (int l = 1; l <= K; l++) {
            ways[l].update(val[i], ways[l-1].read(val[i] - 1));
        }
    }

    cout << ways[K].read(MAXN - 1) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const int MAXV = 1e6 + 100;

int N, M, P, L, C;
int ans[MAXN];
vector<int> sp[MAXV];
vector<pair<int, int>> qq[MAXV];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        sp[r].push_back(l);
    }

    for (int i = 0; i < M; i++) {
        L = -1;

        cin >> P;
        for (int j = 0; j < P; j++) {
            cin >> C;            
            if (C - 1 >= L + 1)
                qq[C-1].emplace_back(L+1, i);
            L = C;
        }

        qq[MAXV-1].emplace_back(L+1, i);
    }

    BIT<int> spc(MAXV);

    for (int ep = 0; ep < MAXV; ep++) {
        for (int sv : sp[ep]) {
            spc.update(sv, 1);
        }
        
        for (auto p : qq[ep]) {
            ans[p.second] += spc.read(p.first, ep);
        }
    }

    for (int i = 0; i < M; i++) 
        cout << N - ans[i] << "\n";
}
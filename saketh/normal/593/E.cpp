#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T> struct matrix {
    int N;
    vector<T> dat;

    matrix<T> (int _N, T fill = T(0), T diag = T(0)) {
        N = _N;
        dat.resize(N * N, fill);

        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        return dat[N * i + j];
    }

    matrix<T> operator *(matrix<T> &b){
        matrix<T> r(N);

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<N; k++)
                    r(i, j) = r(i, j) + (*this)(i, k) * b(k, j);

        return r;
    }

    matrix<T> pow(ll expo){
        if(!expo) return matrix<T>(N, T(0), T(1));
        matrix<T> r = (*this * *this).pow(expo/2);
        return expo&1 ? r * *this : r;
    }

    friend ostream& operator<<(ostream &os, matrix<T> &m){
        os << "{";
        for(int i=0; i<m.N; i++){
            if(i) os << "},\n ";
            os << "{";
            for(int j=0; j<m.N; j++){
                if(j) os << ", ";
                os << setw(10) << m(i, j) << setw(0);
            }
        }
        return os << "}}";
    }
};


struct mll {
    static const int MOD = 1e9 + 7;

    int val;
    mll(int _val = 0) {
        val = _val % MOD;
        if (val < 0) val += MOD;
    }

    mll operator+(const mll &o) {
        return mll((val + o.val) % MOD);
    }

    mll operator*(const mll &o) {
        return mll((val * 1ll * o.val) % MOD);
    }

    friend ostream& operator<<(ostream &os, mll &m) {
        return os << m.val;
    }
};

int N, M, Q;
bool cat[20][20];

int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool go(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M) return false;
    return !cat[i][j];
}

void advance(matrix<mll> &cur, int steps) {
    matrix<mll> mul(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!go(i, j)) continue;
            for (int d = 0; d < 5; d++) {
                int ii = i + dir[d][0];
                int jj = j + dir[d][1];

                if (!go(ii, jj)) continue;
                mul(i * M + j, ii * M + jj) = mll(1);
            }
        }
    }

    mul = mul.pow(steps);
    cur = cur * mul;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> Q;

    matrix<mll> ans(N * M, mll(0), mll(1));

    int CT = 1;

    int T, X, Y, TM;
    for (int i = 0; i < Q; i++) {
        cin >> T >> X >> Y >> TM;
        X--, Y--;

        // now handle the query
        if (T == 1) {
            advance(ans, TM - CT);
            cout << ans(0, X * M + Y) << "\n";
            CT = TM;
        } else {
            advance(ans, TM - CT);
            if (T == 2) cat[X][Y] = true;
            else cat[X][Y] = false;
            CT = TM;
        }
    }
}
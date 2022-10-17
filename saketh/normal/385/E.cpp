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

int MOD;
struct mll {
    ll val;

    mll(ll _val = 0) {
        val = _val % MOD;
        if (val < 0) val += MOD;
    }

    mll operator+(const mll &o) {
        return mll((val + o.val) % MOD);
    }

    mll operator*(const mll &o) {
        return mll((val * o.val) % MOD);
    }

    friend ostream& operator<<(ostream &os, mll &m) {
        return os << m.val;
    }
};

int N, SX, SY, DX, DY;
ll T;

int mat[6][6] = {{2, 1, 1, 0, 1, 2},
                 {1, 2, 0, 1, 1, 2},
                 {1, 1, 1, 0, 1, 2},
                 {1, 1, 0, 1, 1, 2},
                 {0, 0, 0, 0, 1, 1},
                 {0, 0, 0, 0, 0, 1}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> SX >> SY >> DX >> DY >> T;
    SX--, SY--;
    MOD = N;

    matrix<mll> m(6);

    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < 6; j++) 
            m(i, j) = mll(mat[i][j]);

    m = m.pow(T);

    mll vec[6] = {SX, SY, DX, DY, 0, 1};

    mll X = 0, Y = 0;

    for (int i = 0; i < 6; i++) {
        X = X + vec[i] * m(0, i);
        Y = Y + vec[i] * m(1, i);
    }

    cout << X.val + 1 << " " << Y.val + 1 << "\n";
}
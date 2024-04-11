#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 305;

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
        matrix<T> r(N, 0);

        for(int i=0; i<N; i++)
            for(int j=i; j<N; j++)
                for(int k=i; k<=j; k++)
                    r(i, j) = max(r(i, j), (*this)(i, k) + b(k, j));

        for (int i = N - 1; i >= 0; i--) {
            for (int j = i; j < N; j++) {
                if (j > i) r(i, j) = max(r(i, j), r(i, j-1));
                if (i < N - 1) r(i, j) = max(r(i, j), r(i+1, j));
            }
        }

        return r;
    }

    matrix<T> pow(ll expo){
        if(!expo) return matrix<T>(N, T(0), T(0));
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, T;
    cin >> N >> T;

    vector<int> val(N);

    for (int i = 0; i < N; i++)
        cin >> val[i];

    matrix<int> m(MAXV, 0, 0);

    for (int i = 0; i < N; i++) {
        int v = val[i];

        for (int s = 0; s <= v; s++) 
            m(s, v)++;

        for (int i = MAXV - 1; i >= 0; i--) {
            for (int j = i; j < MAXV; j++) {
                if (j > i) m(i, j) = max(m(i, j), m(i, j-1));
                if (i < N - 1) m(i, j) = max(m(i, j), m(i+1, j));
            }
        }
    }

    m = m.pow(T);
    cout << m(0, MAXV - 1) << endl;
}
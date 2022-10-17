#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
}

typedef long long ll;

ll MOD = 1000000007;

void add(ll &a, ll b){ a = (a+b) % MOD; }
ll sum(ll a, ll b){ return (a+b) % MOD; }
void mul(ll &a, ll b){ a = (a*b) % MOD; }
ll prod(ll a, ll b){ return (a*b) % MOD; }

struct mat{
    int N;
    vector<vector<ll> > dat;

    mat(int _N, ll diag = 0){
        N = _N;
        dat.resize(N);
        for(int i=0; i<N; i++){
            dat[i].resize(N);
            dat[i][i] = diag;
        }
    }

    vector<ll>& operator[](int i){
        return dat[i];
    }

    mat operator *(mat b){
        mat r(N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<N; k++)
                    add(r[i][j], prod(dat[i][k], b[k][j]));
        return r;
    }
    
    mat pow(ll E){
        if(!E) return mat(N, 1);
        mat r = (*this * *this).pow(E/2);
        return E&1 ? r * *this : r;
    }
    
    friend ostream& operator<<(ostream &os, mat &m){
        os << "{";
        for(int i=0; i<m.N; i++){
            if(i) os << "},\n ";
            os << "{";
            for(int j=0; j<m.N; j++){
                if(j) os << ", ";
                os << setw(10) << m[i][j] << setw(0);
            }
        }
        return os << "}}";
    }
};

ll exp(ll b, ll e){
    mat m(1, b);
    return m.pow(e)[0][0];
}

ll fib(ll i){
    mat m(2);
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
    mat r = m.pow(i);
    return r[0][0];
}

ll N, L, K;

int main(){
    setup();
    cin >> N >> K >> L >> MOD;

    if(L < 64 && (1ull << L) <= K){
        cout << 0 << endl;
        return 0;
    }

    ll offw = fib(N+1);
    ll onw = sum(exp(2, N), MOD-offw);

    int onb = __builtin_popcountll(K);
    cout << prod(exp(onw, onb), exp(offw, L-onb)) << endl;
}
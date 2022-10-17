#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 2000;

int sieve[MAXV];

bool prime_pow(int arg) {
    if(arg == 1) return false;
    int P = sieve[arg];
    while(arg % P == 0) arg /= P;
    return arg == 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int p = 2; p < MAXV; p++) {
        if(sieve[p]) continue;
        for (int q = p; q < MAXV; q += p) 
            sieve[q] = p;
    }

    int N;
    vector<int> res;

    cin >> N;

    for (int i = 2; i <= N; i++)
        if(prime_pow(i))
            res.push_back(i);

    cout << res.size() << "\n";
    for (int v : res) cout << v << " ";
    cout << "\n";
}
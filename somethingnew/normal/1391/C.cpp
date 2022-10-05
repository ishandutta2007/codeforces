#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>

using namespace std;
long long pow(long long a,long long b){
    long long res = 1;
    while(b){
        if(b%2)
            res *= a;
        b/=2;
        a *= a;
    }
    return res;
}
int main() {
    long long mod = pow(10,9) + 7;
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    long long minusres = 1;
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
        minusres *= 2;
        res %= mod;
        minusres %= mod;
    }
    cout << (mod + res - minusres) % mod;
}
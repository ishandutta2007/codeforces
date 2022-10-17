#include <iostream>
#define MOD 1000000007
using namespace std;

int x, y, N, v[6];

int main(){
    cin >> x >> y >> N;
    if(x < 0) x += MOD;
    if(y < 0) y += MOD;

    v[1] = x;
    v[2] = y;

    v[3] = y-x;
    if(v[3] < 0) v[3] += MOD;

    v[4] = (MOD - x) % MOD;
    v[5] = (MOD - y) % MOD;
    v[0] = (MOD - v[3]) % MOD;

    cout << v[N%6] << endl;
}
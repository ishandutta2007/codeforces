#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll N;
    cin >> N;

    ll D = 1;

    while(N % D == 0) D *= 3;

    cout << (N + D - 1) / D << endl;
}
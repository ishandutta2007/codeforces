#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;
const int k_K = 9 + 3;
const long long k_Mod = 1e9 + 7;

int a[k_N], b[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int dn = n / k;
    for(int i = 0; i < dn; ++i)
        cin >> a[i];
    for(int i = 0; i < dn; ++i)
        cin >> b[i];

    int nines = 1;
    for(int i = 0; i < k; ++i)
        nines *= 10;
    nines--;

    int power = 1;
    for(int i = 0; i < k - 1; ++i)
        power *= 10;

    long long answer = 1;
    for(int i = 0; i < dn; ++i){
        int curr = (nines / a[i]) + 1;
        int num = b[i] * power;

        int m = num % a[i];
        if(m){
            num += a[i] - m;
            if(num >= (b[i] + 1) * power){
                answer *= curr;
                answer %= k_Mod;
                continue;
            }
        }

        curr -= ((b[i] + 1) * power - 1 - num) / a[i] + 1;
        answer *= curr;
        answer %= k_Mod;
    }

    cout << answer << "\n";
}
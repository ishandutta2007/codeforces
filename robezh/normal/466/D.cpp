#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

int n,h;
int num[2050];

int main(){
    ll res = 1;

    cin >> n >> h;
    for(int i = 0; i < n; i++) cin >> num[i], num[i] = h - num[i];
    if(num[0] >= 2 || num[n-1] >= 2) return !printf("0");
    for(int i = 0; i < n-1; i++) if(abs(num[i]-num[i+1]) >= 2) return !printf("0");
    for(int i = 0; i < n; i++) if(num[i] < 0) return !printf("0");

    int val = 0;
    for(int i = 0; i < n-1; i++){
        if(num[i] == num[i+1] + 1) res *= num[i], res %= mod;
        else if(num[i] == num[i+1]) res *= (num[i]+1), res %= mod;
    }
    cout << res;

}
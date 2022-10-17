#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
const ll mod = 998244353;
int abit[N];
int bbit[N];
char s[N];
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    scanf("%s", s);
    for (int i = 0; i < a; i++){
        abit[a - i - 1] = s[i] - '0';
    }
    scanf("%s", s);
    for (int i = 0; i < b; i++){
        bbit[b - i - 1] = s[i] - '0';
        if (i)
            bbit[b - i - 1] += bbit[b - i];
    }
    ll power = 1;
    ll sum = 0;
    for (int i = 0; i <= max(a, b); i++){
        if (abit[i]){
            sum+=bbit[i] * power%mod;
            sum%=mod;
        }
        power = power * 2 % mod;
    }
    cout << sum << endl;
    return 0;
}
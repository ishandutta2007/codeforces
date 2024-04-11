#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k1,k2;
int num1[1050],num2[1050];
int dif[1050];

int fabs(int a){
    return a > 0 ? a : -a;
}

int main(){
    cin >> n >> k1 >> k2;
    for(int i = 0; i < n; i++) cin >> num1[i];
    for(int i = 0; i < n; i++) cin >> num2[i], dif[i] = fabs(num2[i]-num1[i]);

    for(int i = 0; i < k1 + k2; i++){
        int maxj = 0;
        for(int j = 1; j < n; j++){
            if(dif[j] > dif[maxj]) maxj = j;
        }
        dif[maxj] = fabs(dif[maxj]-1);
    }

    ll res = 0;
    for(int i = 0; i < n; i++) res += (ll)dif[i] * dif[i];
    cout << res;
}
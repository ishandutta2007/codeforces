#include <bits/stdc++.h>
using namespace std;

int n, U;
double res = -1;
int num[100500];

int main() {
    int k = 0;
    cin >> n >> U;
    for(int i = 0; i < n; i++) cin >> num[i];

    for(int i = 0; i < n-1; i++){
        while(k < n-1 && num[k+1] - num[i] <= U) k++;
        if(i+2 > k) continue;
        res = max(res, (double)(num[k]-num[i+1])/(num[k]-num[i]));
    }
    if(res == -1) return !printf("-1");
    else cout << fixed << setprecision(10) << res;
}
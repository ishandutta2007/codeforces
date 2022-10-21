#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef long long ll;


int n;
int num[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++) scanf("%d", &num[i]);
    sort(num, num+2*n);
    ll res = 1LL * (num[n-1] - num[0]) * (num[2*n-1] - num[n]);
    for(int i = 1; i < n; i++){
        res = min(res, 1LL * (num[n-1+i] - num[i]) * (num[2*n-1] - num[0]));
    }
    cout << res << endl;
}
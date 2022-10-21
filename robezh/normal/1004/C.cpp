#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

ll ans = 0;
int n, num[N];
int rlas[N], rsum[N], llas[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++) rlas[num[i]] = i;
    for(int i = n-1; i >= 0; i--) llas[num[i]] = i;
    rsum[n] = 0;
    for(int i = n-1; i >= 0; i--){
        rsum[i] = rsum[i+1] + (rlas[num[i]] == i);
    }
    for(int i = 0; i < n-1; i++){
        if(llas[num[i]] == i) ans += rsum[i+1];
    }
    cout << ans;

}
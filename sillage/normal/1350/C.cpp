#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int a[maxn], n;
vector<int>lis[200010];
long long Pow(int i, int u){
    long long y = 1, x = i;
    for (;u;u>>=1, x*=x) if (u&1) y*=x;
    return y; 
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        for (int j = 2; j*j <=x; j++) {
            int cnt = 0;
            while (x % j == 0) cnt++, x/=j;
            lis[j].push_back(cnt);
        }
        if (x>1) lis[x].push_back(1);
    }
    long long ans = 1;
    for (int i=2; i<=200000; i++) if (lis[i].size() >= n-1){
        sort(lis[i].begin(), lis[i].end());
        if (lis[i].size() == n) ans *= Pow(i, lis[i][1]);
        else if (lis[i].size() == n-1) ans *= Pow(i, lis[i][0]);
    }
    printf("%lld\n", ans);
    return 0;
}
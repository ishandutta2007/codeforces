#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K, ans;
int cnt[202020];

int main(){
    int a, mid, k;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int L=1, H=200000; L<=H; ){
        mid = (L+H)/2, k=0;
        for (int i=1; i<=200000; i++) k += (cnt[i] / mid);
        if (k >= K) ans = mid, L = mid + 1;
        else H = mid - 1;
    }

    for (int i=1, j=1; i<=200000 && j<=K; i++){
        if (cnt[i] >= ans){
            printf("%d ", i);
            cnt[i--] -= ans;
            j++;
        }
    }
    return 0;
}
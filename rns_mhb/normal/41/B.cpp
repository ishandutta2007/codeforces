#include <bits/stdc++.h>
using namespace std;

int n, b, a[3000], mini[3000];

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%d %d", &n, &b);
    for(int i = 1; i <= n; i ++)    scanf("%d", a + i);
    mini[1] = a[1];
    for(int i = 2; i <= n; i ++){
        if(mini[i - 1] > a[i])  mini[i] = a[i];
        else mini[i] = mini[i - 1];
        //printf("%d ", mini[i]);
    }
    int maxi = b;
    for(int i = 1; i <= n; i ++){
        int k = b;
        int k1 = b / mini[i];
        k %= mini[i];
        k += (a[i] * k1);
        if(maxi < k)    maxi = k;
    }
    printf("%d\n", maxi);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 150000;
int n, num[N];
ll res[N];


int main(){
    scanf("%d", &n);
    int mx = 0;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]), mx = max(mx, num[i]);

    if(mx == 0){
        printf("YES\n");
        for(int i = 0; i < n; i++) printf("1 ");
        return 0;
    }


    int cur = -1;
    for(int i = 0; i < n; i++){
        if(num[i] == mx && num[(i+n-1)%n] < mx){
            cur = i;
            break;
        }
    }
    bool zb = false;
    if(cur == -1) return !printf("NO");
    res[cur] = num[cur];
    for(int j = (cur + n - 1) % n; j != cur; j = (j + n - 1) % n){
        res[j] = num[j] + res[(j+1)%n];
        if(num[j] == 0 && !zb){
            zb = true;
            res[j] *= 2;
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) printf("%I64d ", res[i]);
}
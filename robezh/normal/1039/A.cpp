#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;
const ll INF = (ll)3e18;

int n;
ll t, a[N];
int x[N];
ll res[N];

int main(){
    scanf("%d", &n);
    scanf("%I64d", &t);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
        a[i] += t;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        x[i]--;
        if(x[i] < i) return !printf("No");
    }
    for(int i = 0; i < n-1; i++){
        if(x[i] > x[i+1]) return !printf("No");
    }
    for(int i = n-1; i >= 0; i--){
        if(i == n-1) res[i] = INF;
        else if(x[i] == x[i+1]){
            res[i] = res[i+1] - 1;
        }
        else{
            res[i] = min(a[x[i]+1] - 1, res[i+1] - 1);
        }

    }
    //printf("YES\n");
    //for(int i = 0; i < n; i++) printf("%I64d ", res[i]);
    for(int i = 0; i < n; i++) if(res[i] < a[i]) return !printf("No");
    for(int i = 0; i < n;){
        int r = i;
        while(r < n && x[r] == x[i]) r++;
        for(int j = i; j < r - 1; j++){
            if(res[j] < a[j+1]) return !printf("No");
        }
        if(r < n && res[r-1] >= a[r]) return !printf("No");
        i = r;
    }
    printf("Yes\n");
    for(int i = 0; i < n; i++) printf("%I64d ", res[i]);


}
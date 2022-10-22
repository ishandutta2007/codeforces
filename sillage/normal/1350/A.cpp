#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int n, k;
        cin >> n >> k;
        if (n & 1){
            int i;
            for (i = 2; i*i <=n; i++)  if (n%i == 0){
                break;
            }
            if (i*i <=n){
                n+=i;
            }else{
                n+=n;
            }
            k--;
        }
        printf("%d\n", n+2*k);
    }
    return 0;
}
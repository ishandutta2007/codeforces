#include<bits/stdc++.h>
using namespace std;
int A[5009][5009], B[5009][5009], ans[5009][5009];
int a[5009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        A[i][i] = a[i];
        B[i][i] = a[i];
        ans[i][i] = a[i];
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j + i - 1 <= n; j++){
            int l = j, r = j + i - 1;
            A[l][r] = (A[l][r-1]^A[l+1][r]);
            B[l][r] = max(A[l][r], B[l][r-1]);
        }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j + i - 1 <= n; j++){
            int l = j, r = j + i - 1;
            ans[l][r] = max(ans[l+1][r], B[l][r]);
        }

    int q;
    cin >> q;
    while(q--){
        int l , r;
        scanf("%d%d",&l, &r);
        printf("%d\n",ans[l][r]);
    }
    //b0, b1, .. b(m-1)

}

/*
0 -0
1 - 0^1
2 - 0^2
3 - (0^1)^(2^3)
4 - (
*/
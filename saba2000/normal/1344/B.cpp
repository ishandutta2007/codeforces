#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
int L[1009], R[1009];
main(){
    int n, m;
    cin >>n >> m;
    for(int i = 1; i <= n; i++){
        string s; cin >>s;
        for(int j  = 1;j <=m; j++){
            char x = s[j-1];
            if(x == '#') a[i][j] = 1;
            else a[i][j] =0 ;
        }
    }
    int row = 0, col  =0;
    for(int i = 1; i <= n; i++){
        int k = 0;
        int l = -1, r = -1;
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1 && a[i][j-1] == 0) k++;
            if(a[i][j] == 1) {
                if(l == -1) l = j;
                r = j;
            }
        }
        if(k > 1){
            cout<<-1<<endl;
            return 0;
        }
        if(k){
            L[i] = l, R[i] = r;
        }
        if(!k) row = 1;

    }
    for(int i = 1; i <= m; i++){
        int k = 0;
        for(int j = 1; j <= n; j++){
            if(a[j][i] == 1 && a[j-1][i] == 0) k++;
        }
        if(k > 1){
            cout<<-1<<endl;
            return 0;
        }
        if(!k) col = 1;
    }
    if(row && !col || col && !row){
        cout<<-1<<endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(L[i] && (!L[i-1] || min(R[i], R[i-1])< max(L[i], L[i-1])))
            ans++;
    }
    cout<<ans<<endl;


}
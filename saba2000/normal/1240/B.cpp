#include<bits/stdc++.h>
using namespace std;
int a[300009];
int f[300009];
int l[300009];
int r[300009];
int n;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        f[i] = 0,l[i] = 0,r[i] =0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(!f[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
        f[a[i]] = 1;
    }
    int k = 0;
    int RR = -1,ans = 0, ans1 = 0;
    for(int i = 1; i <= n; i++){
        if(!f[i]) continue;
        k++;
        if(l[i] > RR){
            ans1++;
        }
        else ans = max(ans, ans1),ans1=1;
        RR = r[i];
    }
    cout<<k-max(ans,ans1)<<endl;


}
main(){
    int q;
    cin >> q;
    while(q--){
        solve();
    }


}
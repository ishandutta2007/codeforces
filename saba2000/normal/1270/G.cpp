#include<bits/stdc++.h>
#define B 100
#define ll long long
using namespace std;
int a[1000009];
int f[1000009];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i =1; i <= n; i++){
        f[i] = 0;
        scanf("%d",&a[i]);
        a[i] = i - a[i];
    }
    int j = 1,ans=0;
    while(f[j] != 2){
        f[j]++;
        if(f[j] == 2) ans++;
        j = a[j];
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        if(f[i] == 2) printf("%d ", i);
    printf("\n");
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
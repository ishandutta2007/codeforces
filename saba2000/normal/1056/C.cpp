#include<bits/stdc++.h>
using namespace std;
int p[2009];
int f[2009],a[2009],b[2009];
    int n, m;
void mov(){
    for(int i = 1; i <= m; i++){
        if(f[a[i]] && !f[b[i]]){
            cout<<b[i]<<endl;
            f[b[i]] = 1;
            return;
        }
        if(f[b[i]] && !f[a[i]]){
            cout<<a[i]<<endl;
            f[a[i]] = 1;
            return;
        }
    }
    for(int i =1; i <= m; i++){
        if(f[a[i]]) continue;
        if(p[a[i]] > p[b[i]]) {
            cout<<a[i]<<endl;
            f[a[i]] = 1;
            return;
        }
        cout<<b[i]<<endl;
        f[b[i]] = 1;
        return;
    }
    int x = 0;
    for(int i = 1; i <= 2*n; i++){
        if(p[i] > p[x] && f[i] == 0)
            x = i;
    }
    cout<<x<<endl;
    f[x] = 1;
    return;
}
main(){
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= m; i++){
       cin >> a[i] >> b[i];
    }
    int t;
    cin >> t;
    for(int x = 1; x<= 2*n; x++){
        if(t == 1){
            mov();
        }
        else{
            int k;
            cin >> k;
            f[k] = 1;
        }
        t = 3 - t;
    }

}
#include<bits/stdc++.h>
using namespace std;
int f[300009],g[300009],ans[300009],fl[300009],a[300009];
main(){
    int t;
    cin>>t;
    for(int i = 1;i <= t; i++){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            f[i] = 0,g[i] = 0,ans[i] = 0,fl[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            f[a[i]]++;
            g[a[i]] = i;
        }
        if(f[1]) ans[1] = 1;
        int p = 1, s = n;
        for(int i = 1; i < n; i++){
            if(f[i] != 1 || f[i+1] == 0){
                break;
            }
            int u = g[i];
            fl[u] = 1;
            while(fl[p]) p++;
            while(fl[s]) s--;
            if(p -1 + n - s == i)
                ans[i+1] = 1;
            else break;
        }
        ans[n] = 1;
        for(int i = 1; i <= n; i++)
            if(f[i] == 0) ans[n] = 0;
        string Ans;
        for(int i = 1; i <= n; i++)
            if(ans[n+1-i]) Ans+='1'; else Ans+='0';
        cout<<Ans<<endl;
    }



}
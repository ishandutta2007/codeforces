#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[1009][1090];
main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >>n>> a >> b;
        int ok = 1;
         for(int i ='a' ; i <='z'; i++)
            for(int j = 'a'; j <='z';j ++)
                f[i][j] =0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] > b[i]){
                ok = 0;
            }
            f[a[i]][b[i]] = 1;
        }
        if(!ok) {
            cout << -1<<endl;
            continue;
        }
        int ans = 0;
        for(int i ='a' ; i <='z'; i++){
            int u = -1;
            for(int j = i+1; j <='z';j ++){
               if(f[i][j] && u == -1) u = j;
                if(f[i][j]) f[u][j] = 1;
            }
            if(u != -1) ans++;
        }
        cout<<ans<<endl;

    }

}
/*
1 1 1 0

*/
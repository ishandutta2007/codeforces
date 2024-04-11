#include<bits/stdc++.h>
using namespace std;
int f[19][109][109];
main(){
    int n,q,c;
    cin>> n >> q >> c;
    for(int i = 0; i < n; i++){
        int x,y,s;
        scanf("%d %d %d", &x,&y,&s);
        f[s][x][y] ++;
    }
    for(int i = 1; i <= 100; i++)
        for(int j =1; j <= 100; j++)
            for(int k = 0; k <= c; k++)
            f[k][i][j] += f[k][i][j-1] + f[k][i-1][j] - f[k][i-1][j-1];
        while(q--){
            int t,x,y,a,b;
            scanf("%d %d %d %d %d",&t,&x,&y,&a,&b);
            x--; y--;
            int ans = 0;
            for(int i = 0; i <= c; i++){
                int S = f[i][a][b] - f[i][x][b] - f[i][a][y] + f[i][x][y];
                ans += S * ((i + t)%(c+1));
            }
            cout<<ans<<endl;
        }

}
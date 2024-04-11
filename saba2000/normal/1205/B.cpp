#include<bits/stdc++.h>
using namespace std;
long long a[100009];
int d[209][209];
int f[209][209];
vector<int> ff[444];
main(){
    int n;
    cin >> n;
    int J =0 , N= 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) continue;
        J++; N++;
        for(long long j = 0; j < 60; j++){
            if((1ll<<j) & a[i]) {ff[j].push_back(J);
                if(ff[j].size() > 2) {cout<<3<<endl; return 0;}
        }
        }
    }
    n = N;
    for(int j = 0; j < 60; j++){
        if(ff[j].size() == 2){
            int a = ff[j][0]; int b = ff[j][1];
            d[a][b] = 1;
            d[b][a] = 1;
        }
    }
    int ans = 1e9;
    for(int i =1; i <= n; i++){
        d[i][i] = 2;
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(!d[j][k] && d[j][i] && d[i][k])
                    d[j][k] = 2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(d[i][j] != 1) continue;
            vector<int> v;

            v.push_back(i);
            for(int x = i+1; x <= n; x++){
                if(!d[i][x]) continue;
                v.push_back(x);
            }
            for(int x : v)
                for(int y: v)
                    if(x == y) f[x][y] = 0;
                    else if(d[x][y] == 1) f[x][y] = 1;
                    else f[x][y] = 1e9;
            f[i][j] = 1e9;
            f[j][i] = 1e9;
            for(int x : v)
                for(int y : v)
                    for(int z : v)
                        if(f[y][z] > f[y][x] + f[x][z])
                            f[y][z] = f[y][x] + f[x][z];
            ans = min(ans, f[i][j] + 1);
        }
    }
    if(ans == 1e9) cout<<-1<<endl;
    else cout<< ans << endl;

}
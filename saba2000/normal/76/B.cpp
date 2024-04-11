#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[100009],y[100009], D[100009], f[100009];
void r(int j, int d){
    if(D[j] < d) return;
    if(D[j] == d){
        f[j]++;
    }
    else
        D[j] = d, f[j] = 1;
}
main(){
   int n, m;
   cin >> n >> m>>x[0]>>x[0];
   for(int i =1; i <= n; i++){
        cin >> x[i];
   }
   for(int i =1 ;i <= m; i++){
        cin >> y[i];
        D[i] = 1e9+1;
   }
   int j = 1;
   for(int i = 1; i <= n; i++){
      while(j < m && abs(x[i]-y[j+1]) < abs(x[i] - y[j])) j ++;
        int d = abs(x[i] - y[j]);
        if(j < m && d == abs(x[i] - y[j+1])){
            if(f[j] && D[j] != d){
                r(j+1,d);
            }
            else
                r(j,d);
        }
        else r(j, d);
   }
   int a = 0;
   for(int i= 1; i <= m; i++)
     a += f[i];
   cout<< n - a << endl;
}
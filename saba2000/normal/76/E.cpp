#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x[100009],y[100009];
ll ssq,sx,sy;
main(){
   int n;
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> x[i] >> y[i];
      ssq += x[i]*x[i]+y[i]*y[i];
      sx += x[i];
      sy += y[i];
   }
   cout<<ssq*n - sx*sx-sy*sy<<endl;
}
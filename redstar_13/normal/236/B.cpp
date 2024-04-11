#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define NN 1000010
int i,j,k,a,b,c,s;
int aa[NN];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
#endif
   
   for(i=1;i<NN;i++) for(j=1;j*i<NN;j++) aa[i*j]++;
  
   INT s=0;
   
   scanf(" %d %d %d",&a,&b,&c);
   for(i=1;i<=a;i++) for(j=1;j<=b;j++) for(k=1;k<=c;k++) s+=aa[i*j*k];  
   printf("%d\n",s%1073741824);
}
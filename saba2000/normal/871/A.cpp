#include<bits/stdc++.h>
using namespace std;
long long n,k,m[100009],q;
int main(){ cin>>q;

 while(q--)
 {

  scanf("%d",&m[q]);
  if(m[q]<4 || m[q]==5){
  printf("-1\n");
   continue;
  }
  if(m[q]%2==0){
  printf("%d\n",m[q]/4);
   continue;
  }
  if(m[q]%4==1 || m[q]%4==3 && m[q]>12){
printf("%d\n",m[q]/4-1);
   continue;
  }
 printf("-1\n");
 }
 return 0;
}
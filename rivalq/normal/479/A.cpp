#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int t1=a*b*c;
  int t2=a+b+c;
  int t3=(a+b)*c;
  int t4=a*(b+c);
  int t5=a*b+c;
  int t6=a+b*c;
  int m1=(t1>t2)?t1:t2;
  int m2=(t3>t4)?t3:t4;
  int m3=(t5>t6)?t5:t6;
  int max=(m1>m2)?m1:m2;
  max= (max>m3)?max:m3;
  cout<<max<<endl;
}
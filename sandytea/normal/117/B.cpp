//program 117B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string Get(int T)
{
  string S;
  for(int i=0;i<9;i++){S=char(T%10+48)+S;T/=10;}
  return S;
}

int main()
{
  int A,B,P,Ans=-1;cin>>A>>B>>P;
  if(B<P)
    for(int i=0,LB=0,UB=B;i<=A&&i<P&&Ans==-1;i++,LB=(LB+1000000000)%P,UB=(UB+1000000000)%P)
      if(LB>0&&LB<=UB)Ans=i;
  if(Ans==-1)
    cout<<2<<endl;
  else
    cout<<1<<' '<<Get(Ans)<<endl;
  return 0;
}
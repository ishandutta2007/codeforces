//program 151B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Taxi(string S)
{
  return S[0]==S[1]&&S[1]==S[2]&&S[2]==S[3]&&S[3]==S[4]&&S[4]==S[5];
}

bool Pizza(string S)
{
  return S[0]>S[1]&&S[1]>S[2]&&S[2]>S[3]&&S[3]>S[4]&&S[4]>S[5];
}

int main()
{
  int N;cin>>N;
  int N1=0,N2=0,N3=0,Max1=0,Max2=0,Max3=0;
  string Ans1[100],Ans2[100],Ans3[100];
  while(N--)
    {
      int M;string S;cin>>M>>S;
      int C1=0,C2=0,C3=0;
      while(M--)
        {
          string Number;
          for(int i=0;i<6;i++){char c=getchar();while(c<'0'||c>'9')c=getchar();Number+=c;}
          if(Taxi(Number))C1++;
          else if(Pizza(Number))C2++;
          else C3++;
        }
      if(C1>Max1){Max1=C1;N1=0;}if(C1==Max1)Ans1[N1++]=S;
      if(C2>Max2){Max2=C2;N2=0;}if(C2==Max2)Ans2[N2++]=S;
      if(C3>Max3){Max3=C3;N3=0;}if(C3==Max3)Ans3[N3++]=S;
    }
  cout<<"If you want to call a taxi, you should call:";
  for(int i=0;i<N1;i++)cout<<' '<<Ans1[i]<<((i==N1-1)?".\n":",");
  cout<<"If you want to order a pizza, you should call:";
  for(int i=0;i<N2;i++)cout<<' '<<Ans2[i]<<((i==N2-1)?".\n":",");
  cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
  for(int i=0;i<N3;i++)cout<<' '<<Ans3[i]<<((i==N3-1)?".\n":",");
  return 0;
}
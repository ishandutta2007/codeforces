//program 156E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int P[4]={1397110206,930734855,1219503313,1453912603};
const int Prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int Num[25]={0,0,1,2,3,3,2,1,0,0,1,2,3,3,2,1,0,0,1,2,3,3,2,1,0};
const int MaxLen[17]={0,0,14,9,7,6,6,5,5,5,5,4,4,4,4,4,4};

vector<long long> DP[4][17];
long long A[10000];

int Pow(int A,int B)
{
  if(!B)return 1;
  int T=Pow(A,B/2);
  T=T*T;if(B&1)T=T*A;
  return T;
}

void Calculate(int N)
{
  for(int Mod=0;Mod<4;Mod++)
    for(int Base=2;Base<=16;Base++)
      {
        int MaxMask=Pow(Base+1,MaxLen[Base]);
        DP[Mod][Base].resize(MaxMask);
        for(int Mask=0;Mask<MaxMask;Mask++)
          {
            DP[Mod][Base][Mask]=1;
            int Temp=Mask,First=MaxLen[Base]-1,W=MaxMask/(Base+1);
            while(First>=0)
              {
                if(Temp/W==Base)break;
                Temp%=W;First--;W/=Base+1;
              }
            if(First==-1)
              {
                int T=0,W=MaxMask/(Base+1),Tmp=Mask;
                while(W)
                  {
                    T=T*Base+Tmp/W;
                    Tmp%=W;W/=Base+1;
                  }
                DP[Mod][Base][Mask]=(T<N)?A[T]%P[Mod]:1;
              }
            else
              for(int i=1;i<=Base;i++)
                DP[Mod][Base][Mask]=DP[Mod][Base][Mask]*DP[Mod][Base][Mask-W*i]%P[Mod];
          }
      }
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)cin>>A[i];
  Calculate(N);
  int Query;cin>>Query;
  while(Query--)
    {
      int Base;string Pattern;long long Cost;
      cin>>Base>>Pattern>>Cost;int Len=Pattern.size();
      while(Len<MaxLen[Base]){Pattern='0'+Pattern;Len++;}
      string Mask;int Start=Len-MaxLen[Base];
      bool Bad=false;
      for(int i=0;!Bad&&i<Start;i++)Bad=(Pattern[i]!='?'&&Pattern[i]!='0');
      if(Bad){cout<<-1<<endl;continue;}
      while(Start<Len)Mask+=Pattern[Start++];
      int T=0;for(int i=0;i<MaxLen[Base];i++)T=T*(Base+1)+((Mask[i]=='?')?Base:((Mask[i]<='9')?(Mask[i]-48):(Mask[i]-55)));
      int Ans=-1;
      for(int i=0;Ans==-1&&i<25;i++)
        if((DP[Num[i]][Base][T]+Cost)%Prime[i]==0)
          Ans=Prime[i];
      cout<<Ans<<endl;
    }
  return 0;
}
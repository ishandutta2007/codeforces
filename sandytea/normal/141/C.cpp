//program 141C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const double MaxH=1e10;

int N;
bool Flag[3000];
int H[3000];
string Ans[3000];

int main()
{
  scanf("%d",&N);
  bool OK=true;memset(Flag,0,sizeof(Flag));
  for(int i=0;i<N;i++)
    {
      string S;int x;cin>>S>>x;
      int p=x;while(p<N&&Flag[p])p++;
      if(p<N){H[p]=p+1-x;Ans[p]=S;Flag[p]=true;}else OK=false;
    }
  if(!OK)
    printf("-1\n");
  else
    {
      H[0]=1;
      for(int i=1;i<N;i++)
        for(int j=0;j<i;j++)
          if(H[j]>=H[i])H[j]++;
      for(int i=0;i<N;i++)cout<<Ans[i]<<' '<<H[i]<<endl;
    }
  return 0;
}
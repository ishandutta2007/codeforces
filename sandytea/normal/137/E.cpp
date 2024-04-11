//program 137E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;
int N;
int Sum[200001],Max[200001],Count[200001];

int Find(int X)
{
  if(Max[N]>=X)return N;
  int Left=0,Right=N;
  while(true)
    {
      int Mid=(Left+Right)/2;
      if(Max[Mid]>=X&&Max[Mid+1]<X)return Mid;
      if(Max[Mid]>=X)Left=Mid+1;else Right=Mid-1;
    }
}

int main()
{
  cin>>S;N=S.size();
  Sum[0]=0;
  for(int i=0;i<N;i++)
    if(S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U'||S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
      Sum[i+1]=Sum[i]-1;
    else
      Sum[i+1]=Sum[i]+2;
  Max[N]=Sum[N];for(int i=N-1;i>=0;i--)Max[i]=max(Max[i+1],Sum[i]);
  memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)Count[Find(Sum[i])-i]++;
  int Ans=N;while(!Count[Ans])Ans--;
  if(Ans)cout<<Ans<<' '<<Count[Ans]<<endl;else cout<<"No solution"<<endl;
  return 0;
}
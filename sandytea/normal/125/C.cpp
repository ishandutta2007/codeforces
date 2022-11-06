//program 125C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int M=3;while(M*(M+1)/2<=N)M++;
  int Count=0,Top[144],Ans[144][143];
  memset(Top,0,sizeof(Top));
  for(int i=0;i<M;i++)
    for(int j=i+1;j<M;j++)
      {Count++;Ans[i][Top[i]++]=Count;Ans[j][Top[j]++]=Count;}
  cout<<M<<endl;
  for(int i=0;i<M;i++)
    for(int j=0;j<Top[i];j++)
      {
        cout<<Ans[i][j];
        putchar((j==Top[i]-1)?'\n':' ');
      }
  return 0;
}
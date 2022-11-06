//program 117C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool A[5000][5000];

int main()
{
  int N;cin>>N;
  int Degree[5000];memset(Degree,0,sizeof(Degree));
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      {
        char c=getchar();
        while(c!='0'&&c!='1')c=getchar();
        A[i][j]=(c=='1');if(A[i][j])Degree[i]++;
      }
  int T[5000];for(int i=0;i<N;i++)T[i]=Degree[i];sort(T,T+N);
  int P=N-1;while(P>=0&&T[P]==P)P--;
  if(P==-1){cout<<-1<<endl;return 0;}
  for(int i=0;i<N;i++)if(Degree[i]==T[P]){P=i;break;}
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(A[P][i]&&A[i][j]&&A[j][P])
        {cout<<P+1<<' '<<i+1<<' '<<j+1<<endl;return 0;}
  return 0;
}
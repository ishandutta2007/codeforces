//program 159C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  string T,S[2001];cin>>T;
  for(int i=1;i<=N;i++)S[i]=T;
  int Count[2001][26];memset(Count,0,sizeof(Count));
  for(int i=0;i<T.size();i++)for(int j=1;j<=N;j++)Count[j][T[i]-97]+=j;
  int Query;cin>>Query;
  while(Query--)
    {
      int X;cin>>X;
      char c;while(c=getchar(),c<'a'||c>'z');
      int P=0;while(Count[P][c-97]<X)P++;
      int Tmp=X-Count[P-1][c-97];
      string New;
      for(int i=0;i<S[P].size();i++)
        {
          if(S[P][i]==c)Tmp--;
          if(S[P][i]!=c||Tmp)New+=S[P][i];
        }
      S[P]=New;while(P<=N)Count[P++][c-97]--;
    }
  for(int i=1;i<=N;i++)cout<<S[i];putchar('\n');
  return 0;
}
//program 149B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long Check(string S,int T)
{
  long long Sum=0;
  for(int i=0;i<S.size();i++)
    {
      int V=(S[i]>='0'&&S[i]<='9')?(S[i]-48):(S[i]-55);
      if(V>=T)return 100;Sum=Sum*T+V;
    }
  return Sum;
}

int main()
{
  string S;cin>>S;
  string Hour,Minute;
  int P=0;while(S[P]!=':')Hour+=S[P++];
  while(++P<S.size())Minute+=S[P];
  bool Ans=false;int Left=-1,Right=-1;
  for(int i=1;i<100;i++)
    if(Check(Hour,i)<24&&Check(Minute,i)<60)
      {Ans=true;if(Left==-1)Left=i;Right=i;}
  if(!Ans)
    cout<<0<<endl;
  else if(Right==99)
    cout<<-1<<endl;
  else
    for(int i=Left;i<=Right;i++){cout<<i;putchar((i==Right)?'\n':' ');}
  return 0;
}
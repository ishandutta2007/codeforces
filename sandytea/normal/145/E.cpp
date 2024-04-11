//program 145E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;
int S4[3000000],S7[3000000],Max1[3000000],Max2[3000000];
bool Flag[3000000];

void Check(int P,int Left,int Right)
{
  if(!Flag[P])return;Flag[P]=false;
  int T;
  T=S4[P];S4[P]=S7[P];S7[P]=T;
  T=Max1[P];Max1[P]=Max2[P];Max2[P]=T;
  if(Left!=Right)
    {
      Flag[P*2]=!Flag[P*2];
      Flag[P*2+1]=!Flag[P*2+1];
    }
}

void Update(int P,int Left,int Right,int Mid)
{
  Check(P*2,Left,Mid);Check(P*2+1,Mid+1,Right);
  S4[P]=S4[P*2]+S4[P*2+1];
  S7[P]=S7[P*2]+S7[P*2+1];
  Max1[P]=max(Max1[P*2]+S7[P*2+1],S4[P*2]+Max1[P*2+1]);
  Max2[P]=max(Max2[P*2]+S4[P*2+1],S7[P*2]+Max2[P*2+1]);
}

void BuildTree(int P,int L,int R)
{
  Flag[P]=false;
  if(L==R)
    {
      S4[P]=S7[P]=0;
      if(S[L]=='4')S4[P]=1;else S7[P]=1;
      Max1[P]=Max2[P]=1;
    }
  else
    {
      int Mid=(L+R)/2;
      BuildTree(P*2,L,Mid);
      BuildTree(P*2+1,Mid+1,R);
      Update(P,L,R,Mid);
    }
}

void Inverse(int P,int Left,int Right,int L,int R)
{
  if(Left==L&&Right==R){Flag[P]=!Flag[P];Check(P,Left,Right);return;}
  int Mid=(Left+Right)/2;
  if(R<=Mid)Inverse(P*2,Left,Mid,L,R);
  else if(L>Mid)Inverse(P*2+1,Mid+1,Right,L,R);
  else {Inverse(P*2,Left,Mid,L,Mid);Inverse(P*2+1,Mid+1,Right,Mid+1,R);}
  Update(P,Left,Right,Mid);
}

int main()
{
  int N,M;cin>>N>>M>>S;
  BuildTree(1,0,N-1);
  while(M--)
    {
      char c=getchar(),d;
      while(c!='c'&&c!='s')c=getchar();
      while(d=getchar(),d!=' '&&d!=10);
      if(c=='c')
        printf("%d\n",Max1[1]);
      else
        {
          int L,R;scanf("%d%d",&L,&R);
          Inverse(1,0,N-1,L-1,R-1);
        }
    }
  return 0;
}
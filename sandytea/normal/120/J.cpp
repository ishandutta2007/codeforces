//program 120J

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point
{
  double X,Y;
  int W,Num;
};

struct AnsType
{
  int V1,V2,W1,W2;
  double Dist;
};

const double inf=1000000000;

Point P[100000],Data[100000],Q1[100000],Q2[100000];

int GetNumber()
{
  char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();
  bool Flag=(c=='-');if(Flag)c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return Flag?-X:X;
}

bool Cmp(Point A,Point B)
{
  return A.X<B.X;
}

double Calc_Dist(Point A,Point B)
{
  return sqrt((A.X-B.X)*(A.X-B.X)+(A.Y-B.Y)*(A.Y-B.Y));
}

AnsType Calc(int L,int R)
{
  AnsType T;T.Dist=inf;
  if(R-L<3)
    {
      for(int i=L;i<R;i++)
        for(int j=i+1;j<=R;j++)
          if(P[i].Y>P[j].Y){Point Tmp=P[i];P[i]=P[j];P[j]=Tmp;}
      for(int i=L;i<R;i++)
        for(int j=i+1;j<=R;j++)
          {
            double Tmp=Calc_Dist(P[i],P[j]);
            if(Tmp<T.Dist){T.Dist=Tmp;T.V1=P[i].Num;T.W1=P[i].W;T.V2=P[j].Num;T.W2=P[j].W;}
          }
      return T;
    }
  int Mid=(L+R)/2;double Line=(P[Mid].X+P[Mid+1].X)/2;
  AnsType T1=Calc(L,Mid),T2=Calc(Mid+1,R);
  T=(T1.Dist<T2.Dist)?T1:T2;double Len=T.Dist;
  int M1=0;for(int i=L;i<=Mid;i++)if(Line-P[i].X<Len)Q1[M1++]=P[i];
  int M2=0;for(int i=Mid+1;i<=R;i++)if(P[i].X-Line<Len)Q2[M2++]=P[i];
  int P1=L,P2=Mid+1,K=0;
  while(P1<=Mid&&P2<=R)if(P[P1].Y<P[P2].Y)Data[K++]=P[P1++];else Data[K++]=P[P2++];
  while(P1<=Mid)Data[K++]=P[P1++];while(P2<=R)Data[K++]=P[P2++];
  for(int i=0;i<K;i++)P[L+i]=Data[i];
  P1=0;P2=-1;
  for(int i=0;i<M1;i++)
    {
      while(P2+1<M2&&Q2[P2+1].Y<Q1[i].Y+Len)P2++;
      while(P1<M2&&Q2[P1].Y<Q1[i].Y-Len)P1++;
      for(int j=P1;j<=P2;j++)
        {
          double Tmp=Calc_Dist(Q1[i],Q2[j]);
          if(Tmp<T.Dist){T.Dist=Tmp;T.V1=Q1[i].Num;T.W1=Q1[i].W;T.V2=Q2[j].Num;T.W2=Q2[j].W;}
        }
    }
  return T;
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int N=GetNumber();
  for(int i=0;i<N;i++)
    {
      P[i].X=GetNumber();P[i].Y=GetNumber();
      P[i].W=((P[i].X>=0)?1:2)+((P[i].Y>=0)?0:2);
      P[i].Num=i+1;
      P[i].X=abs(P[i].X);P[i].Y=abs(P[i].Y);
    }
  sort(P,P+N,Cmp);
  AnsType Ans=Calc(0,N-1);
  printf("%d %d %d %d\n",Ans.V1,Ans.W1,Ans.V2,5-Ans.W2);
  return 0;
}
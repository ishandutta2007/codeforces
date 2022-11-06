//program 109D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

bool Lucky(int T)
{
  if(!T)return true;
  if(T%10!=4&&T%10!=7)return false;
  return Lucky(T/10);
}

int X[100000],Sorted[100000],Sx[200000],Sy[200000];
map<int,set<int> > Set;

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)cin>>X[i];
  bool Flag=true;
  for(int i=1;Flag&&i<N;i++)Flag=(X[i]>=X[i-1]);
  if(Flag){cout<<0<<endl;return 0;}
  int T=-1;for(int i=0;T==-1&&i<N;i++)if(Lucky(X[i]))T=i;
  if(T==-1){cout<<-1<<endl;return 0;}
  for(int i=0;i<N;i++)Sorted[i]=X[i];
  sort(Sorted,Sorted+N);
  int Target=0;while(Sorted[Target]!=X[T])Target++;
  for(int i=0;i<N;i++)if(i!=T)Set[X[i]].insert(i);
  int Total=0;
  for(int i=0;i<N;i++)
    if(i!=Target)
      if(X[i]==Sorted[i])
        Set[X[i]].erase(i);
      else
        {
          if(T!=i){Sx[Total]=T;Sy[Total]=i;Total++;}
          Set[X[i]].erase(i);Set[X[i]].insert(T);
          swap(X[T],X[i]);T=i;
          if(X[i]==Sorted[i])continue;
          int P=*Set[Sorted[i]].lower_bound(-1);
          Sx[Total]=P;Sy[Total]=T;Total++;
          swap(X[T],X[P]);T=P;
          Set[X[i]].erase(P);
        }
  cout<<Total<<endl;
  for(int i=0;i<Total;i++)cout<<Sx[i]+1<<' '<<Sy[i]+1<<endl;
  return 0;
}
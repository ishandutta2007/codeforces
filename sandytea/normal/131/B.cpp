//program 131B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
  int N;cin>>N;multiset<int> List;
  for(int i=0;i<N;i++){int X;scanf("%d",&X);List.insert(X);}
  long long T=List.count(0),Ans=T*(T-1)/2;
  for(int i=1;i<=10;i++)
    {
      long long X=List.count(i),Y=List.count(-i);
      Ans+=X*Y;
    }
  cout<<Ans<<endl;
  return 0;
}
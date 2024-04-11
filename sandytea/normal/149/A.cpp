//program 149A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
  int N;cin>>N;
  priority_queue<int> A;
  for(int i=0;i<12;i++){int X;cin>>X;A.push(X);}
  int Ans=0;
  while(N>0&&!A.empty()){N-=A.top();A.pop();Ans++;}
  if(N>0)Ans=-1;cout<<Ans<<endl;
  return 0;
}
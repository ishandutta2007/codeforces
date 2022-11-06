//program 104A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  if(N<=10||N>21)cout<<0<<endl;
  else if(N==20)cout<<15<<endl;
  else cout<<4<<endl;
  return 0;
}
//program 108A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int HH,MM;char T;cin>>HH>>T>>MM;
  while(MM++,HH+=MM/60,MM%=60,HH%=24,HH!=(MM%10)*10+MM/10);
  cout<<HH/10<<HH%10<<':'<<MM/10<<MM%10<<endl;
  return 0;
}
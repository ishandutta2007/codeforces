//program 98A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int Count[6];
  memset(Count,0,sizeof(Count));
  for(int i=0;i<6;i++)
    {
	  char c=getchar();
	  if(c=='R')Count[0]++;
	  if(c=='O')Count[1]++;
	  if(c=='Y')Count[2]++;
	  if(c=='G')Count[3]++;
	  if(c=='B')Count[4]++;
	  if(c=='V')Count[5]++;
	}
  sort(Count,Count+6);
  if(Count[5]==6)cout<<1<<endl;
  if(Count[5]==5)cout<<1<<endl;
  if(Count[5]==4)cout<<2<<endl;
  if(Count[5]==3&&Count[4]==3)cout<<2<<endl;
  if(Count[5]==3&&Count[4]==2)cout<<3<<endl;
  if(Count[5]==3&&Count[4]==1)cout<<5<<endl;
  if(Count[5]==2&&Count[3]==2)cout<<6<<endl;
  if(Count[5]==2&&Count[4]==2&&Count[3]==1)cout<<8<<endl;
  if(Count[5]==2&&Count[4]==1)cout<<15<<endl;
  if(Count[5]==1)cout<<30<<endl;
  return 0;
}
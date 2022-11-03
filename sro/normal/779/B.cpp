#include <cstdio>
#include <iostream>
#include <string>
#define FOR(a,b) for(a=0;a<(int)(b);a++)
using namespace std;

int k,cnt=0,ct0=0;
string c;
bool start=false;
int main()
{
	cin>>c>>k;
	int i,j;
	for(int i=0;i<c.size();i++)if(c[i]=='0')ct0++;
	if(ct0<k)return printf("%d",(int)c.size()-1),0;
	ct0=0;
	for(i=(int)c.size()-1;i>=0&&ct0<k;i--)
	{
		if(c[i]!='0')cnt++;
		else ct0++;
	}
	printf("%d",cnt);
	return 0;
}
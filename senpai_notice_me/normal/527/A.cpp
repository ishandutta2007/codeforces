//File name: .cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long a,b;
long long Deal(long long x,long long y)
{
	if(!y)
	    return 0;
	long long ret=0;
	ret+=x/y+Deal(y,x%y);
	return ret;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>a>>b;
	if(a<b)
	    swap(a,b);
	cout<<Deal(a,b);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
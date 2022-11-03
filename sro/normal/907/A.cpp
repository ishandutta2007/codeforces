#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int v1,v2,v3,v4,vm;

int main()
{
	cin>>v1>>v2>>v3>>vm;
	v1=2*v1;
	v2=2*v2;if(v2==v1)v2--;
	v4=2*v3;if(v3==v1)v4--;if(v3==v2)v4--;
	if(2*vm<v4)v4=2*vm;
	if(v4<v3)return puts("-1"),0;
	if(2*vm<v4||2*vm>=v2||2*vm>=v1)return puts("-1"),0;
	if(v4<vm)return puts("-1"),0;
	cout<<v1<<endl;
	cout<<v2<<endl;
	cout<<v4<<endl;
	return 0;
}
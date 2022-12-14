#include<bits/stdc++.h>
#define gg return puts("NO"),0
using namespace std;


int main(){
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x)gg;
	a-=x;
	if(a+b<y)gg;
	if(a<y)y-=a,a=0;
	else a-=y,y=0;
	b-=y;
	if(a+b+c<z)gg;
	puts("YES");
}
#include<bits/stdc++.h>
using namespace std;

int a,b,c,A,B,n;
char s[5];
int main(){
	scanf("%d",&n);
	A=0;B=(1<<10)-1;
	for(int i=0;i<n;i++){
		int x;scanf("%s%d",s,&x);
		if(s[0]=='&'){A&=x;B&=x;}
		else if(s[0]=='|'){A|=x;B|=x;}
		else {A^=x;B^=x;}
	}
	for(int i=0;i<10;i++){
		int u=A>>i&1,v=B>>i&1;
		if(!u&&!v);
		else if(!u&&v)a|=1<<i;
		else if(u&&!v)a|=1<<i,b|=1<<i;
		else c|=1<<i;
	}
	printf("3\n& %d\n^ %d\n| %d\n",a,b,c);
	return 0;
}
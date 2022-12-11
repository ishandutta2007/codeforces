#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

int main(){
	char s[105];
	int n;
	n=get();
	scanf("%s",s+1);
	int cntl,cntr,cntu,cntd;
	cntl=cntr=cntu=cntd=0;
	fo(i,1,n){
		if (s[i]=='U')cntu++;
		if (s[i]=='D')cntd++;
		if (s[i]=='L')cntl++;
		if (s[i]=='R')cntr++;
	}
	printf("%d\n",min(cntl,cntr)*2+min(cntu,cntd)*2);
	return 0;
}
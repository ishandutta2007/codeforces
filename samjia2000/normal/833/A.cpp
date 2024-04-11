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
#define se second
#define fi first

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
	for(int n=get();n;n--){
		int a=get(),b=get();
		LL t=a;
		t=t*b;
		LL v=exp(log(t)/3);
		if (v*v*v>t)v--;
		if (v*v*v<t)v++;
		bool ans=1;
		if (v*v*v!=t)ans=0;
		if(a%v!=0||b%v!=0)ans=0;
		if (ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if(ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

int main(){
	int n=get();
	int w=0;char s[10];
	bool ans=1;
	fo(i,1,n){
		int l=get();scanf("%s",s+1);
		if ((s[1]=='E'||s[1]=='W')&&(w==0||w==20000)){ans=0;continue;}
		if (s[1]=='E'||s[1]=='W')continue;
		if (s[1]=='S'){
			if (w+l>20000)ans=0;
			w+=l;
		}
		if (s[1]=='N'){
			if (w-l<0)ans=0;
			w-=l;
		}
	}
	if (w!=0)ans=0;
	if (ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}
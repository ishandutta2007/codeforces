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

const int N = 8010;

char s[N];
int n;
int f[N],p[N];
int v[N];

int main(){
	char ch;
	while(ch=getchar(),ch<'a'||ch>'z');
	s[n=1]=ch;
	while(ch=getchar(),ch>='a'&&ch<='z')s[++n]=ch;
	v[1]=1;
	v[10]=2;
	v[100]=3;
	v[1000]=4;
	fo(i,1,n)
	if (!v[i])v[i]=v[i-1];
	f[0]=0;
	fo(i,1,n)f[i]=1e+9;
	fo(i,0,n-1){
		int w=0;
		fo(j,2,n-i){
			while(w&&s[i+w+1]!=s[i+j])w=p[w];
			if (s[i+w+1]==s[i+j])w++;
			p[j]=w;
		}
		fo(j,1,n-i)
		if (j%(j-p[j])==0)f[i+j]=min(f[i+j],f[i]+j-p[j]+v[j/(j-p[j])]);
		else f[i+j]=min(f[i+j],f[i]+1+j);
	}
	printf("%d\n",f[n]);
	return 0;
}
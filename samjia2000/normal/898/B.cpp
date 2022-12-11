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
typedef pair<LL,LL> pir;

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

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

pir exgcd(int a,int b){
	if (b==0)return make_pair(1,0);
	pir u=exgcd(b,a%b);
	return make_pair(u.second,(u.first-u.second*(a/b)));
}

int main(){
	int n=get(),a=get(),b=get();
	int d=gcd(n,gcd(a,b));
	n/=d;a/=d;b/=d;
	if (gcd(a,b)!=1)return printf("NO\n"),0;
	pir u=exgcd(a,b);
	LL A=u.first,B=u.second;
	A=(A%b+b)%b;
	A=A*n%b;
	B=(1ll*n-A*a)/b;
	if (A>=0&&B>=0)printf("YES\n%I64d %I64d\n",A,B);
	else printf("NO\n");
	return 0;
}
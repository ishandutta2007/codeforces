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

const int N = 3e5+5;
const LL INF = 1e12;

int n,m;
char s[3];
char col[N];
LL w[N];
LL ans;

LL max(LL x,LL y){return x>=y?x:y;}
LL min(LL x,LL y){return x<=y?x:y;}

int main(){
	n=get();
	fo(i,1,n){
		scanf("%I64d%s",&w[i],s+1);
		col[i]=s[1];
	}
	w[0]=-INF;w[n+1]=INF;col[0]=col[n+1]='G';
	int lst=0;
	ans=0;
	fo(i,1,n+1)
	if (col[i]=='G'){
		if (lst==0&&i==n+1){
			LL mx=-INF,mi=INF;
			fo(x,1,n)if (col[x]=='R')mx=max(mx,w[x]),mi=min(mi,w[x]);
			ans=ans+max(0,mx-mi);
			mx=-INF,mi=INF;
			fo(x,1,n)if (col[x]=='B')mx=max(mx,w[x]),mi=min(mi,w[x]);
			ans=ans+max(0,mx-mi);
			continue;
		}
		LL mx=0,nv=0,mi=(w[i]-w[lst])*2;
		for(int x=lst+1,y=lst;x<=i;x++)
		if (col[x]=='G'||col[x]=='R'){mx=max(mx,w[x]-w[y]);y=x;}
		nv+=mx;mx=0;
		for(int x=lst+1,y=lst;x<=i;x++)
		if (col[x]=='G'||col[x]=='B'){mx=max(mx,w[x]-w[y]);y=x;}
		mi=min(mi,(w[i]-w[lst])*3-mx-nv);
		if (lst==0||i==n+1)mi=mi-(w[i]-w[lst]);
		ans=ans+mi;
		lst=i;
	}
	printf("%I64d\n",ans);
	return 0;
}
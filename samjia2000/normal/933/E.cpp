#include<bits/stdc++.h>

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

int n;
int a[N];
LL f[N];
int lst[N];

int ans[N*5],m;
int all;

void op(int x){
	if (x<1||x>=n)return;
	if (!a[x]||!a[x+1])return;
	int v=min(a[x],a[x+1]);
	a[x]-=v,a[x+1]-=v;
	ans[++m]=x;
	all+=v;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)f[i]=1e18;
	f[1]=a[1];lst[1]=1;
	f[2]=a[1]+max(a[2]-a[1],0);lst[2]=2;
	fo(i,2,n){
		if (i>1&&f[i]>f[i-2]+a[i]){
			f[i]=f[i-2]+a[i];
			lst[i]=1;
		}
		if (i>2&&f[i]>f[i-3]+a[i-1]+max(a[i]-a[i-1],0)){
			f[i]=f[i-3]+a[i-1]+max(a[i]-a[i-1],0);
			lst[i]=2;
		}
	}
	int x=f[n]<f[n-1]?n:n-1;
	for(;x>0;x-=lst[x]+1){
		if (lst[x]==1){
			op(x);
			op(x-1);
		}
		else{
			op(x-1);
			op(x);
			op(x-2);
		}
	}
	printf("%d\n",m);
	fo(i,1,m)printf("%d\n",ans[i]);
	return 0;
}
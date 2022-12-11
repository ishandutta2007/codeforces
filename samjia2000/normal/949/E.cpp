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

const int N = 100005;
const int L = 262144;

int n,a[N];
int d[20][N];
int ans[40];
int key[40];

void dfs(int x){
	if (d[x-1][0]==1){
		if (d[x-1][1]!=0)return;
		if(key[0]<ans[0]){
			ans[0]=key[0];
			fo(i,1,key[0])ans[i]=key[i];
		}
		return;
	}
	int mv=1<<19;
	fo(i,1,d[x-1][0]){
		int v=abs(d[x-1][i]);
		if ((v&-v)>0)mv=min(mv,v&-v);
	}
	if (mv==(1<<19))return;
	key[++key[0]]=mv;
	d[x][0]=0;
	fo(i,1,d[x-1][0]){
		if ((d[x-1][i]&mv)>0)d[x][++d[x][0]]=d[x-1][i]-mv;
		else d[x][++d[x][0]]=d[x-1][i];
	}
	sort(d[x]+1,d[x]+1+d[x][0]);
	int k=1;
	fo(i,2,d[x][0])if (d[x][i]!=d[x][i-1])d[x][++k]=d[x][i];
	d[x][0]=k;
	dfs(x+1);
	key[key[0]]=-mv;
	d[x][0]=0;
	fo(i,1,d[x-1][0]){
		if ((d[x-1][i]&mv)>0)d[x][++d[x][0]]=d[x-1][i]+mv;
		else d[x][++d[x][0]]=d[x-1][i];
	}
	sort(d[x]+1,d[x]+1+d[x][0]);
	k=1;
	fo(i,2,d[x][0])if (d[x][i]!=d[x][i-1])d[x][++k]=d[x][i];
	d[x][0]=k;
	dfs(x+1);
	key[0]--;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	ans[0]=100;
	a[++n]=0;
	sort(a+1,a+1+n);
	int n_=1;
	fo(i,2,n)if (a[i]!=a[i-1])a[++n_]=a[i];
	n=n_;
	fo(i,1,n)d[0][i]=a[i];
	d[0][0]=n;
	dfs(1);
	printf("%d\n",ans[0]);
	fo(i,1,ans[0])printf("%d ",ans[i]);
	return 0;
}
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
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
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 5010;

int a[N];
int n;
int f[N];
int lef[N],rig[N];
int w[N];
int vis[N],tim;

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)w[a[i]]=i;
	fo(i,1,n)rig[i]=w[a[i]];
	fd(i,n,1)w[a[i]]=i;
	fo(i,1,n)lef[i]=w[a[i]];
	int ans=0;
	fo(i,1,n){
		f[i]=0;
		int l=lef[i],r=rig[i];
		tim++;
		int val=a[i];
		vis[a[i]]=tim;
		if (r<=i)
			fd(j,i-1,0){
				if (l>j)f[i]=max(f[i],f[j]+val);
				if (!j)break;
				l=min(l,lef[j]);
				if (rig[j]>i)break;
				if (vis[a[j]]<tim){
					vis[a[j]]=tim;
					val=val^a[j];
				}
			}
		f[i]=max(f[i],f[i-1]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
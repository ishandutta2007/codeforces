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

struct section{
	int l,r,w;
}sec[100];
int ans[100];
int m,n;
bool pd[100];

int main(){
	scanf("%d%d",&m,&n);
	int l=1,r=m;
	fo(i,1,n){
		int mid=(l+r)/2;
		if (mid>m)mid=m;
		if (mid<1)mid=1;
		printf("%d\n",mid);fflush(stdout);
		int c=get();
		if(c==0)return 0;
		ans[i]=c;
		sec[i].l=l;sec[i].r=r;sec[i].w=mid;
		if(c==1)r=mid-1;
		else l=mid+1;
	}
	fo(i,1,n){
		printf("%d\n",sec[i].r);fflush(stdout);
		int c=get();
		if(c==0)return 0;
		if(c==-1){
			pd[i]=0;
			if(ans[i]==1){
				fo(j,i+1,n)
				if(ans[j]==-1)pd[j]=1;else pd[j]=0;
				l=sec[i].w+1,r=sec[i].r;
			}
			else{
				fo(j,i+1,n)
				if(ans[j]==1)pd[j]=1;else pd[j]=0;
				l=sec[i].l,r=sec[i].w-1;
			}
			for(int x=i%n+1;;x=x%n+1){
				int mid=(l+r)/2;
				printf("%d\n",mid);fflush(stdout);
				int c=get();
				if(!pd[x])c=-c;
				if(c==0)return 0;
				if (c==1)r=mid-1;
				else l=mid+1;
			}
			return 0;
		}
		pd[i]=1;
	}
	while(1){
		int mid=(l+r)/2;
		printf("%d\n",mid);fflush(stdout);
		int c=get();
		if(c==0)return 0;
		if (c==1)r=mid-1;
		else l=mid+1;
	}
	return 0;
}
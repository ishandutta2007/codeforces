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

const int N = 10005;

int n,l,r;
int a0[N],a1[N];
int k0,k1;
int a[N];
bool import[N];
bool pd[N];
int pre[N];
int sum[N];

int main(){
	n=get();l=get();r=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)import[i]=get();
	k0=k1=0;
	fo(i,1,n)if (import[i])a1[++k1]=a[i];else a0[++k0]=a[i];
	int len=0;
	fo(i,1,n)len=len+a[i];
	pd[0]=1;
	fo(i,1,k0){
		fd(j,10000,a0[i])pd[j]|=pd[j-a0[i]];
	}
	fo(i,1,10000){
		pre[i]=pre[i-1];
		if (pd[i])pre[i]=i;
	}
	//fo(i,0,10000)pd[i]=0;
	//pd[0]=1;
	sort(a1+1,a1+1+k1);
	fo(i,1,k1)sum[i]=sum[i-1]+a1[i];
	int ans=0;
	fd(i,k1,1){
		if (sum[i-1]<=r){
			int ps=sum[i-1];
			int d=pre[r-sum[i-1]];
			if (d+ps>=l&&d+ps<=r){
				int L=1,R=i-1,ret=0;
				while(L<=R){
					int mid=(L+R)/2;
					if (ps-sum[mid]+d>=l)ret=mid,L=mid+1;
					else R=mid-1;
				}
				ans=max(ans,ret+1);
			}
		}
		if (sum[i]<=r){
			int d=pre[r-sum[i]];
			if (d+sum[i]>=l&&d+sum[i]<=r){
				int L=1,R=i,ret=0;
				while(L<=R){
					int mid=(L+R)/2;
					if (sum[i]-sum[mid]+d>=l)ret=mid,L=mid+1;
					else R=mid-1;
				}
				ans=max(ans,ret);
			}
			
		}
		fd(j,10000,a1[i])pd[j]|=pd[j-a1[i]];
		fo(j,1,10000){
			pre[j]=pre[j-1];
			if (pd[j])pre[j]=j;
		}
	}
	printf("%d\n",ans);
	return 0;
}
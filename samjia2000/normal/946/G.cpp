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

const int N = 200005;
const int INF = 1e9;

int n;
int a[N];
int key[N],k;
int tree1[N],tree2[N];

int getw(int x){
	int l=1,r=k,ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (key[mid]<=x)ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}

int val1[N],val2[N];

void add1(int x,int v){for(;x<=k;x+=x&-x)tree1[x]=max(tree1[x],v);}
void add2(int x,int v){for(;x<=k;x+=x&-x)tree2[x]=max(tree2[x],v);}
int getv1(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,tree1[x]);return ret;}
int getv2(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,tree2[x]);return ret;}

int main(){
	n=get();
	fo(i,1,n){
		a[i]=get();
		key[++k]=a[i]-i;
	}
	sort(key+1,key+1+k);
	int k_=1;
	fo(i,2,k)if (key[i]>key[i-1])key[++k_]=key[i];
	k=k_;
	int ans=0;
	fo(i,1,k)tree1[i]=tree2[i]=0;
	fo(i,1,n){
		int w=getw(a[i]-i);
		val1[i]=getv1(w)+1;
		val2[i]=max(val2[i],1);
		if (i<n)val2[i+1]=getv1(getw(a[i+1]-i))+1;
		add1(w,val1[i]);
		if (i>1){
			val2[i]=max(val2[i],getv2(w)+1);
			add2(w,val2[i]);
		}
	}
	ans=n;
	fo(i,1,n){
		ans=min(ans,n-1-val1[i]);
		if (i>1)ans=min(ans,n-1-val2[i]);
	}
	ans=max(ans,0);
	printf("%d\n",ans);
	return 0;
}
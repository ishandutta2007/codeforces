#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int INF = 2.1e9;
const int N = 2e5+5;

int n,m,ta,tb,k;
int a[N],b[N];

int main(){
	n=get();m=get();ta=get();tb=get();k=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,m)b[i]=get();
	int ans=0;
	fo(i,0,min(n,k)){
		int j=min(m,k-i);
		if(i==n||j==m||a[i+1]+ta>b[m-j]){
			ans=INF;
		}
		else{
			int l=1,r=m,w=0;
			for(;l<=r;){
				int mid=(l+r)/2;
				if (b[mid]>=a[i+1]+ta)w=mid,r=mid-1;
				else l=mid+1;
			}
			ans=max(ans,b[w+j]+tb);
		}
	}
	if (ans==INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}
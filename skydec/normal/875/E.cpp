#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int s1,s2;
int n,a[N];
int mi[17][N*2],ma[17][N*2];
int BB[N*2];
int getmi(int l,int r){
	return min(mi[BB[r-l+1]][l],mi[BB[r-l+1]][r-(1<<BB[r-l+1])+1]);
}
int getma(int l,int r){
	return max(ma[BB[r-l+1]][l],ma[BB[r-l+1]][r-(1<<BB[r-l+1])+1]);
}
void init(){
	rep(j,0,16)rep(i,(1<<j),(1<<(j+1))-1)BB[i]=j;

	rep(i,1,n){
		mi[0][i]=ma[0][i]=a[i];
	}
	rep(j,1,16)rep(i,1,n-(1<<j)+1){
		mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
		ma[j][i]=max(ma[j-1][i],ma[j-1][i+(1<<(j-1))]);
	}
}
bool f[N],g[N];
bool check(int S){
	rep(i,0,n)f[i]=g[i]=0;
	f[0]=g[0]=1;
	//f:s1
	//g:s2
	int maf,mag;
	maf=mag=0;
	rep(i,0,n-1){
		bool f1=(i<=maf);
		bool f2=(i<=mag);
		//printf("%d %d %d\n",i,maf,mag);
		if(f1){
			int now=a[i];
			if(i==0)now=s1;
			int l=i+1;int r=n;
			int rt=0;
			while(l<r){
				int mid=(l+r)>>1;
				if((abs(getma(i+1,mid)-now)>S)||(abs(getmi(i+1,mid)-now)>S))r=mid;
				else l=mid+1,rt=mid;
			}
			if(!(abs((getma(i+1,l)-now)>S)||(abs(getmi(i+1,l)-now)>S)))rt=l;

			//printf("%d %d %d\n",now,S,rt);
			mag=max(mag,rt);
		}
		if(f2){
			int now=a[i];
			if(i==0)now=s2;
			int l=i+1;int r=n;
			int rt=0;
			while(l<r){
				int mid=(l+r)>>1;
				if((abs(getma(i+1,mid)-now)>S)||(abs(getmi(i+1,mid)-now)>S))r=mid;
				else l=mid+1,rt=mid;
			}
			if(!((abs(getma(i+1,l)-now)>S)||(abs(getmi(i+1,l)-now)>S)))rt=l;

			//printf("_%d %d %d\n",now,S,rt);
			maf=max(maf,rt);
		}
	}
	return (maf==n)||(mag==n);
}
int main(){
	scanf("%d%d%d",&n,&s1,&s2);
	rep(i,1,n)scanf("%d",&a[i]);
	init();
	int L=abs(s1-s2);int R=1000000000;
	int ans=0;
	while(L<R){
		int mid=(L+R)>>1;
		if(check(mid))ans=mid,R=mid;
		else L=mid+1;
	}
	if(check(L))ans=L;
	cout<<ans<<endl;
	return 0;
}
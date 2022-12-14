#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n,a[1000005];
pii f[1<<21];

void merge(pii &a,const pii &b){
	if(b.X>a.X)a.Y=a.X,a.X=b.X;
	else if(b.X>a.Y)a.Y=b.X;
	if(b.Y>a.X)a.Y=a.X,a.X=b.Y;
	else if(b.Y>a.Y)a.Y=b.Y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		merge(f[a[i]],mp(i,0));
	}
	for(int d=0;d<=20;++d)
		for(int s=0;s<1<<21;++s)
			if(!(s>>d&1))merge(f[s],f[s^(1<<d)]);
	int ans=0;
	for(int i=n-2;i;--i){
		int mx=0,now=0;
		for(int j=20;j>=0;--j)
			if(a[i]>>j&1)
				mx|=1<<j;
			else{
				pii tmp=f[now|(1<<j)];
				if(tmp.first>=i&&tmp.second>=i)
					mx|=1<<j,now|=1<<j;
			}
		ans=max(ans,mx);
	}
	printf("%d\n",ans);
	return 0;
}
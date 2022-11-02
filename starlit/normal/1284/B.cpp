#include<bits/stdc++.h>
const int N=1000006;
using namespace std;
int n,m,x,mx[N],mn,ti[N];
long long ans;
bool fl;
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		mn=1e7;
		fl=0;
		for(;m--;){
			scanf("%d",&x);
			if(mn<x)fl=1;
			mn=min(mn,x),mx[i]=max(mx[i],x);
		}
		if(fl)mn=-1,mx[i]=N-1;
		ti[mn+1]++;
	}
	for(int i=1;i<N;i++)
	ti[i]+=ti[i-1];
	for(int i=0;i<n;i++)
	ans+=ti[mx[i]];
	printf("%lld",ans);
}
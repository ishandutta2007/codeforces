#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int F[MN],val[MN],n,k,a,b;
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)F[i]=i;
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a,&b);
		int fa=Find(a),fb=Find(b);
		if(fa!=fb){
			F[fa]=fb;
			val[fb]+=val[fa]+1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(Find(i)==i)ans+=val[i];
	}
	printf("%d",k-ans);
	return 0;
}
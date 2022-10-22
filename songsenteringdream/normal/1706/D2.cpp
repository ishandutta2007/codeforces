#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10;
int T,n,k,c[o],ans,st[o],tp;
int main(){
	for(scanf("%d",&T),st[0]=o*100;T--;printf("%d\n",ans)){
		scanf("%d%d",&n,&k);ans=o;
		for(int i=0;i<o;++i) c[i]=i+1;
		for(int a;n--;tp=0){
			scanf("%d",&a);
			for(int i=1;i<=k&&i<=a;i=a/st[tp]+1) st[++tp]=a/i;
			st[tp+1]=0;
			for(int i=tp;i+1;--i) c[st[i+1]]=max(c[st[i+1]],st[i]);
		}
		for(int l=1,r=c[0];l<o;r=max(r,c[l++])) ans=min(ans,r-l);
	}
	return 0;
}
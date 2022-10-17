#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 400000
int v11[Maxn+5],v10[Maxn+5],v01[Maxn+5],v00[(Maxn<<1)+5];
bool cmp(int p,int q){
	return p>q;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	int ans=0;
	scanf("%d",&n);
	int x,v;
	int len11=0,len10=0,len01=0,len00=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&v);
		if(x==11){
			v11[++len11]=v;
			ans+=v;
		}
		else if(x==10){
			v10[++len10]=v;
		}
		else if(x==1){
			v01[++len01]=v;
		}
		else{
			v00[++len00]=v;
		}
	}
	sort(v10+1,v10+1+len10,cmp);
	sort(v01+1,v01+1+len01,cmp);
	int min_len=mn(len10,len01);
	for(int i=1;i<=min_len;i++){
		ans+=v10[i]+v01[i];
	}
	if(len10>len01){
		for(int i=min_len+1;i<=len10;i++){
			v00[++len00]=v10[i];
		}
	}
	else{
		for(int i=min_len+1;i<=len01;i++){
			v00[++len00]=v01[i];
		}
	}
	int all=(len11+min_len)<<1;
	int next=all-len11-(min_len<<1);
	sort(v00+1,v00+1+len00,cmp);
	for(int i=1;i<=next;i++){
		ans+=v00[i];
	}
	printf("%d\n",ans);
	return 0;
}
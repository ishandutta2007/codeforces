#include<bits/stdc++.h>
const int N=503;
using namespace std;
int n,sz[N],no[N],u[N],v[N],t,l,r,mi,tp,ls;
bool vis[N];
int main(){
	scanf("%d",&n);
	sz[1]=n,no[1]=1;
	if(n<3)return printf("ANSWER\n1 2"),0;
	for(int i=2;i<=n;i++){
		no[i]=i;
		printf("1\n1\n%d\n",n-2);
		for(int j=2;j<=n;j++)
		if(j^i)printf("%d ",j);
		printf("\n%d\n",i);
		fflush(stdout),scanf("%d",sz+i);
	}
	sort(no+1,no+n+1,[](int x,int y){return sz[x]<sz[y];});
	vis[no[1]]=1;
	for(int i=2;i<n;i++){
		//cerr<<"ini "<<no[i]<<"=====\n";
		for(l=1;;){
			for(;l<=n&&!vis[l];l++);
			if(l>n)break;
			for(r=n,ls=n+1;l<=r;){
				mi=l+r>>1;
				printf("1\n1\n");
				tp=0;
				for(int j=1;j<=mi;j++)
				if(vis[j])tp++;
				printf("%d\n",tp);
				for(int j=1;j<=mi;j++)
				if(vis[j])printf("%d ",j);
				printf("\n%d\n",no[i]);
				fflush(stdout),scanf("%d",&tp);
				if(tp)ls=mi,r=mi-1;
				else l=mi+1;
			}
			//cerr<<"get "<<ls<<endl;
			if(ls<=n)u[t]=no[i],v[t++]=ls,vis[ls]=0;
			l=ls;
		}vis[no[i]]=1;
	}
	for(int i=2;i<=n;i++)
	if(vis[i])u[t]=1,v[t++]=i;
	puts("ANSWER");
	for(int i=0;i<t;i++)
	printf("%d %d\n",u[i],v[i]);
}
#include<bits/stdc++.h>
const int N=3003;
using namespace std;
long long ans,sum;
int n,m,d,k,ax[N],ay[N],na[N],nb[N],
sa[N],sb[N],pre[N],nxt[N],t;
bool cmpa(int x,int y){
	return ay[x]<ay[y];
}
bool cmpb(int x,int y){
	return ax[x]>ax[y];
}
void dfs(int x,int d){
	if(d>k||x<0)return;
//	cerr<<"mdf "<<x<<":"<<sa[x]<<'*'<<sb[x]<<endl;
	sum-=sa[x]*sb[x];
	dfs(pre[x],d+1);
	sb[x]=sb[nxt[x]];
	if(d==1)sa[x]+=sa[nxt[x]];
	if(d)sum+=sa[x]*sb[x];
//	cerr<<"to "<<x<<":"<<sa[x]<<'*'<<sb[x]<<endl;
}
int main(){
//	freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&d,&k);
	for(int i=1;i<=d;i++)
	scanf("%d%d",ax+i,ay+i);
	ay[d+1]=m+1;
	for(int i=1;i<=n;i++){
		sum=t=0;
		for(int j=1;j<=d;j++)
		if(ax[j]>=i)t++,na[t]=nb[t]=j;
		na[++t]=d+1;
		sort(na+1,na+t,cmpa);
		sort(nb+1,nb+t,cmpb);
		for(int j=0,s;j<t;j++){
			if(s=na[j])
			pre[s]=na[j-1];
			else pre[s]=-1;
			nxt[s]=na[j+1],
			sa[s]=ay[na[j+1]]-ay[s],
			sb[s]=j+k<t?m+1-ay[na[j+k]]:0;
			sum+=sa[s]*sb[s];
		}
		for(int j=n,l=1;j>=i;j--){
			for(int s;l<t&&ax[nb[l]]>j;l++){
				s=nb[l],dfs(s,0);
				//cerr<<"del "<<s<<endl;
				nxt[pre[s]]=nxt[s];
				pre[nxt[s]]=pre[s];
			}
		//	cerr<<"["<<i<<','<<j<<"]"<<sum<<endl;
			ans+=sum;
		}
	}printf("%lld",ans);
}
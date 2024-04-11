#include<bits/stdc++.h>
using namespace std;
const int M=200005;
int n,m,l[M],r[M],id[M],st[M],top,ans[M],tot;
bool cmp(int p,int q){return l[p]==l[q]?r[p]>r[q]:l[p]<l[q];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",l+i,r+i),id[i]=i,r[i]+=l[i]-1;
	sort(id+1,id+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(i>1&&l[id[i]]==l[id[i-1]]){
			ans[++tot]=id[i];
			continue;
		}
		if(top&&r[id[i]]<=r[st[top]]){
			ans[++tot]=id[i];
			continue;
		}
		while(top>1&&r[st[top-1]]>=l[id[i]]-1)ans[++tot]=st[top--];
		st[++top]=id[i];
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d%c",ans[i]," \n"[i==tot]);
	return 0;
}
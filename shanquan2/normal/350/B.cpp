#include<cstdio>
#include<cstring>
using namespace std;

int tp[100000],a[100000];
int vis[100000],v[100000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&tp[i]);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
		if(a[i]>=0)vis[a[i]]++;
	}
	int ans=-1,max=0;
	for(int i=0;i<n;i++)
		if(tp[i]==1){
			int k=i,len=1;
			while(a[k]>=0 && vis[a[k]]==1){
				len++;
				k=a[k];
			}
			if(len>max)max=len,ans=i;
		}
	printf("%d\n",max);
	int k=ans,len=1;
	v[0]=k;
	while(a[k]>=0 && vis[a[k]]==1){
		k=a[k];
		v[len++]=k;
	}
	for(int i=len-1;i>0;i--)printf("%d ",v[i]+1);printf("%d\n",v[0]+1);
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100];
bool vis[100]={0};
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
//	for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
	int ans=0;
	for(int i=0;i<n;i++)if(!vis[i]){
//		vis[i]=1;
		int j=i,k=0;
		while(j<n){
			while(j<n && (vis[j] || a[j]<k))j++;
			if(j>=n)break;
			vis[j]=1;j++;k++;
		}
		ans++;
//		for(int i=0;i<n;i++)printf("%d ",vis[i]);printf("\n");
	}
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
int a[Maxn+5];
bool vis[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0;
	int tmp,tol=n;
	while(tol){
		tmp=0;
		for(int i=1;i<=n;i++){
			if(tmp<=a[i]&&!vis[i]){
				vis[i]=1;
				tmp++;
				tol--;
			}
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
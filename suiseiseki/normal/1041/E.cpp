#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 1000
int a[Maxn+5],b[Maxn+5];
bool visit[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]!=n){
			puts("NO");
			return 0;
		}
	}
	sort(a+1,a+n);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			visit[a[i]]=1;
			b[i]=a[i];
		}
		else{
			for(int j=1;j<=a[i];j++){
				if(!visit[j]){
					b[i]=j;
					visit[j]=1;
					break;
				}
				if(j==a[i]){
					puts("NO");
					return 0;
				}
			}
		}
	}
	b[n]=n;
	puts("YES");
	for(int i=1;i<n;i++){
		printf("%d %d\n",b[i],b[i+1]);
	}
	return 0;
}
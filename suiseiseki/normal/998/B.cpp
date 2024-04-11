#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
int a[Maxn+5];
int f[Maxn+5];
int num[Maxn+5];
int ab(int a){
	return a<0?-a:a;
}
int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]&1){
			f[i]=f[i-1]+1;
		}
		else{
			f[i]=f[i-1]-1;
		}
	}
	int ans=0;
	int len=0;
	for(int i=2;i<n;i++){
		if(f[i]==0){
			num[++len]=ab(a[i+1]-a[i]);
		}
	}
	sort(num+1,num+1+len);
	int now=0;
	for(int i=1;i<=len&&now+num[i]<=b;i++){
		ans++;
		now+=num[i];
	}
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=2000;
const int Maxv=1000000;
int a[Maxn+5];
int n;
int num[Maxv+5];
bool solve(int sum){
	for(int i=1;i<=(n<<1);i++){
		num[a[i]]=0;
	}
	for(int i=1;i<=(n<<1);i++){
		num[a[i]]++;
	}
	for(int i=(n<<1);i>0;i--){
		if(num[a[i]]==0){
			continue;
		}
		num[a[i]]--;
		if(sum-a[i]>a[i]||num[sum-a[i]]==0){
			return 0;
		}
		num[sum-a[i]]--;
		sum=a[i];
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+(n<<1));
	for(int i=(n<<1)-1;i>0;i--){
		if(solve(a[i]+a[n<<1])){
			puts("YES");
			printf("%d\n",a[i]+a[n<<1]);
			for(int j=1;j<=(n<<1);j++){
				num[a[j]]=0;
			}
			for(int j=1;j<=(n<<1);j++){
				num[a[j]]++;
			}
			int sum=a[i]+a[n<<1];
			for(int j=(n<<1);j>0;j--){
				if(num[a[j]]==0){
					continue;
				}
				num[a[j]]--;
				num[sum-a[j]]--;
				printf("%d %d\n",sum-a[j],a[j]);
				sum=a[j];
			}
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
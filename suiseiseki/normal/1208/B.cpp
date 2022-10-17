#include <map>
#include <cstdio>
using namespace std;
#define Maxn 2000
int n;
int a[Maxn+5];
map<int,int> mp;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	int num=0;
	int left=1,right=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
		if(mp[a[i]]==2){
			num++;
		}
	}
	if(num==0){
		puts("0");
		return 0;
	}
	int ans=n;
	while(right<n){
		right++;
		mp[a[right]]--;
		if(mp[a[right]]==1){
			num--;
		}
		while(left<=right&&num==0){
			ans=mn(ans,right-left+1);
			mp[a[left]]++;
			if(mp[a[left]]==2){
				num++;
			}
			left++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
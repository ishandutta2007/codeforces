#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 400000
int a[Maxn+5];
int n,k;
map<int,int> mp;
int find(int x){
	if(x==0){
		return 0;
	}
	return ceil(log2(x));
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=n;
	int left=1,right=0;
	int num=0;
	while(left<=n){
		while(right<=n&&find(num)*n<=k*8.0){
			right++;
			if(mp[a[right]]==0){
				num++;
			}
			mp[a[right]]++;
		}
		if(right>n||find(num)*n>k*8){
			if(mp[a[right]]==1){
				num--;
			}
			mp[a[right]]--;
			right--;
		}
		ans=min(ans,n-(right-left+1));
		if(mp[a[left]]==1){
			num--;
		}
		mp[a[left]]--;
		left++;
	}
	printf("%d\n",ans);
	return 0;
}
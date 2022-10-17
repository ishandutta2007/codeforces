#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=300000;
const int Maxk=1000000;
int n,k;
int a[Maxn+5];
int b[Maxk+5],sum[Maxn+5];
pair<int,int> f[20][Maxn+5];
void init(){
	for(int i=1;i<=n;i++){
		f[0][i]=make_pair(a[i],i);
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
}
pair<int,int> query(int l,int r){
	int k=log2(r-l+1);
	return max(f[k][l],f[k][r-(1<<k)+1]);
}
ll ans;
void calc(int left,int right){
	if(left>right){
		return;
	}
	if(left==right){
		b[sum[left]]--;
		ans++;
		return;
	}
	int mid=query(left,right).second;
	int l_1=left,r_1=mid-1,l_2=mid+1,r_2=right;
	int len_1=r_1-l_1+1,len_2=r_2-l_2+1;
	if(len_1<len_2){
		for(int i=left;i<mid;i++){
			b[sum[i]]--;
		}
		for(int i=left-1;i<mid;i++){
			ans+=b[(sum[i]+a[mid]%k)%k];
		}
		b[sum[mid]]--;
		calc(l_2,r_2);
		for(int i=l_1;i<=r_1;i++){
			b[sum[i]]++;
		}
		calc(l_1,r_1);
	}
	else{
		for(int i=mid;i<=right;i++){
			b[sum[i]]--;
		}
		b[sum[left-1]]++;
		for(int i=mid;i<=right;i++){
			ans+=b[(sum[i]-a[mid]%k+k)%k];
		}
		b[sum[left-1]]--;
		calc(l_1,r_1);
		for(int i=l_2;i<=r_2;i++){
			b[sum[i]]++;
		}
		calc(l_2,r_2);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]+a[i])%k;
		b[sum[i]]++;
	}
	init();
	calc(1,n);
	printf("%lld\n",ans-n);
	return 0;
}
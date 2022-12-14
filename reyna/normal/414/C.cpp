//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 21;
int arr[1 << Maxn];
int cur[Maxn];
ll ans[Maxn][2];
ll inv;
void merge(int l,int r,int h){
	int mid = l + r >> 1;
	int p = mid + 1;
	ll res = 0;
	for(int i = l; i <= mid;i++){
		while(p != r + 1 && arr[i] > arr[p]) p++;
		res += p - mid - 1;
	}
	ans[h][0] += res;
	inv += res;
	p = l;
	res = 0;
	for(int i = mid + 1; i <= r;i++){
		while(p != mid + 1 && arr[i] > arr[p]) p++;
		res += p - l;
	}
	ans[h][1] += res;
	return;
}
int n;
void merge_sort(int l,int r,int h = n){
	int mid = l + r >> 1;
	if(r == l) return;
	merge_sort(l,mid,h-1);
	merge_sort(mid+1,r,h-1);
	merge(l,r,h);
	inplace_merge(arr + l,arr + mid + 1,arr + r + 1);
}
int main(){
	scanf("%d",&n);
	for(int i = 0; i < (1 << n);i++) scanf("%d",&arr[i]);
	merge_sort(0,(1 << n) - 1);
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m;i++){
		int q;
		scanf("%d",&q);
		//cout << ans[q][1] << endl;
		inv = 0;
		for(int j = 0; j <= q;j++) cur[j] ^= 1;
		for(int j = 0; j <= n;j++) inv += ans[j][cur[j]];
		printf("%I64d\n",inv);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N];
vector<int> v[102];

int sum[N],pre[N*2+2];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	int mx=0, id=-1;
	for(int i=0;i<=100;i++){
		if(v[i].size() > mx) {
			mx=v[i].size(); id=i;
		}
	}
	int ans=0;
	for(int i=1;i<=100;i++) if(i!=id){
		memset(sum,0,sizeof(sum));
		memset(pre,-1,sizeof(pre));
		pre[N]=0;
		for(auto x: v[id]) sum[x]=1;
		for(auto x: v[i]) sum[x]=-1;

		for(int j=1;j<=n;j++){
			sum[j]+=sum[j-1];
			if(pre[sum[j] + N] == -1) {
				pre[sum[j] + N]=j;
			}else{
				ans=max(ans,j-pre[sum[j] + N]);
			}
		}
	}
	cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
bool vis[N];
int sum[N];
int main() {
	for(int i=2;i<N;i++){
		if(vis[i])continue;
		for(int j=i+i;j<N;j+=i){
			vis[j]=1;
		}
	}
	for(int i=1;i<N;i++){
		sum[i]=sum[i-1];
		if(vis[i]==0) {
			sum[i]++;
		}

	}
	int t; scanf("%d",&t);
	while(t--){
		int x; scanf("%d",&x);
		int y=sqrt(x);y=max(y-2,0);
		while((y+1)*(y+1)<=x) ++y;
		//printf("x=%d,y=%d\n", x,y);
		int ans=sum[x] - sum[y];
		printf("%d\n", ans + 1);
	}
	/*
	int n=200;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int> v;
			v.push_back(gcd(i,j));
			v.push_back(i/gcd(i,j));
			v.push_back(j/gcd(i,j));
			sort(v.begin(),v.end());
			if(v[0]+v[1] > v[2]) {
				vis[i]=vis[j]=1;
							if(i==13) {
				printf("%d %d\n", i,j);
				printf("%d %d %d\n", v[0],v[1],v[2]);
			}
			}

		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			printf("%d\n", i);
		}
	*/
}
/*
*/
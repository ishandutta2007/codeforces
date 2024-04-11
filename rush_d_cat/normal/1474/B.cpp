#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,x;
bool vis[N];
int main() {
	for(int i=2;i<N;i++){
		if(vis[i])continue;
		for(int j=i+i;j<N;j+=i){
			vis[j]=1;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		int a=x+1;
		while(vis[a]) ++a;
		int b=x+a;
		while(vis[b]) ++b;
		printf("%d\n", a*b);
	}
}
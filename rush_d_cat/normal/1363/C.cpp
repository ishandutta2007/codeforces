#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int t,n,x;
vector<int> g[N];
int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d%d",&n,&x);
		if(n==1) {
			printf("Ayush\n");
			continue;
		}
		int deg=0;
		for(int i=1;i<n;i++){
			int u,v; scanf("%d%d",&u,&v);
			if(u==x) {
				deg++;
			}
			if(v==x){
				deg++;
			}
		}
		if(deg==1) printf("Ayush\n");
		else {
			bool fg=(n-1)%2;
			printf("%s\n", fg==0?"Ashish":"Ayush");
		}
	}
}
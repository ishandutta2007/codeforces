#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k;
int h[N],x[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		pair<int,int> p = make_pair(h[1],h[1]);
		bool ok=true;
		for(int i=2;i<=n;i++){
			int l=h[i],r=h[i]+k-1;
			int l1=p.first-(k-1),r1=p.second+(k-1);
			int L=max(l,l1);
			int R=min(r,r1);
			if(R-L+1<=0) {
				ok=false;
				printf("NO\n");
				break;
			}
			p=make_pair(L,R);
		}
		if (ok) {
			if(h[n]<=p.second && h[n]>=p.first) {
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
}
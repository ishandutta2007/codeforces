#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int t,n,d,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=2;i<=n;i++){
			if(d>=(i-1)){
				int x=min(d/(i-1),a[i]);
				a[1]+=x;
				d=d-x*(i-1);
			}
		}
		cout<<a[1]<<endl;
	}
}
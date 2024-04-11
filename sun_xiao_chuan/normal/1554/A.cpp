#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll res,sb,a[200500];
int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	res=0;
    	for(i=1;i<=n;i++){
    		scanf("%lld",&a[i]);
    		res=max(res,a[i]*a[i-1]);
		}
		printf("%lld\n",res);
	}
}
#include <bits/stdc++.h>



#define NN 501111

#define mod 1000000007

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN];

map<int, int> cnt; 	



INT power(int u, INT n){

	if(n==0) return 1LL;

	INT ans=power(u, n/2);

	ans=ans*ans%mod;

	if(n%2) ans=ans*u%mod;

	if(ans<0) ans+=mod;

	return ans;

}



int main() {

	int n,i,j,x;

	cin>>n>>x;

	INT sum=0;

	for(i=1; i<=n; i++) scanf("%d", a+i);

	sort(a+1, a+n+1);

//	if(a[n]==0) {puts("1"); return 0;}

	

	for(i=1; i<=n-1; i++) sum+=a[i];

	

	for(i=n; i>=1; i--) cnt[a[n]-a[i]]++;

	

	INT ans=power(x, sum);

	for(i=0; i<NN-1; i++) {

		if(cnt[i] && cnt[i]%x) break;

		cnt[i+1]+=cnt[i]/x;

	}

 	ans=ans*power(x, (INT)min(i, a[n]))%mod;

 	if(ans<0) ans+=mod;

	cout<<ans<<endl;





	return 0;

}
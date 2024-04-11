#include<bits/stdc++.h>



using namespace std;



typedef long long INT;



#define NN 1000100



char a[NN], b[NN];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in","r",stdin);

	freopen("out.out","w",stdout);

#endif

	scanf("%s %s", a+1, b+1);

	int n = strlen(a+1);

	int m = strlen(b+1);

	

	int st = 0;

	for(int i=1; i<=m; i++) st += b[i] - '0';

	st %= 2;

	int sum = 0;

	for(int i=1; i<=m; i++) sum += a[i] - '0';

	sum %= 2;

	

	int ans = 0;

	if(sum == st) ans++;

	

	for(int i=2; i<=n-m+1; i++) {

		sum -= a[i-1] - '0';

		sum += a[i+m-1] - '0';

		sum = (sum % 2 + 2) % 2;

		if(sum == st) ans++;

	}

	

	cout << ans << endl;

	

	

	return 0;

}
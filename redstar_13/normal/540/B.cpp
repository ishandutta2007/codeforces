#include <bits/stdc++.h>



#define NN 1111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN];



int main() {

	int n,k,p,x,y, i;

	cin>>n>>k>>p>>x>>y;

	

	for(i=1; i<=k; i++) scanf("%d", a+i);

	sort(a+1, a+k+1);

	int cnt=0;

	

	for(i=1; i<=k; i++){

		if(a[i]>=y) cnt++;

	}

	

	cnt=max(0, (n+1)/2-cnt);

	if(cnt>n-k) return puts("-1"), 0;

	

	for(i=k+1; i<=k+cnt; i++) a[i]=y;

	for(i=k+cnt+1; i<=n; i++) a[i]=1;

	

	int sum=0;

	for(i=1; i<=n; i++) sum+=a[i];

	

	if(sum>x) return puts("-1"), 0;

	for(i=k+1; i<=n; i++) printf("%d ", a[i]);



	return 0;

}
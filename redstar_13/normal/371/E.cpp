#include <bits/stdc++.h>



#define NN 300011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



pii x[NN];

INT up[NN], bak[NN];



int main() {

	int n,i,j;

	cin>>n;

	for(i=1; i<=n; i++) scanf("%d", &x[i].first), x[i].second=i;

	sort(x+1, x+n+1);

	

	int k; cin>>k;

	

	for(i=1; i<=k-1; i++) bak[k]+=x[k].first-x[i].first;

	for(i=k+1; i<=n; i++) bak[i]=bak[i-1]-(x[i-1].first-x[i-k].first)+(INT)(k-1)*(x[i].first-x[i-1].first);

//	for(i=k; i<=n; i++) cout<<i<<' '<<bak[i]<<endl;

	

	for(i=2; i<=k; i++) up[1]+=x[i].first-x[1].first;

	for(i=2; i<=n-k+1; i++) up[i]=up[i-1]-(INT)(k-1)*(x[i].first-x[i-1].first)+x[i+k-1].first-x[i].first;

	

	INT ans=0, pos=1;

	for(i=1; i<=k-1; i++) {

		ans+=(INT)i*(k-i)*(x[i+1].first-x[i].first);

	}

	

	INT tmp=ans;

	for(i=2; i<=n-k+1; i++){

		INT t=tmp;

		t+=bak[i+k-1]-up[i-1];

		tmp=t;

		if(tmp<ans) ans=tmp, pos=i;

	}

	

	for(i=pos; i<=pos+k-1; i++) printf("%d ", x[i].second);

	return 0;

}
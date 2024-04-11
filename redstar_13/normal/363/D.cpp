#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int b[NN], p[NN];



int main() {

	int n,m,i,j,a;

	cin>>n>>m>>a;

	

	for(i=1; i<=n; i++) scanf("%d", b+i);

	for(i=1; i<=m; i++) scanf("%d", p+i);

	sort(b+1, b+n+1);

	sort(p+1, p+m+1);

	

	int st=0, ed=min(n, m)+1;

	while(ed>st+1){

		int mid=(st+ed)>>1;

		int tmp=a, ok=1;

		for(i=1; i<=mid; i++){

			if(b[n+1-i]>=p[mid+1-i]) continue;

			if(b[n+1-i]+tmp<p[mid+1-i]) { ok=0; break;}

			tmp-=p[mid+1-i]-b[n+1-i];

		}

		if(ok) st=mid;

		else ed=mid;

	}

	

	INT ANS=0, sum=0;

	for(i=1; i<=st; i++){

		sum+=p[st+1-i];

	}

	ANS=max(0LL, sum-a);

	cout<<st<<' '<<ANS<<endl;

	return 0;

}
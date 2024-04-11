#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], pos[NN], prim[NN*2], flag[NN*2];

pii ans[NN*10];



int main() {

	int n,i,j;

	cin>>n;

	for(i=1; i<=n; i++) scanf("%d", a+i), pos[a[i]]=i;

	

	int nn=0;

	for(i=2; i<=n*2; i++){

		if(flag[i]) continue;

		prim[nn++]=i;

		for(j=i*2; j<=n*2; j+=i){

			flag[j]=1;

		}

	}

	

//	for(i=0; i<nn; i++) cout<<prim[i]<<endl;

	

	int k=0;

	int t=10;

	

	for(i=1; i<=n; i++){

		while(i!=pos[i]){

			int u=upper_bound(prim, prim+nn, pos[i]-i+1)-prim-1;

			int p=prim[u];

			

			ans[k++]=pii(pos[i], pos[i]-p+1);

			swap(a[pos[i]], a[pos[i]-p+1]);

			swap(pos[i], pos[a[pos[i]]]);

			

		}

	}

	

	cout<<k<<endl;

	for(i=0; i<k; i++) printf("%d %d\n", ans[i].second, ans[i].first);





	return 0;

}
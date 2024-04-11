#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], cnt[111], id[111], arr[NN];



int cmp(int u, int v){

	return cnt[u]>cnt[v];

}



int main() {

	int n,m,i,j;

	cin>>n>>m;

	

	for(i=0; i<n; i++){

		scanf("%d", a+i);

		cnt[a[i]]++;

	}

	

	for(i=1; i<=m; i++) id[i]=i;

	

	sort(id+1, id+m+1, cmp);

	int nn=0;

	for(i=1; i<=m; i++){

		for(j=0; j<cnt[id[i]]; j++) arr[nn++]=id[i];

	}

	

	int ans=0, pos;

	for(i=0; i<n; i++){

		int tmp=0;

		for(j=0; j<n; j++){

			if(arr[j]!=arr[(i+j)%n]) tmp++;

		}

		if(tmp>ans) ans=tmp, pos=i;

	}

	

	cout<<ans<<endl;

	for(i=0; i<n; i++) printf("%d %d\n", arr[(i+pos)%n], arr[i]);



	return 0;

}
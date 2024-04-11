#include<bits/stdc++.h>



#define NN 111111

using namespace std;

typedef long long INT;

const long double PI=4*atan(1);



int n,m;

INT r[NN], h[NN], arr[NN], B[NN];



INT calc(int u){

	INT ans=0;

	while(u){

		ans=max(ans, B[u]);

		u-=u&-u;

	}

	return ans;

}



void update(int u, INT val){

	while(u<=m){

		B[u]=max(B[u], val);

		u+=u&-u;

	}

}



int main(){

	int i,j;

	cin>>n;

	

	for(i=0; i<n; i++){

		scanf("%I64d%I64d", r+i, h+i);

		arr[i]=r[i]*r[i]*h[i];

	}

	

	sort(arr, arr+n);

	m=unique(arr, arr+n)-arr;

	

	INT mx=0;

	for(i=0; i<n; i++){

		INT v=r[i]*r[i]*h[i];

		INT tmp=v;

		int q=upper_bound(arr, arr+m, v)-arr;

		if(q==1) {

			mx=max(mx, tmp);

			update(q, tmp);

			continue;

		}

		tmp+=calc(q-1);	

		update(q, tmp);

		mx=max(mx, tmp);

	}

	long double ans=(long double)mx*PI;

	printf("%.10lf\n", 	(double)ans);

	

	return 0;

}
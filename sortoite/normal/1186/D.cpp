#include<bits/stdc++.h>



using namespace std;



typedef long long INT;

typedef double DO;



#define NN 100010



DO a[NN];



int L[NN], R[NN];



int ans[NN];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in","r",stdin);

	freopen("out.out","w",stdout);

#endif

	int n; cin >> n;

	for(int i=1; i<=n; i++) scanf("%lf", &a[i]);

	for(int i=1; i<=n; i++) {

		if(a[i] == 0) {

			L[i] = R[i] = 0;

			continue;

		}

		if(a[i] > 0) {

			L[i] = a[i];

			R[i] = a[i] + (DO) 0.99999999;

		} else {

			R[i] = a[i];

			L[i] = a[i] - (DO) 0.99999999;

		}

	}

	

	INT min_val = 0, max_val = 0;

	for(int i=1; i<=n; i++) {

		min_val += L[i];

		max_val += R[i];

	}

	

	for(int i=1; i<=n; i++) {

		if(min_val < 0) {

			ans[i] = R[i];

			min_val += R[i] - L[i];

		} else {

			ans[i] = L[i];

		}

	}

	

	for(int i=1; i<=n; i++) printf("%d ", ans[i]);

	return 0;

}
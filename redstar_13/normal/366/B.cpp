#include <bits/stdc++.h>



using namespace std;

#define MM 110000

#define NN 100000010



int n, k, a[MM], id, mn=NN, sum[MM];

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &k);

	for (int i=0; i<n; i++) scanf ("%d", a+i);

	for (int i=0; i<n; i++) sum[i%k]+=a[i];

	id=0;

	for (int i=0; i<k; i++){

		if(mn>sum[i]) mn=sum[i], id=i;

	}

	cout<<id+1<<endl;

	return 0;

}
#include <bits/stdc++.h>



using namespace std;

typedef long long INT;

#define MM 210000

int freq[MM], a[MM], n, q, cnt, l[MM], r[MM];

INT sum;

int main()

{

	int u, v;

//	freopen ("in.txt", "r", stdin);

	scanf  ("%d%d", &n, &q);

	for (int i=1; i<=n; i++) scanf ("%d", a+i);

	while(q--){

		scanf ("%d%d", &u, &v);

		l[cnt]=u; r[cnt++]=v;

	}

	sort(l, l+cnt); sort(r, r+cnt);

	for (int i=1; i<=n; i++){

		int p1=upper_bound(l, l+cnt, i)-l-1;

		int p2=lower_bound(r, r+cnt, i)-r-1;

		freq[i]=p1-p2;

	}

	sort(a+1, a+n+1); sort(freq+1, freq+1+n);

	for (int i=1; i<=n; i++) sum+=(INT)freq[i]*a[i];

	cout<<sum<<endl;

	return 0;

}
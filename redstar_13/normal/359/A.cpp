#include <bits/stdc++.h>



using namespace std;



int n, m, f, a[100][100];



int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &m);

	for (int i=1; i<=n; i++){

		for (int j=1; j<=m; j++){

			cin>>a[i][j];

			if ((i==1 || j==1) && a[i][j]>0) f=1;

			if ((i==n || j==m) && a[i][j]>0)f=1;

		}

	}

	if (f) puts("2");

	else puts("4");

	return 0;

}
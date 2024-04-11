#include <bits/stdc++.h>



using namespace std;

#define MM 2100000



int n, m;

char str[MM], *a;

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &m);

	if ((n-1)<=m && m<=2*(n+1)){

		if ((n-1)==m){

			for (int i=0; i<m; i++) printf("01"); puts("0");

		}

		else if(n==m){

			for (int i=0; i<m; i++) printf("01"); puts("");

		}

		else if((n+1)*2==m){

			for (int i=0; i<n; i++) printf("110"); puts("11");

		}

		else{

			int i;

			for (i=1; i<=m-(n+1); i++) printf("11"),printf("0");

			for (int j=i; j<=n; j++) printf("1"), printf("0");

			printf("1");

		}

	}

	else puts("-1");

	return 0;

}
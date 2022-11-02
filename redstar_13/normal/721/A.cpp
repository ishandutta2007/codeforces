#include <bits/stdc++.h>



using namespace std;



int n, cnt;

char str[200];

int ans[200];

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	scanf ("%s", str);

	bool f=0;

	for (int i=0; i<n; i++){

		if (str[i]=='B')ans[cnt]++, f=1;

		if (f && (str[i]=='W' || i==n-1))cnt++,f=0;

	}

	cout<<cnt<<endl;

	for (int i=0; i<cnt; i++) cout<<ans[i]<<" ";

	return 0;

}
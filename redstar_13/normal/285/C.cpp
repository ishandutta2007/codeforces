#include <bits/stdc++.h>



using namespace std;

#define MM 310000



int a[MM],n;

long long sum;

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	for (int i=0; i<n; i++) scanf("%d", a+i);

	sort(a, a+n);

	sum=0;

	for (int i=0; i<n; i++) sum+=(long long)abs(a[i]-(i+1));

	cout<<sum<<endl;

}
#include<bits/stdc++.h>



using namespace std;



int a[55];



int main(){

	int n,k,i,j;

	cin>>n>>k;

	for(i=0; i<n; i++) scanf("%d", a+i);

	sort(a, a+n);

	if(k<=n) cout<<a[n-k]<<' '<<a[n-k]<<endl;

	else puts("-1");

}
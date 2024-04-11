#include<bits/stdc++.h>



using namespace std;



int main(){

	int n,a[5][3];

	

	cin>>n;

	for(int i=1;i<=n;i++)

		scanf("%d%d",&a[i][0],&a[i][1]);

	if(n==1) {printf("-1\n"); return 0; }

	if(n==2) {

		if(a[1][0]==a[2][0] || a[1][1]==a[2][1]) {printf("-1\n");  return 0;}

		else {printf("%d\n",abs(a[1][0]-a[2][0])*abs(a[1][1]-a[2][1]));  return 0;}

	}

	for(int i=1;i<=n-1;i++) 

		for(int j=i+1;j<=n;j++){

			int s=(a[i][0]-a[j][0])*(a[i][1]-a[j][1]);

			if(s) {printf("%d\n",abs(s));	return 0;}

		}

	 

	



	return  0;

}
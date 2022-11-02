#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef double DO;



int ans[111];

int main(){

	int n,d,l,i, j;

	cin>>n>>d>>l;

	

	int mx=l*((n+1)/2)-(n/2), mn=-l*(n/2)+(n+1)/2;

//	cout<<mx<<' '<<mn<<endl;

	if(d<mn || d>mx)  {puts("-1"); return 0;}

	

	for(i=1; i<=n; i++){

		if(i&1) ans[i]=1;

		else ans[i]=l;

	}

	

	int s=mn;

	for(i=1; i<=n; i++){

		if(i&1){

			if(s-1+l<d) ans[i]=l, s=s-1+l;

			else {

				ans[i]=d-s+1;

				for(i=1; i<=n; i++) cout<<ans[i]<<' ';

				return 0;

			}

		}

		

		else {

			if(s+l-1<d) ans[i]=1, s=s+l-1;

			else {

				ans[i]=s+l-d;

				for(i=1; i<=n; i++) cout<<ans[i]<<' ';

				return 0;

			}

		}

	}

	return 0;

}
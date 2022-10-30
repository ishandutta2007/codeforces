#include<bits/stdc++.h>



#define NN 5555

using namespace std;

typedef long long INT;

typedef double DO;



char s;

int main(){

	int n,m,i,j;

	cin>>n>>m;

	INT t,T, x, cost;

	INT ans=0;

	for(i=0; i<n; i++){

		scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);

		INT tmp1=cost+(t+m>T)*x*m;

		INT tmp2;

		if(T<=t) tmp2=tmp1;

		else tmp2=((m+T-t-1)/(T-t))*cost;

//		cout<<tmp1<<' '<<tmp2<<endl;

		ans+=min(tmp1, tmp2);

//		cout<<ans<<endl;

	}

	

	cout<<ans<<endl;

	return 0;

}
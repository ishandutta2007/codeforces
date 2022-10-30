#include<bits/stdc++.h>

#define NN 100050

using namespace std;



int t[NN],v[NN];



double tt[NN]; 

int main(){

//	freopen("in.txt", "r",stdin);

	int n,a,d;

	cin>>n>>a>>d;

	

	for(int i=0;i<n;i++){

		scanf("%d %d",&t[i],&v[i]);

		double s0=1.0*v[i]*v[i]/a/2.0;

		if(s0>d) tt[i]=t[i]+sqrt(2.0*d/a);

		else tt[i]=1.0*t[i]+1.0*d/v[i]+1.0*v[i]/a/2.0;

	}

	for(int i=0;i<n;i++)

		if(i && tt[i]<tt[i-1]) tt[i]=tt[i-1];

	for(int i=0;i<n;i++)

		printf("%.10lf\n",tt[i]);

	return 0;

}
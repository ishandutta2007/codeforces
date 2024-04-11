#include<bits/stdc++.h>



#define NN 5555

using namespace std;

typedef long long INT;

typedef double DO;



char s;

int main(){

	DO ans=0;

	int r=0, p1=0, p2=100000000,c,n,m,k;

	cin>>n;

	

	while(n--) {

		scanf("%d",&c);

		r=max(r, c);

	}

	cin>>m;

	

	while(m--){

		scanf("%d", &c);

		p1=max(p1, c);

	}

	

	cin>>k;

	while(k--){

		scanf("%d", &c);

		p2=min(p2, c);

	}

	

	int a,b;

	cin>>a>>b;

	

	ans=sqrt((DO)r*r*b*p1/((DO)	a*p2+b*p1));

	printf("%.10lf\n", ans);

	return 0;

}
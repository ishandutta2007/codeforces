#include <bits/stdc++.h>



#define NN 100011

#define eps (1e-6)

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;

typedef double DO;







int main() {

	DO a, d;

	int n,i,j;

	scanf("%lf %lf", &a, &d);

	DO len=a*4;

	cin>>n;

	

	for(i=1; i<=n; i++){

		DO dst=d*i;

		DO rem=fmod(dst, len);

		DO x, y;

		

		if(rem+eps<a) x=rem, y=0;

		else if(rem+eps<2*a) x=a, y=rem-a;

		else if(rem+eps<3*a) x=3*a-rem, y=a;

		else x=0, y=4*a-rem;

		printf("%.10lf %.10lf\n", x, y);

	}





	return 0;

}
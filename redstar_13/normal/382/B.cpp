#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a ,b, c, w, x;

int ok(INT mid){

	INT k;

	if((INT)mid*x-b<0) k=0;

	else k=((INT)mid*x-b+w-1)/w;

	if(a-k>=c-mid) return 1;

	else return 0;

}



int main() {

	cin>>a>>b>>w>>x>>c;

	if(a>=c) return puts("0"), 0;

	

	INT st=0, ed=2000000000000000000LL;

	while(ed>st+1){

		INT mid=(st+ed)/2;

		if(ok(mid)) ed=mid;

		else st=mid;

	}

	

	cout<<ed<<endl;

	return 0;

}
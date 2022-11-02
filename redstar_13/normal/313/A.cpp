#include<bits/stdc++.h>



using namespace std;



int main(){

	int n;

	cin>>n;

	if(n>0) { printf("%d",n); return 0;}

	int nn=abs(n);

	int tg1=nn%10;

	int tg2=(nn-tg1)/10%10;	

	if(tg1>tg2) printf("%d",(n+tg1)/10);

 	else printf("%d",(n+tg1+tg2*10)/10-tg1);

 	return 0;

}
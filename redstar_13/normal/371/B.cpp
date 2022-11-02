#include<bits/stdc++.h>



using namespace std;



int a, b, aa, bb, aaa, bbb, aaaaa, bbbbb;



int main(){

	

	scanf("%d%d", &a, &b);

	

	while(a%2==0){a/=2; aa++;}

	while(a%3==0){a/=3; aaa++;}

	while(a%5==0){a/=5; aaaaa++;}

	

	while(b%2==0){b/=2; bb++;}

	while(b%3==0){b/=3; bbb++;}

	while(b%5==0){b/=5; bbbbb++;}

	

	if(a!=b) puts("-1");

	else printf("%d\n", abs(aa-bb)+abs(aaa-bbb)+abs(aaaaa-bbbbb));

	return 0;

}
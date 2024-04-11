#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	long long n,q=1;
	cin >> n;
	for (int i=0;i<100;i++){
		if (q*5>=n){
			n=(n-1)/q;
			if (n==0)puts("Sheldon");
			if (n==1)puts("Leonard");
			if (n==2)puts("Penny");
			if (n==3)puts("Rajesh");
			if (n==4)puts("Howard");
			return 0;
		}
		n-=q*5;
		q*=2;
	}
	return 0;
}
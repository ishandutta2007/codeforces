#include<bits/stdc++.h>



#define NN 100011

#define inf 1000000100

using namespace std;

typedef long long INT;

typedef double DO;

typedef pair<int, int> pii;



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	int n,m,i,j;

	cin>>n>>m;

	if( n>m) {

		while(n>m) putchar('B'), n--;

		while(n) putchar('G'), putchar('B'), n--;

		return 0;

	}

	else  {

		while(m>n) putchar('G'), m--;

		while(m) putchar('B'),putchar('G'), m--;

	}

	

	return 0;

}
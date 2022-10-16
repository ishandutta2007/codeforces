#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

int main(){
	unsigned long long a,b,c;
	cin>>a>>b>>c;
	//scanf("%lli%lli%lli",&a,&b,&c);
	if(a==b && a==c){
		//printf("%lli",0	);
		cout<<0;
	}
	else if(b>a && b>c){
		//assert(0);
		//printf("%lli",2*b-a-c-2);
		cout<<2*b-a-c-2;
	}
	else if(a>b && a>c){
		//assert(0);
		//printf("%lli",2*a-b-c-2);
		cout<<2*a-b-c-2;
	}
	else if(c>a && c>b){
		//assert(0);
		//printf("%lli",2*c-a-b-2);
		cout<<2*c-a-b-2;
	}
	else if(a==b && a>c){
		//assert(0);
		//printf("%lli",a-c-1);
		cout<<a-c-1;
	}
	else if(a==c && a>b){
		//assert(0);
		//printf("%lli",a-b-1);
		cout<<a-b-1;
	}
	else if(b==c && a<b){
		//assert(0);
		//printf("%lli",b-a-1);
		cout<<b-a-1;
	}
		//assert(0);
	return 0;
}
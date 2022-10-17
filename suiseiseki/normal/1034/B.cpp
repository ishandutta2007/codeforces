#include <cstdio>
#include <iostream>
using namespace std;
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m){
		swp(n,m);
	}
	if(n==1){
		if(m%6==0){
			printf("%d\n",m);
		}
		else if(m%6<=3){
			printf("%d\n",m-m%6);
		}
		else{
			printf("%d\n",m-(6-m%6));
		}
	}
	else if(n==2&&m==2){
		puts("0");
	}
	else if(n==2&&m==7){
		puts("12");
	}
	else if(n==2&&m==3){
		puts("4");
	}
	else{
		if((n&1)&&(m&1)){
			cout<<(long long)n*m-1<<endl;
		}
		else{
			cout<<(long long)n*m<<endl;
		}
	}
	return 0;
}
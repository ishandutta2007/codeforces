#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	int q,num;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&num);
		if(num == 1 || num == 2 || num == 3 || num == 5 || num == 7 || num == 11){
			printf("-1\n");
		}
		else if(num % 4 == 0){
			cout<<num/4<<endl;
		}
		else if(num % 4 == 1){
			cout<<(num - 5) / 4 <<endl;
		}
		else if(num % 4 == 2){
			cout<<num/4 << endl;
		}
		else{
			cout<<(num - 7) / 4 <<endl;
		}
	}
}
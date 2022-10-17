#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	fflush(stdout);
	cout<<"? ";
	for(int i=1;i<=100;i++){
		cout<<i<<' ';
	}
	cout<<endl;
	int x;
	scanf("%d",&x);
	int ans=0;
	for(int i=8;i<=14;i++){
		if((1<<(i-1))&x){
			ans+=(1<<(i-1));
		}
	}
	cout<<"? ";
	for(int i=1;i<=100;i++){
		cout<<(i<<7)<<' ';
	}
	cout<<endl;
	scanf("%d",&x);
	for(int i=1;i<8;i++){
		if((1<<(i-1))&x){
			ans+=(1<<(i-1));
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}
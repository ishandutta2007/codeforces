#include<iostream>

using namespace std;

int main(){
	int n , p , q , level[101] , a , sum = 0;
	cin>>n>>p;
	for(int i = 1 ; i <= n ; i++){
		level[i] = 1;
	}
	for(int i = 0 ; i < p ; i++){
		cin>>a;
		level[a] = 0;
	}
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		cin>>a;
		level[a] = 0;
	}
	for(int i = 1 ; i <= n ; i++){
		sum += level[i];
	}
	if(sum == 0){
		cout<<"I become the guy."<<endl;
	}
	else{
		cout<<"Oh, my keyboard!"<<endl;
	}
	return 0;
}
#include<iostream>

using namespace std;

int main(){
	int l , a[100] , min = 101 , max = 0 , mi , ma;
	cin>>l;
	for(int i = 0 ; i < l ; i++){
		cin>>a[i];
		if(a[i] > max){
			max = a[i];
			ma=i;
		}
		if(a[i] <= min){
			min = a[i];
			mi = i;
		}
	}
	if(mi == ma){
		cout<<"0"<<endl;
	}
	else if(mi > ma){
		cout<<(l - 1) - mi + ma<<endl;
	}
	else{
		cout<<(l - 1) - mi + ma - 1<<endl;
	}
	return 0;
}
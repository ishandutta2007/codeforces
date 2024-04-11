#include<iostream>

using namespace std;

int main(){
	int n , k , a[50] , counter = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < k ; i++){
		if(a[i] > 0){
			counter++;
		}
		else{
			break;
		}
	}
	for(int i = k ; i < n ; i++){
		if(a[i] == a[k-1] && a[i] > 0){
			counter++;
		}
		else{
			break;
		}
	}
	cout<<counter<<endl;
	return 0;
}
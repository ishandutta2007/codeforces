#include<iostream>

using namespace std;

int main(){
	int a[4] , counter = 0;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	for(int i = 1 ; i < 4 ; i++){
		if(a[0] == a[i]){
			a[i] = -1;
			counter++;
		}
	}
	if(a[1] != -1){
		for(int i = 2 ; i < 4 ; i++){
			if(a[1] == a[i] && a[i] != -1){
				a[i] = -1;
				counter++;
			}
		}
	}
	if(a[2] == a[3] && a[2] != -1 && a[3] != -1){
		counter++;
	}
	cout<<counter<<endl;
	return 0;
}
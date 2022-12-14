#include <iostream>
using namespace std;
bool tof[300];
int p,n;
int arr[301];
int  main(){
	cin >> p >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(tof[arr[i]%p] != true){
			tof[arr[i]%p] = true;
		}else{
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
	
}
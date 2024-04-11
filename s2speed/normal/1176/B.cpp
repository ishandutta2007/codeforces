#include<iostream>

using namespace std;

int main(){
	int t , n , a[100] , co[3] , counter;
	cin>>t;
	while(t > 0){
		counter = 0;
		for(int i = 0 ; i < 3 ; i++){
			co[i] = 0;
		}
		cin>>n;
		for(int i = 0  ; i < n ; i++){
			cin>>a[i];
			a[i] %= 3;
		}
		for(int i = 0 ; i < n ; i++){
			if(a[i] == 0){
				co[0]++;
			}
			else if(a[i] == 1){
				co[1]++;
			}
			else{
				co[2]++;
			}
		}
		counter += co[0];
		counter += min(co[1] , co[2]);
		counter += (max(co[1] , co[2]) - min(co[1] , co[2])) / 3;
		cout<<counter<<endl;
		t--;
	}
	return 0;
}
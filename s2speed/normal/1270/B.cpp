#include<iostream>

using namespace std;

int main(){
	int t , n , a[200000];
	cin>>t;
	while(t > 0){
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < n - 1 ; i++){
			if(a[i] - a[i + 1] == 1 || a[i + 1] - a[i] == 1 || a[i] == a[i + 1]){
				if(i == n - 2){
					cout<<"NO"<<endl;
				}
			}
			else{
				cout<<"YES"<<endl<<i + 1<<" "<<i + 2<<endl;
				break;
			}
		}
		t--;
	}
	return 0;
}
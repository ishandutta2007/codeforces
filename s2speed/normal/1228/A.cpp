#include<iostream>

using namespace std;

int main(){
	int n , m , a[5] , b;
	cin>>n>>m;
	for(int i = 0 ; i < m - n + 1 ; i++){
		b = n+i;
		for(int j = 0 ; j < 5 ; j++){
			a[j] = b % 10;
			b /= 10;
		}
		if(n+i >= 10000){
			if(a[0] != a[1] && a[0] != a[2] && a[1] != a[2] && a[0] != a[3] && a[1] != a[3] && a[2] != a[3] && a[0] != a[4] && a[1] != a[4] && a[2] != a[4] && a[3] != a[4]){
				cout<<n+i<<endl;
				break;
			}
		}
		else if(n+i >= 1000){
			if(a[0] != a[1] && a[0] != a[2] && a[1] != a[2] && a[0] != a[3] && a[1] != a[3] && a[2] != a[3]){
				cout<<n+i<<endl;
				break;
			}
		}
		else if(n+i >= 100){
			if(a[0] != a[1] && a[0] != a[2] && a[1] != a[2]){
				cout<<n+i<<endl;
				break;
			}
		}
		else if(n+i >= 10){
			if(a[0] != a[1]){
				cout<<n+i;
				break;
			}
		}
		else if(n+i > 0){
			cout<<n+i;
			break;
		}
		if(i == m - n){
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
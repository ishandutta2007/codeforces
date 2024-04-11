#include<iostream>

using namespace std;

int main(){
	int n , m;
	cin>>n>>m;
	if(m > 2 * n + 2 || n > m + 1){
		 cout<<-1<<endl;
	}
	else if(m <= n){
		for(int i = 0 ; i < m + n ; i++){
			if(i % 2 == 0){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
	else if(m >= n * 2){
		for(int i = m - 2 * n ; i > 0 ; i--){
			cout<<1;
		}
		for(int i = 0 ; i < 3 * n ; i++){
			if(i % 3 == 0){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
	else {
		while(m + n > 0){
			while(m < 2 * n){
				cout<<1;
				m--;
				cout<<0;
				n--;
			}
			for(int i = 0 ; i < m + n ; i++){
				if(i % 3 == 2){
					cout<<0;
				} else {
					cout<<1;
				}
			}
			break;
		}
	}
	return 0;
}
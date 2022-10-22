#include<iostream>

using namespace std;

int main(){
	int n , m , d , c[1000] , co = 0;
	cin>>n>>m>>d;
	for(int i = 0 ; i < m ; i++){
		cin>>c[i];
		co += c[i];
		co--;
	}
	if(d * (m + 1) + co < n + 1){
		cout<<"NO"<<endl;
	}
	else{
		co += m;
		cout<<"YES"<<endl;
		for(int i = 0 ; n != 0 ; i++){
			if(n - co > d - 1){
				for(int j = 0 ; j < d - 1 ; j++){
					cout<<"0 ";
				}
				n -= d - 1;
			}
			else if(n - co > 0){
				for(int j = 0 ; j < n - co ; j++){
					cout<<"0 ";
				}
				n = co;
			}
			if(i == m){
				break;
			}
			for(int j = 0 ; j < c[i] ; j++){
				cout<<i + 1<<" ";
				co--;
				n--;
			}
		}
	}
	return 0;
}
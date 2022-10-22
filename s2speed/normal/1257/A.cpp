#include<iostream>

using namespace std;

int main(){
	int t , n , x , a , b , d = 0;
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		cin>>n>>x>>a>>b;
		d = 0;
		d += a - b;
		if(d < 0){
			d -= 2*d;
		}
		d += x;
		if(d >= n){
			cout<<n - 1<<endl;
		}
		else{
			cout<<d<<endl;
		}
	}
	return 0;
}
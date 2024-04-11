#include<iostream>

using namespace std;

int main(){
	int t , counter;
	long long a , b , c , r;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>c>>r;
		if(a > b){
			swap(a,b);
		}
		counter = 0;
		if(c >= a && c <= b){
			if(c + r < b){
				counter += b - c - r;
			}
			if(c - r > a){
				counter += c - r - a;
			}
		}
		else if(c < a){
			if(c + r > a){
				counter += b - a - (c + r - a);
			}
			else{
				counter += b - a;
			}
		}
		else{
			if(c - r < b){
				counter += b - a - (b - c + r);
			}
			else{
				counter += b - a;
			}
		}
		if(counter < 0){
			cout<<0<<endl;
		}
		else{
			cout<<counter<<endl;
		}
		t--;
	}
	return 0;
}
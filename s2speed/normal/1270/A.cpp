#include<iostream>

using namespace std;

int main(){
	int n , c1 , c2 , ma[2], t , h;
	cin>>t;
	while(t > 0){
		ma[0] = 0;
		ma[1] = 1;
		cin>>n>>c1>>c2;
		for(int i = 0 ; i < c1 ; i++){
			cin>>h;
			ma[0] = max(ma[0] , h);
		}
		for(int i = 0 ; i < c2 ; i++){
			cin>>h;
			ma[1] = max(ma[1] , h);
		}
		if(ma[0] > ma[1]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}
#include<iostream>

using namespace std;

int main(){
	int t , l , ll , r , rr;
	cin>>t;
	while(t > 0){
		cin>>l>>r>>ll>>rr;
		if(l != ll){
			cout<<l<<" "<<ll<<endl;
		}
		else{
			cout<<l<<" "<<l + 1<<endl;
		}
		t--;
	}
	return 0;
}
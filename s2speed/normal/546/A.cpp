#include<iostream>

using namespace std;

int main(){
	int k , n , w;
	cin>>k>>n>>w;
	if(w*(w+1)/2*k - n < 0){
		cout<<"0"<<endl;
	}
	else{
		cout<<w*(w+1)/2*k-n<<endl;
	}
	return 0;
}
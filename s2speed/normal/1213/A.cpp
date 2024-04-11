#include<iostream>

using namespace std;

int main(){
	int n , a , counter[2];
	cin>>n;
	counter[0] = 0;
	counter[1] = 0;
	while(n > 0){
		cin>>a;
		counter[a % 2]++;
		n--;
	}
	cout<<min(counter[0] , counter[1])<<endl;
	return 0;
}
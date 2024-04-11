#include<iostream>

using namespace std;

int main(){
	int n , c1 = 0 , c2 = 0 , c3 = 0 , c4 = 0 , sum = 0 , input;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>input;
		if(input == 1){
			c1++;
		}
		else if(input == 2){
			c2++;
		}
		else if(input == 3){
			c3++;
		}
		else{
			c4++;
		}
	}
	sum += c4;
	sum += c3;
	if(c3 >= c1){
		c1 = 0;
	}
	else{
		c1 -= c3;
	}
	if((2 * c2 + c1) % 4 == 0){
		sum += (2 * c2 + c1) / 4;
	}
	else{
		sum += (2 * c2 + c1) / 4 + 1;
	}
	cout<<sum<<endl;
	return 0;
}
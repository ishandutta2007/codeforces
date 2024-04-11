#include<iostream>

using namespace std;

int main(){
	int n , counter = 0 , max = 1 , a , b = -1;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		a = b;
		cin>>b;
		if(b >= a ){
			counter++;
		}
		else{
			if(counter > max){
				max = counter;
			}
			counter = 1;
		}
		if(counter > max){
			max = counter;
		}
	}
	cout<<max<<endl;
	return 0;
}
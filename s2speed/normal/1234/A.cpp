#include<iostream>

using namespace std;

int main(){
	int q , n , input , sum = 0;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		cin>>n;
		for(int j = 0 ; j < n ; j++){
			cin>>input;
			sum += input;
		}
		if(sum % n == 0){
			cout<<sum / n<<endl;
			sum = 0;
		}
		else{
			cout<<sum / n + 1<<endl;
			sum = 0;
		}
	}
	return 0;
}
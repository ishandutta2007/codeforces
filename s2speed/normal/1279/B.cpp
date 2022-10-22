#include<iostream>

using namespace std;

int maw(int q[] , int k){
	int mix = 0 , spotter;
	for(int i = 0 ; i <= k ; i++){
		if(q[i] > mix){
			mix = q[i];
			spotter = i;
		}
	}
	return spotter;
}

int main(){
	bool checker;
	short t;
	int n , s , a[100000] , sum;
	cin>>t;
	while(t > 0){
		int nokhodsiah;
		checker = false;
		sum = 0;
		cin>>n>>s;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			sum += a[i];
			if(sum > s && i <= n - 2){
				nokhodsiah = i + 2;
				cin>>a[i + 1];
				if(a[maw(a , i)] < a[i + 1]){
					checker = true;
					cout<<i + 2<<endl;
					break;
				}
				else{
					checker = true;
					cout<<maw(a , i) + 1<<endl;
					break;
				}
			}
			else if(sum > s && i == n - 1){
				nokhodsiah = n;
				checker = true;
				cout<<maw(a , i) + 1<<endl;
				break;
			}
		}
		if(checker == false){
			cout<<0<<endl;
		}
		else{
			for(; nokhodsiah < n ; nokhodsiah++){
				cin>>a[nokhodsiah];
			}
		}
		t--;
	}
	return 0;
}
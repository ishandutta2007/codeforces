#include<iostream>

using namespace std;

int main(){
	int t , n , p[200000] , helper[200001] , mn , mx;
	bool code[200001];
	cin>>t;
	while(t > 0){
		cin>>n;
		for(int i = 2 ; i < n ; i++){
			code[i] = true;
		}
		for(int i = 0 ; i < n ; i++){
			cin>>p[i];
		}
		for(int i = 0 ; i < n ; i++){
			helper[p[i]] = i;
		}
		mn = helper[1];
		mx = helper[1];
		for(int i = 2 ; i < n ; i++){
			mx = max(mx , helper[i]);
			mn = min(mn , helper[i]);
			if(mx - mn >= i){
				code[i] = false;
			}
		}
		code[1] = true;
		code[n] = true;
		for(int i = 1 ; i <= n ; i++){
			cout<<code[i];
		}
		cout<<endl;
		t--;
	} 
}
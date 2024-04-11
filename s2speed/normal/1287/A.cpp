#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	int t , n , maxi , counter;
	bool check = true;
	string s;
	cin>>t;
	while(t > 0){
		counter = 0;
		maxi = 0;
		check = false;
		cin>>n>>s;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'A' && check == false){
				check = true;
			}
			if(check == true && s[i] == 'P'){
				counter++;
			}
			else if(check == true && s[i] == 'A'){
				maxi = max(maxi , counter);
				counter = 0;
			}
		}
		maxi = max(counter , maxi);
		cout<<maxi<<endl;
		t--;
	}
	return 0;
}
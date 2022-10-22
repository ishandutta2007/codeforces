#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string f;
	vector <string> s , c;
	int n , m , a;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>f;
		s.push_back(f);
	}
	for(int i = 0 ; i < m ; i++){
		cin>>f;
		c.push_back(f);
	}
	int q;
	cin>>q;
	while(q > 0){
		cin>>a;
		cout<<s[(a - 1) % n]<<c[(a - 1) % m]<<endl;
		q--;
	}
	return 0;
}
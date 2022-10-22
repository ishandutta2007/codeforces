#include<iostream>
#include<string>
#include<vector>

using namespace std;

void change(string a , int i){
	if(a[i] == 'W'){
		a[i] = 'B';
	} else {
		a[i] = 'W';
	}
	return ;
}

int main(){
	vector<int> v , vv;
	int n , counter = 0 , ccounter = 0;
	char m = 'W';
	string s , clone;
	cin>>n>>s;
	clone = s;
	if(n % 2 == 1){
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'B'){
				counter++;
			}
		}
		if(counter % 2 == 1){
			m = 'B';
		}
	} else {
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'W'){
				counter++;
			}
		}
		if(counter % 2 == 1){
			cout<<-1<<endl;
			return 0;
		}
	}
	counter = 0;
	for(int i = 0 ; i < n - 1 ; i++){
		if(s[i] != m){
			v.push_back(i + 1);
			counter++;
			s[i] = m;
			if(s[i + 1] != 'B'){
				s[i + 1] = 'B';
			} else {
				s[i + 1] = 'W';
			}
		}
	}
	if(n % 2 == 0){
		m = 'B';
		for(int i = 0 ; i < n - 1 ; i++){
			if(clone[i] != m){
				vv.push_back(i + 1);
				ccounter++;
				clone[i] = m;
				if(clone[i + 1] == 'B'){
					clone[i + 1] = 'W';
				} else {
					clone[i + 1] = 'B';
				}
			}
		}
		if(counter <= ccounter){
			cout<<counter<<endl;
			for(int i = 0 ; i < v.size() ; i++){
				cout<<v[i]<<" ";
			}
		} else {
			cout<<ccounter<<endl;
			for(int i = 0 ; i < vv.size() ; i++){
				cout<<vv[i]<<" ";
			}
		}
	} else {
		cout<<counter<<endl;
		for(int i = 0 ; i < counter ; i++){
			cout<<v[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}
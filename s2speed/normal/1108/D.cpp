#include<iostream>
#include<string>

using namespace std;

char ree(char a , char b , char c){
	if(a == 'B' && c == 'G' || a == 'G' && c == 'B'){
		b = 'R';
	}
	else if(a == 'R' && c == 'G' || a == 'G' && c == 'G' || a == 'G' && c == 'R'){
		b = 'B';
	}
	else{
		b = 'G';
	}
	return b;
}

int main(){
	int n , counter = 0;
	string s;
	cin>>n>>s;
	for(int i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]){
			if(i != n - 1){
				s[i] = ree(s[i - 1] , s[i] , s[i + 1]);
				counter++;
			}
			else{
				s[i] = ree(s[i - 1] , s[i] , 'R');
				counter++;
			}
		}
	}
	cout<<counter<<endl<<s<<endl;
	return 0;
}
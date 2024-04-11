#include<iostream>
#include<string>

using namespace std;

int main(){
	int f;
	char hey;
	string s;
	cin>>s;
	for(int i = 0 ; i < s.size() ; i++){
		f = 'a' - s[i];
		if(f == 32 || f == 0 || f == -4 || f == 28 || f == 8 || f == -24 || f == 12 || f == -20 || f == 24 || f == -8 || f == 18 || f == -14){}
		else{
			if(f < 0){
				cout<<"."<<s[i];
			}
			else{
				hey = s[i] + 32;
				cout<<"."<<hey;
			}
		}
	}
	return 0;
}
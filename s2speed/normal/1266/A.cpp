#include<iostream>
#include<string>

using namespace std;

int changer(char x){
	if(x == '0'){
		return 0;
	}
	else if(x == '1'){
		return 1;
	}
	else if(x == '2'){
		return 2;
	}
	else if(x == '3'){
		return 3;
	}
	else if(x == '4'){
		return 4;
	}
	else if(x == '5'){
		return 5;
	}
	else if(x == '6'){
		return 6;
	}
	else if(x == '7'){
		return 7;
	}
	else if(x == '8'){
		return 8;
	}
	else{
		return 9;
	}
}

int main(){
	int n , aray[100] , sum , zooj;
	bool sefr;
	string s;
	cin>>n;
	while(n > 0){
		cin>>s;
		sum = 0;
		sefr = false;
		zooj = 0;
		for(int i = 0 ; i < s.size() ; i++){
			aray[i] = changer(s[i]);
		}
		for(int i = 0 ; i < s.size() ; i++){
			sum += aray[i];
			sum %= 3;
		}
		if(sum == 0){
			for(int i = 0 ; i < s.size() ; i++){
				if(aray[i] == 0){
					sefr = true;
					zooj++;
				}
				else if(aray[i] % 2 == 0){
					zooj++;
				}
			}
		}
		if(sefr == true && zooj >= 2){
			cout<<"red"<<endl;
		}
		else{
			cout<<"cyan"<<endl;
		}
		n--;
	}
	return 0;
}
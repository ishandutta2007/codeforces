#include<iostream>
#include<string>

using namespace std;

void re(char c[] , int r){
	if(r / 2 == 0){
		c[0] = 'R';
		if(r == 1){
			c[1] = 'G';
			c[2] = 'B';
		}
		else{
			c[2] = 'G';
			c[1] = 'B';
		}
	}
	else if(r / 2 == 1){
		c[0] = 'B';
		if(r == 3){
			c[1] = 'R';
			c[2] = 'G';
		}
		else{
			c[2] = 'R';
			c[1] = 'G';
		}
	}
	else{
		c[0] = 'G';
		if(r == 5){
			c[1] = 'R';
			c[2] = 'B';
		}
		else{
			c[1] = 'B';
			c[2] = 'R';
		}
	}
	
}

int main(){
	int counter = 0 , n , min[2];
	min[0] = 10000000;
	min[1] = 10000000;
	char c[3];
	string s;
	cin>>n;
	cin>>s;
	for(int i = 0 ; i < 6 ; i++){
		re(c , i);
		for(int j = 0 ; j < n ; j++){
			if(s[j] != c[j % 3]){
				counter++;
			}
		}
		if(counter < min[0]){
			min[0] = counter;
			min[1] = i;
		}
		counter = 0;
	}
	re(c , min[1]);
	for(int i = 0 ; i < n ; i++){
		if(s[i] != c[i % 3]){
			s[i] = c[i % 3];
		}
	}
	cout<<min[0]<<endl<<s<<endl;
	return 0;
}
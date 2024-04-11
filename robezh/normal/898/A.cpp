#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int op;
int n;


int main(){
	cin >> n;
	if(n % 10 >= 5){
		n += 10-(n%10);
	}
	else n -= n%10;

	cout << n;
}
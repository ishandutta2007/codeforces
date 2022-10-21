#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int op;
int a,b;
int n;


int main(){
	cin >> n >> a >> b;
	for(int i = 0; i <= n/a; i++){
		if((n - i * a) % b == 0){
			cout << "YES" << endl;
			cout << i << " " << (n - i*a) / b << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
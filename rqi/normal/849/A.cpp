#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, a;
	cin >> n;
	int ans = 1;
	if(n % 2 == 0){
		ans = 0;
	}
	for(int i = 0; i < n; i++){
		cin >> a;
		if(i == 0){
			if(a % 2 == 0){
				ans = 0;	
			}	
		}
		else if(i == n-1){
			if(a % 2 == 0){
				ans = 0;
			}	
		}
	}
	
	if(ans == 1){
		cout << "YES";
	}
	else cout << "NO";
}
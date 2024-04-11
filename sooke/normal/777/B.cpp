#include <cstdio>
#include <iostream>

using namespace std;

int n , x[10] , y[10] , ansx = 0 , ansy = 0;
string r , s;
bool flag;

int main(){
	cin >> n >> r >> s;
	r = "#" + r , s = "#" + s;
	for(int i = 1 ; i <= n ; i++)
		x[s[i] ^ 48]++ , y[s[i] ^ 48]++;
	for(int i = 1 ; i <= n ; i++){
		flag = true;
		for(int j = (r[i] ^ 48) ; j <= 9 ; j++)
			if(x[j] >= 1){
				flag = false;
				x[j]--;
				break;
			}
		ansx += flag;
		if(flag)
			for(int j = 0 ; j <= (r[i] ^ 48) - 1 ; j++)
				if(x[j] >= 1){
					x[j]--;
					break;
				}
	}
	for(int i = 1 ; i <= n ; i++){
		flag = true;
		for(int j = (r[i] ^ 48) + 1 ; j <= 9 ; j++)
			if(y[j] >= 1){
				flag = false;
				y[j]--;
				break;
			}
		ansy += 1 - flag;
		if(flag)
			for(int j = 0 ; j <= (r[i] ^ 48) ; j++)
				if(y[j] >= 1){
					y[j]--;
					break;
				}
	}
	cout << ansx << "\n" << ansy << "\n"; 
	return 0;
}
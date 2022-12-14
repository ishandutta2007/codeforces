//In the name of God
#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int c = a+1;
	while(1){
		int tmp = c;
		int cnt = 0;
		while(tmp){
			if(tmp % 10 == 4 || tmp % 10 == 7){
				cnt *= 10;
				cnt += tmp % 10;
			}
			tmp/=10;
		}
		tmp = cnt;
		cnt = 0;
		while(tmp){
			cnt *= 10;
			cnt += tmp % 10;
			tmp/=10;
		}
		if(cnt == b){
			cout << c << endl;
			return 0;
		}
		c++;
	}
}
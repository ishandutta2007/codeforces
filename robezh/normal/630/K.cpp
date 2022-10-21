#include<cstdio>
#include<iostream>
using namespace std;

bool divi[2550];
int num[2550];

long long n;

int main(){
	int cnt = 0;
	fill(divi, divi+2550, false);
	fill(num, num+2550, 0);
	for(int i = 1; i <= 2520; i++){
		for(int j = 2; j <= 10; j++){
			if(i % j == 0){
				divi[i] = true;
				cnt ++;
				break;
			}
		}
		if(!divi[i]) num[i] = num[i-1] + 1;
		else num[i] = num[i-1];
	}
	cin >> n;
	//cout << cnt;
	cout << (long long) (2520 - cnt) * (n / 2520) + num[n % 2520];
	
}
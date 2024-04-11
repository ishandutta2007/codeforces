#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		bool good = false;
		for(int i = 0; i < 100; i++){
			if(t - 3 * i >= 0 && (t - 3 * i)%7 == 0){
				printf("YES\n");
				good = true;
				break;
			}
		}
		if(!good) printf("NO\n");
	}
	
}
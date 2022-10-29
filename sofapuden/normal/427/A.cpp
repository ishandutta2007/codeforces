#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int police = 0;
	int ans = 0;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp; police+= tmp;
		if(police < 0){
			 ans+=abs(police);
			 police = 0;
		 }
	 }
	 cout << ans << "\n";
			
}
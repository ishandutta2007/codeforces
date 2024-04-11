#include <bits/stdc++.h>

using namespace std;

int main(){
	int s, t1, t2, v1, v2; cin >> s >> t1 >> t2 >> v1 >> v2;
	int per1 = s*t1 + 2*v1;
	int per2 = s*t2 + 2*v2;
	if(per1 == per2){
		cout << "Friendship\n";
		return 0;
	}
	cout << (per1 > per2?"Second":"First");
}
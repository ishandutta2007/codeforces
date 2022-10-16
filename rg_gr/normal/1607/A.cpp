#include<bits/stdc++.h>
using namespace std;
 
int pos[26] , T;
 
int main(){
	for(cin >> T ; T ; --T){
		string s , t; cin >> s >> t; int sum = 0;
		for(int i = 0 ; i < 26 ; ++i) pos[s[i] - 'a'] = i;
		for(int i = 1 ; i < t.size() ; ++i) sum += abs(pos[t[i] - 'a'] - pos[t[i - 1] - 'a']);
		cout << sum << endl;
	}
	return 0;
}
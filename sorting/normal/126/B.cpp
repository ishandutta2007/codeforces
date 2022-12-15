#include <bits/stdc++.h>

using namespace std;

const unsigned long long base = 27;

string s;
int n;

vector<int> possible;

bool check(int len){
	unsigned long long power = 1, true_hash = 0, curr_hash = 0;

	for(int i = 0; i < len; i++){
		true_hash *= base;
		true_hash += (s[i] - 'a' + 1);
		power *= base;
	}

	curr_hash = true_hash;

	bool ok = false;

	for(int i = len; i < n - 1; i++){
		curr_hash *= base;
		curr_hash -= power * (s[i - len] - 'a' + 1);
		curr_hash += (s[i] - 'a' + 1);

		if(curr_hash == true_hash){
			return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	n = s.size();

	unsigned long long prefix = 0, suffix = 0, power = 1;

	for(int i = 1; i <= n - 2; i++, power *= base){
		prefix *= base;
		prefix += (s[i -1] - 'a' + 1);
		suffix += (s[n - i] - 'a' + 1) * power;

		if(suffix == prefix){
			possible.push_back(i);
			//cout << i << endl;
		}
	}

	if(possible.empty()){
		cout << "Just a legend\n";

		return 0;
	}

	int l = 0, r = (int)possible.size() - 1;

	while(l != r){
		int mid = (l + r + 1) >> 1;

		//cout << mid << " " << possible[mid] << " - " << check(possible[mid]) << endl; 

		if(check(possible[mid])){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}

	if(!check(possible[l])){
		cout << "Just a legend\n";
		return 0;
	}

	for(int i = 0; i < possible[l]; i++){
		cout << s[i];
	}
	cout << "\n";

	return 0;
}
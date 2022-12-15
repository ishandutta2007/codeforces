#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int inf = 1e9;

struct dp_pair{
	int first;
	bool second, choice;

	dp_pair(){
		first = 0;
		second = false;
		choice = false;
	}
};

bool chkmx(int &lvalue, int rvalue){
	if(lvalue >= rvalue){
		return false;
	}

	lvalue = rvalue;

	return true;
}

string n;
dp_pair dp[N][2][3];

int solve(int pos, bool start, int rem){
	if(pos == n.size()){
		if(rem == 0){
			return 0;
		}
		return -inf;
	}

	dp_pair &p = dp[pos][start][rem];

	if(p.second){
		return p.first;
	}

	p.second = true;

	p.first = solve(pos + 1, start, rem);
	p.choice = false;

	if(n[pos] == '0'){
		if(start){
			p.choice = chkmx(p.first, solve(pos + 1, true, rem) + 1);
		}
	}
	else{
		p.choice = chkmx(p.first, solve(pos + 1, true, (rem + n[pos] - '0') % 3) + 1);
	}

	return p.first;
}

void output(int pos, bool start, int rem){
	if(pos == n.size()){
		return;
	}

	dp_pair &p = dp[pos][start][rem];

	if(p.choice){
		cout << n[pos];
		output(pos + 1, true, (rem + n[pos] - '0') % 3);
	}
	else{
		output(pos + 1, start, rem);
	}

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int x = solve(0, false, 0);

	if(x <= 0){
		for(char c: n){
			if(c == '0'){
				cout << "0\n";
				return 0;
			}
		}

		cout << "-1\n";

		return 0;
	}

	output(0, false, 0);
	cout << "\n";

	return 0;
}
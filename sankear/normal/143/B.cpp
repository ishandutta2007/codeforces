#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

int main(){
	//freopen("chess.in", "r", stdin);
	//freopen("chess.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	string res = "";
	int i = 0;
	if(s[0] == '-'){
		res += '(';
		i++;
	}
	res += '$';
	string r = "";
	while(i < (int)s.length() && s[i] != '.'){
		r += s[i++];
	}
	bool fl = false;
	for(int i = 0; i < (int)r.length() % 3; i++){
		fl = true;
		res += r[i];
	}
	r = r.substr((int)r.length() % 3, (int)r.length() - (int)r.length() % 3);
	for(int i = 0; i < (int)r.length(); i += 3){
		if(fl){
			res += ',';
		}
		fl = true;
		res += r[i];
		res += r[i + 1];
		res += r[i + 2];
	}
	i++;
	res += '.';
	for(int it = 0; it < 2; it++){
		if(i >= (int)s.length()){
			res += '0';
		}
		else{
			res += s[i++];
		}
	}
	if(s[0] == '-'){
		res += ')';
	}
	cout << res << endl;
	return 0;
}
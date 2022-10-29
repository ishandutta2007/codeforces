#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

string inp, res;

int main(){
	getline(cin, inp, '\n');
	int n = inp.length(), i (0);
	while(i < n){
		if(i < n - 2 && inp[i] == 'W' && inp[i + 1] == 'U' && inp[i + 2] == 'B'){
			if(res.size() != 0 && res[res.size() - 1] != ' ')res += ' ';
			i += 3;
		}
		else
			res += inp[i++];
	}
	if(res[res.size() - 1] == ' ')res.erase(res.size() - 1, 1);
	cout << res << '\n';

	return 0;
}
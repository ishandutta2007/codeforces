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

const int inf = (int)1e9;

int val[100100];

vector <int> calcz(string s){
	int n = s.size();
	vector <int> res(n);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(i <= r){
			res[i] = min(r - i + 1, res[i - l]);
		}
		while(i + res[i] < n && s[i + res[i]] == s[res[i]]){
			res[i]++;
		}
		if(i + res[i] - 1 > r){
			l = i;
			r = i + res[i] - 1;
		}
	}
	return res;
}

string rev(string s){
	string res = "";
	for(int i = s.size() - 1; i >= 0; i--){
		res += s[i];
	}
	return res;
}

int main(){
	//freopen("tea.in", "r", stdin);
	//freopen("tea.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int len1 = s.size(), n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		string r;
		cin >> r;
		vector <int> z1 = calcz(rev(r) + '#' + rev(s));
		vector <int> z2 = calcz(r + '#' + s);
		int len2 = r.size();
		for(int j = 0; j < len1; j++){
			val[j] = -inf;
		}
		bool fl = false;
		for(int j = 0; j < len1; j++){
			if(j - len2 + 1 >= 0){
				if(val[j - len2 + 1] + z1[len2 + len1 - j] >= len2){
					fl = true;
					break;
				}
			}
			val[j] = max((j > 0 ? val[j - 1] : 0), z2[len2 + j + 1]);
		}
		if(fl){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
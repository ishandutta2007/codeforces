#include <iostream>
#include <cmath>
#define Min(x , y) ((x) < (y) ? (x) : (y))

using namespace std;

int n;
long long ans = 0;
string s[500001];

int Log(int k){
	return floor(log(k) / log(2.0));
}
void Change(int d){
	int p = 0 , w = (2 << Log(Min(s[d].size() , s[d + 1].size()))) / 2 , del;
	for(int i = w ; i >= 1 ; i = i >> 1)
		if(s[d].substr(0 , p + i) == s[d + 1].substr(0 , p + i))
			p += i;
	del = s[d].size();
	s[d].erase(p , s[d].size());
	ans += del - s[d].size();
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> s[i];
	for(int i = 1 ; i < n ; i++)
		if(s[i] > s[i + 1])
			Change(i);
	for(int i = n ; i > 1 ; i--)
		if(s[i - 1] > s[i])
			Change(i - 1);
	for(int i = 1 ; i <= n ; i++)
	    cout << s[i] << "\n";
	return 0;
}
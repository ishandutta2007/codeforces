#include <iostream>
#include <cstdio>
#define M(x) ((x) % 1000000007)
#define Maxl 100001

using namespace std;

int m , len , k;
long long ans[2][Maxl];
string s , p;

inline bool Check(int d){
	for(int i = 0 ; i < len ; i++)
		if(s[i] != p[(i + d) % len])
			return false;
	return true;
}

int main(){
	cin >> s >> p;
	if(s.size() != p.size()){
		printf("0\n");
		return 0;
	}
	len = s.size();
	for(int i = 0 ; i < len ; i++)
		if(Check(i))
			k++;
	cin >> m;
	ans[0][0] = (s != p);
	ans[1][0] = (s == p);
	for(int i = 1 ; i <= m ; i++){
		ans[0][i] = M(ans[0][i - 1] * (len - k - 1) + ans[1][i - 1] * (len - k));
		ans[1][i] = M(ans[1][i - 1] * (k - 1) + ans[0][i - 1] * k);
	}
	cout << ans[1][m] << endl;
	return 0;
}

// By Sooke.
// CF176B Word Cut.
#include <bits/stdc++.h>
using namespace std;

string a, b;
int ps[1000000][2];
int n, m;

int main(){
	cin >> a >> b;
	int set = 0;
	for(char c : b)
		set += (c == '1' ? 1 : 0);
	if(a[0] == '1')
		ps[0][1] = 1;
	else
		ps[0][0] = 1;

	for(int i = 1; i < a.size(); i++){
		ps[i][1] = ps[i - 1][1];
		ps[i][0] = ps[i - 1][0];
		(a[i] == '1' ? ps[i][1] : ps[i][0])++;
	}
	m = b.size();
	int ans = 0;
	if(ps[m - 1][1] % 2 == set % 2)
		ans++;
	for(int i = m; i < a.size(); i++){
		if((ps[i][1] - ps[i - m][1]) % 2 == set % 2)
			ans++;
	}

	cout << ans << endl;
}
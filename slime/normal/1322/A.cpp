#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
char inp[maxn];
int cal(char a) {
	if (a == '(') return 1;
	return -1; 
} 
int main() {
	int n;
	cin >> n;
	scanf("%s", inp + 1);
	int s = 0;
	for(int i = 1; i <= n; i++) s += cal(inp[i]);
	if (s != 0) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ) {
		int j = i + 1;
		int s = cal(inp[i]);
		int fl = 0;
		while (j <= n) {
			if (s < 0) fl = 1;
			s += cal(inp[j]);
			j++;
			if (s == 0) break;
		}
		if (fl) ans += j - i;
		i = j;
	} 
	cout << ans << endl;
	return 0;
}
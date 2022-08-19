#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int p[maxn];
int fl[maxn]; 
vi nr;
char x[maxn][10] ;
char y[10];
int main() {
	scanf("%s", y);
	cin >> n;
	int fl[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		scanf("%s", x[i]);
		if (x[i][0] == y[0] && x[i][1] == y[1]) {
			printf("YES\n");
			return 0;
		}
		if (x[i][1] == y[0]) fl[0] = 1;
		if (x[i][0] == y[1]) fl[1] = 1;
	}
	if (fl[1] && fl[0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
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
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		nr.clear();
		for (int i = 1; i <= n - 1; i++)
			if (p[i] > p[i + 1]) 
				fl[i] = 1;
			else fl[i] = 0;
		int md = n / 2;
		while (!fl[md] && md > 0) md--;
		if (md == 0) printf("0 0 0\n");
		else {	
			int f = 0;
			for (int j = 1; 3 * j + 2 <= md; j++)
				if (!fl[j]) continue;
				else {
				
					for (int u = 2 * j + 1; u <= md; u++)
						if (fl[u] && md - u > j) {
							f = 1;
							printf("%d %d %d\n", j, u - j, md - u);
							break;
						}
				
					break;
				}	
			if (!f) printf("0 0 0\n");
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;

int N, ch[190][10], num[55], cost[1100100], f[1100100];

bool ok (string a, string b, int req) {
	int A = (int) a.size(), ans = 0;
	fo(i,0,A)fo(j,i+1,A)fo(k,j+1,A)fo(l,k+1,A)fo(m,l+1,A) {
		if (a[i]=='a'&&a[j]=='a'&&a[k]=='a'&&a[l]=='a'&&a[m]=='b') {
			ans++;
		}
	}
	printf("got %d\n", ans);
	return ans == req;
}

int main () {
	scanf("%d", &N);

	fo(i, 0, 50) num[i] = 0;
	fo(i, 0, 190) fo(j, 0, min(i+1, 5)) {
		if (!i || !j) ch[i][j] = 1;
		else ch[i][j] = (ch[i-1][j] + ch[i-1][j-1]);
	}
	//fo(i, 4, 30) printf("%d\n", ch[i][4]);

	int worst = 0, t;
	fill(cost+1, cost+1000*1000+1, 2e9);
	fo(i, 0, 1000*1000+1) {
		fo(j, 4, 25) {
			t = i + ch[j][4];
			if (t < 1000*1000+1 && cost[t] > cost[i] + 1) {
				cost[t] = cost[i] + 1;
				f[t] = j;
			}
		}
		worst = max(worst, cost[i]);
	}

	while (N) {
		num[f[N]]++;
		N -= ch[f[N]][4];
	}

	string ans;
	fo(i, 1, 51) {
		ans += 'a';
		fo(j, 0, num[i]) ans += 'b';
	}
	assert((int) ans.size() < 200);
	printf("%s aaaab\n", ans.c_str());

	//assert(ok(ans, "aaaab", 50));

	return 0;
}
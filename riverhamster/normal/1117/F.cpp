#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100005, L = 17, ST = (1 << 17) + 5;
int f[ST], sum[N][L];
bool ban[L][L][ST], a[L][L];
char s[N];
int n, p;

int find_increment(int x, int al){
	int l = x + 1, r = n, mid, ans = -1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(sum[mid][al] > sum[x][al]){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void pre(){
	for(int i=1; i<=n; ++i){
		for(int j=0; j<p; ++j)
			sum[i][j] = sum[i-1][j];
		++sum[i][s[i]-'a'];
	}
	int nxt, b;
	for(int i=1; i<=n; i++){
		for(int j=0; j<p; j++){
			if(a[s[i]-'a'][j]) continue;
			nxt = find_increment(i, j);
			// printf("find_increment(%d, %c) = %d\n", i, j+'a', nxt);
			if(nxt == -1) continue;
			b = 0;
			for(int k=0; k<p; k++)
				b |= (int)(sum[nxt-1][k] - sum[i][k] != 0) << k;
			ban[s[i]-'a'][j][b] = true;
			// printf("banned [%c, %c] %d\n", s[i], j+'a', b);
		}
	}
	for(int i=0; i<p; ++i)
		for(int j=0; j<p; ++j){
			if(a[i][j]) continue;
			for(int k=0; k<(1<<p); ++k)
				for(int m=0; m<p; ++m)
					ban[i][j][k|(1<<m)] |= ban[i][j][k];
		}
}

void dp(){
	f[0] = true;
	bool flag;
	int ans = n, now;
	for(int i=0; i<(1<<p); ++i){
		flag = true;
		// printf("check %d\n", i);
		for(int j=0; j<p; ++j){
			if((i & (1 << j))) continue;
			// printf("checking: %d\n", j);
			for(int k=0; k<p; ++k)
				if(ban[j][k][i] && (i & (1 << k)) == 0){
					f[i] = false;
					flag = false; goto donecheck;
				}
		}
		donecheck: if(!flag || !f[i]){
			// printf("%d is invaild\n", i);
			continue;
		}
		now = 0;
		for(int j=0; j<p; ++j)
			now += (i & (1 << j)) ? 0 : sum[n][j];
		ans = min(ans, now);
		for(int j=0; j<p; ++j)
			f[i|(1<<j)] |= f[i];
	}
	printf("%d\n", ans);
}


int main(){
	// freopen("cf1117f.in", "r", stdin);
	// freopen("cf1117f.out", "w", stdout);
	scanf("%d%d", &n, &p);
	scanf("%s", s+1);
	int x;
	for(int i=0; i<p; i++)
		for(int j=0; j<p; j++)
			scanf("%d", &x), a[i][j] = x;
	pre();
	dp();
	return 0;
}
#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 1501, M = 31;

int n, m;
long long ans;
char type[MAXN][M], in[256], s[M];
map<long long, bool> mp;

long long translate(char *s){
	long long ret = 0;
	for(int i = 0; i < m; i++)
		ret |= (long long) in[s[i]] << (i << 1);
	return ret;
}

int main(){
	in['S'] = 0, in['E'] = 1, in['T'] = 2;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", type[i]);
	mp[translate(type[n])] = true;
	for(int j = n - 1; j; j--){
		for(int i = j - 1; i; i--){
			for(int k = 0; k < m; k++){
				if(type[i][k] == type[j][k]) s[k] = type[i][k];
				else if(type[i][k] != 'S' && type[j][k] != 'S') s[k] = 'S';
				else if(type[i][k] != 'E' && type[j][k] != 'E') s[k] = 'E';
				else if(type[i][k] != 'T' && type[j][k] != 'T') s[k] = 'T';
			}
			if(mp.count(translate(s))) ans++;
		}
		mp[translate(type[j])] = true;
	}
	printf("%lld", ans);
	return 0;
}
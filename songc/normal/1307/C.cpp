#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL c[30], cnt[30][30], ans;
char str[101010];

int main(){
	scanf("%s", str+1);
	N = strlen(str+1);
	for (int i=1; i<=N; i++){
		for (int j=0; j<26; j++) cnt[j][str[i]-'a'] += c[j];
		c[str[i]-'a']++;
	}
	for (int i=0; i<26; i++) for (int j=0; j<26; j++) ans = max(ans, cnt[i][j]), ans = max(ans, c[i]);
	printf("%lld\n", ans);
	return 0;
}
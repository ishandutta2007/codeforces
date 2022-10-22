#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
char str[101010];

int main(){
	scanf("%d", &TC);
	str[0] = '1';
	while (TC--){
		scanf("%s", str+1);
		int c = 0;
		for (int i=1; str[i]; i++){
			if (str[i] == '0' && str[i-1] == '1') c++;
		}
		if (c == 0) puts("0");
		else if (c == 1) puts("1");
		else puts("2");
	}
	return 0;
}
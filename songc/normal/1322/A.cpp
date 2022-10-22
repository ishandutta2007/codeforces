#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int tc, N, ans;
char str[1010101];

int main(){
	scanf("%d", &N);
	scanf("%s", str+1);
	int x=0, l=0;
	bool tf = true;
	for (int i=1; i<=N; i++){
		if (str[i]=='(') x++;
		else x--;
		l++;
		if (x < 0) tf = false;
		if (x == 0){
			if (!tf) ans += l;
			tf=true, l=0;
		}
	}
	if (x) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
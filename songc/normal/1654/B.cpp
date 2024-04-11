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
char S[202020];
bool chk[30];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%s", S+1);
		N = strlen(S+1);
		int x=0;
		for (int i=0; i<27; i++) chk[i] = false;
		for (int i=N; i>0; i--){
			if (chk[S[i]-'a']) continue;
			else chk[S[i]-'a']=true, x=i;
		}
		printf("%s\n", S+x);
	}
	return 0;
}
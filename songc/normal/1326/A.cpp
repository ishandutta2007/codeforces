#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, ans;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		if (N==1) puts("-1");
		else {
			N--;
			while (N--) printf("3");
			printf("4\n");
		}
	}
	return 0;
}
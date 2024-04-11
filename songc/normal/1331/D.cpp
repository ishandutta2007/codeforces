#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
char str[1010];

int main(){
	scanf("%s", str+1);
	printf("%d\n", (str[7]-'0')&1);
	return 0;
}
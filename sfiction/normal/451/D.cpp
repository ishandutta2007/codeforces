/*
ID: Sfiction
OJ: CF
PROB: 451D
*/
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN=1E5+10;

char s[MAXN];
long long cnt[2][2], ans[2];

int main(){
	scanf("%s",s);
	for (int j,i=0;s[i];++i){
		j=s[i]-'a';
		++cnt[j][i&1];
		ans[0]+=cnt[j][!(i&1)];
		ans[1]+=cnt[j][i&1];
	}
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
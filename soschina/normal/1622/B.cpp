#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, p[N], cntlk, cntdlk;
struct node{
	int i, p;
	bool operator<(const node &b) const{
		return p < b.p;
	}
}lk[N], dlk[N];

char s[N + 1];

int main(){
	scanf("%d", &t);
	while(t--){
		cntlk = cntdlk = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; i++){
			if(s[i] == '1'){
				cntlk++;
				lk[cntlk].i = i;
				lk[cntlk].p = p[i];
			}else{
				cntdlk++;
				dlk[cntdlk].i = i;
				dlk[cntdlk].p = p[i];
			}
		}
		sort(lk + 1, lk + 1 + cntlk);
		sort(dlk + 1, dlk + 1 + cntdlk);
		for(int i = 1; i <= cntdlk; i++)
			p[dlk[i].i] = i;
		for(int i = 1; i <= cntlk; i++)
			p[lk[i].i] = cntdlk + i;
		for(int i = 1; i <= n; i++)
			printf("%d ", p[i]);
		putchar('\n');
	}
	return 0;
}
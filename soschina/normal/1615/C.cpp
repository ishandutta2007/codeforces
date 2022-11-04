#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, cntsame, cntsame1, cntdiff, cntdiff1;
char a[N], b[N];

int main(){
	scanf("%d", &t);
	while(t--){
		cntsame = cntsame1 = cntdiff = cntdiff1 = 0;
		scanf("%d%s%s", &n, a, b);
		for(int i = 0; i < n; i++){
			if(a[i] == b[i]){
				cntsame++;
				if(a[i] == '1') cntsame1++;
			}else{
				cntdiff++;
				if(a[i] == '1') cntdiff1++;
			}
		}
		if(cntsame1 - (cntsame - cntsame1) == 1)
			cntsame1 = 1;
		else cntsame1 = 0;
		if(cntdiff1 == cntdiff - cntdiff1)
			cntdiff1 = 1;
		else cntdiff1 = 0;
		if(cntsame1 && cntdiff1)
			printf("%d\n", min(cntsame, cntdiff));
		else if(cntsame1)
			printf("%d\n", cntsame);
		else if(cntdiff1)
			printf("%d\n", cntdiff);
		else puts("-1");
	}
	return 0;
}
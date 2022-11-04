#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], maxa, seca, cntm, cnts;

int main(){
	scanf("%d", &t);
	while(t--){
		seca = 0;
		maxa = 0;
		cntm = 0;
		cnts = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			if(a[i] > maxa){
				seca = maxa;
				cnts = cntm;
				maxa = a[i];
				cntm = 1;
			}
			else if(a[i] == maxa)
				cntm++;
			else if(a[i] > seca){
				seca = a[i];
				cnts = 1;
			}
			else if(a[i] == seca)
				cnts++;
		}
		puts(cntm == 1 && maxa - seca > 1 ? "NO" : "YES");
	}
	return 0;
}
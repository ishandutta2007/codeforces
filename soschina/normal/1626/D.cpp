#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 2;

int t, n, a, cnt[N], pre[N], suf[N];
vector<int> ppre, psuf;

int main(){
	scanf("%d", &t);
	while(t--){
		ppre.clear();
		psuf.clear();
		for(int i = 1; i <= n; i++)
			cnt[i] = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a);
			cnt[a]++;
		}
		int prelast = 0;
		for(int i = 1; i <= n; i++){
			pre[i] = pre[i - 1] + cnt[i];
			if(pre[i] > prelast){
				ppre.push_back(i - 1);
				prelast = 1;
				while(prelast < pre[i]) prelast <<= 1;
			}
		}
		ppre.push_back(n);
		suf[n + 1] = 0;
		int suflast = 0;
		for(int i = n; i > 0; i--){
			suf[i] = suf[i + 1] + cnt[i];
			if(suf[i] > suflast){
				psuf.push_back(i + 1);
				suflast = 1;
				while(suflast < suf[i]) suflast <<= 1;
			}
		}
		psuf.push_back(1);
		int ans = 0x7fffffff;
		for(int pp : ppre)
			for(int ps : psuf){
				if(pp >= ps) break;
				int a = 1;
				while(a < pre[pp]) a <<= 1;
				int b = 1;
				while(b < suf[ps]) b <<= 1;
				int c = 1;
				while(c < n - pre[pp] - suf[ps]) c <<= 1;
				ans = min(ans, a + b + c - n);
			}
		printf("%d\n", ans);
	}
	return 0;
}
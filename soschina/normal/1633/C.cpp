#include <cstdio>
using namespace std;

int t;
long long hc, dc, hm, dm, k, w, a;

int main(){
	scanf("%d", &t);
	while(t--){
		bool canwin = false;
		scanf("%lld%lld%lld%lld%lld%lld%lld", &hc, &dc, &hm, &dm, &k, &w, &a);
		for(int i = 0; i <= k; i++){
			long long hc_ = hc + i * a;
			long long dc_ = dc + (k - i) * w;
			long long c = (hc_ - 1) / dm + 1;
			long long m = (hm - 1) / dc_ + 1;
			if(c >= m) canwin = true;
		}
		puts(canwin ? "YES" : "NO");
	}
	return 0;
}
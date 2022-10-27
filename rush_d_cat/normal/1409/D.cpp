#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n; int s;

vector<int> v;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%d",&n,&s);
		LL nn=n;
		v.clear();
		while (n) {
			v.push_back(n%10); n/=10;
		}
		while(v.size()<19) v.push_back(0);
		reverse(v.begin(),v.end());
		//for(int i=0;i<v.size();i++)printf("%d", v[i]);printf("\n");
		int sum=0;
		for(auto x: v) sum += x;
		if (sum <= s) {
			printf("0\n"); continue;
		}
		bool ok=0;

		for(int i=17;i>=-1;i--){
			int sum=0; 
			for(int j=0;j<=i;j++) sum+=v[j];
			for(int j=v[i+1]+1;j<=9;j++){
				int tmp=sum+j;
				// [0,i],j
				//printf("tmp=%d, %d\n", tmp, v[i+1]);
				int need=s-tmp;
				int cnt=19-(i+2);
				//printf("i=%d,cnt=%d,need=%d\n", i,cnt,need);
				if(need>=0){
					ok=1; 
					vector<int> ans;
					for(int x=0;x<=i;x++) ans.push_back(v[x]);
					ans.push_back(j);
					vector<int> suf;
					for(int x=1;x<=cnt;x++){
						suf.push_back(0);
					}
					for(auto x:suf) ans.push_back(x);
					LL r=0;
					for(int i=0;i<ans.size();i++){
						r=r*10+ans[i];
					}
					printf("%lld\n", r-nn);
					break;
				}
			}
			if(ok)break;
		}
	}
}
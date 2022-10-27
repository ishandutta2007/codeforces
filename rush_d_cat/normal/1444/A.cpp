#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	int t; scanf("%d",&t);
	while(t--) {
		LL p,q; scanf("%lld%lld",&p,&q);
		if(p%q) printf("%lld\n", p);
		else {
			vector< pair<LL,int> > d;
			int qq=q;
			for(int i=2;i*i<=qq;i++){
				if(qq%i==0){
					int c=0;
					while(qq%i==0){
						qq/=i; c++;
					}
					d.push_back(make_pair(i,c));
				}
			}
			if(qq>1) d.push_back(make_pair(qq,1));


			LL mx=0;
			for(auto item: d) {
				int a_ = 0;
				LL tmp = p;
				LL M1=1,M2=1;
				while(tmp % item.first == 0) {
					a_ ++; tmp /= item.first;
					M1 *= item.first;
				}
				for(int i=1;i<item.second;i++){
					M2 *= item.first;
				}
				mx = max(mx, p / M1 * M2);
			}
			printf("%lld\n", mx);
		}
	}

}
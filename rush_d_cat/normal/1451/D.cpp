#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {

	scanf("%d", &t);
	while(t--){
		LL d, k; scanf("%lld%lld",&d,&k);
		LL mn=1e9;
		for(LL x=0;x*k<=d;x++){
			LL y=sqrt(d*d- (x*k)*(x*k) ) / k;
			mn=min(mn,abs(x-y));
			//printf("%lld %lld\n", x, y);
		}
		for(LL x=0;x*k<=d;x++){
			LL y=sqrt(d*d- (x*k)*(x*k) ) / k;
			if(abs(x-y)==mn){
				printf("%s\n", (x+y)%2==0?"Utkarsh":"Ashish"); break;
			}
		}
    }
}
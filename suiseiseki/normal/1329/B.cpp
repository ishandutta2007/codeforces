#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int T,d,m;
ll ans;
int main(){
	scanf("%d", &T);
	while(T--){
		ans=1;
		scanf("%d%d",&d,&m);
		for(int i=0;(1<<i)<=d;i++){
			(ans*=(min(d,(1<<(i+1))-1))-(1<<i)+2)%=m;
		}
		printf("%lld\n",(ans-1+m)%m);
	}
	return 0;
}
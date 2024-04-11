#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll __int64
ll sum[250000];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(sum,0,sizeof(sum));
		ll tot=0;
		stack<ll>s;
		s.push(0);
		for(int i=0;i<n;i++){
			ll op;
			scanf("%I64d",&op);
			if(op==1){
				ll x;
				scanf("%I64d",&x);
				ll val;
				scanf("%I64d",&val);
				sum[x]+=val;
				tot+=x*val;
			}
			if(op==2){
				ll x;
				scanf("%I64d",&x);
				s.push(x);
				tot+=x;
			}
			if(op==3){
				ll u=s.top();
				tot-=u+sum[s.size()];
				sum[s.size()-1]+=sum[s.size()];
				sum[s.size()]=0;
				s.pop();
			}
			double fenzi=tot;
			double fenmu=s.size();
			printf("%.6lf\n",fenzi/fenmu);
		}
	}
	return 0;
}
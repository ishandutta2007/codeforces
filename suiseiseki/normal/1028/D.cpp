#include <queue>
#include <cstdio>
const int Maxn=363304;
const int Mod=1000000007;
int n;
std::priority_queue<int> q_l;
std::priority_queue<int,std::vector<int>,std::greater<int> > q_r,q_m;
int main(){
	scanf("%d",&n);
	int ans=1;
	for(int i=1;i<=n;i++){
		char op[10];
		scanf("%s",op);
		if(op[1]=='D'){
			int v;
			scanf("%d",&v);
			if(!q_l.empty()&&v<q_l.top()){
				q_l.push(v);
			}
			else if(!q_r.empty()&&v>q_r.top()){
				q_r.push(v);
			}
			else{
				q_m.push(v);
			}
		}
		else{
			int v;
			scanf("%d",&v);
			if(!q_l.empty()&&v<q_l.top()){
				puts("0");
				return 0;
			}
			if(!q_r.empty()&&v>q_r.top()){
				puts("0");
				return 0;
			}
			if(!q_l.empty()&&q_l.top()==v){
				q_l.pop();
				while(!q_m.empty()){
					q_r.push(q_m.top());
					q_m.pop();
				}
			}
			else if(!q_r.empty()&&q_r.top()==v){
				q_r.pop();
				while(!q_m.empty()){
					q_l.push(q_m.top());
					q_m.pop();
				}
			}
			else{
				ans=(ans<<1)%Mod;
				while(q_m.top()!=v){
					q_l.push(q_m.top());
					q_m.pop();
				}
				q_m.pop();
				while(!q_m.empty()){
					q_r.push(q_m.top());
					q_m.pop();
				}
			}
		}
	}
	ans=1ll*ans*((int)q_m.size()+1)%Mod;
	printf("%d\n",ans);
	return 0;
}
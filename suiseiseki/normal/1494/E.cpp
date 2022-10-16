#include <map>
#include <cstdio>
#include <algorithm>
std::map<std::pair<int,int>,char> mp;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int num_0=0,num_1=0;
	for(int i=1;i<=m;i++){
		char op[5];
		scanf("%s",op);
		if((*op)=='-'){
			int u,v;
			scanf("%d%d",&u,&v);
			if(mp.count(std::make_pair(v,u))>0){
				num_1--;
				if(mp[std::make_pair(v,u)]==mp[std::make_pair(u,v)]){
					num_0--;
				}
			}
			mp.erase(std::make_pair(u,v));
		}
		else if((*op)=='+'){
			int u,v;
			char c[5];
			scanf("%d%d%s",&u,&v,c);
			if(mp.count(std::make_pair(v,u))>0){
				num_1++;
				if(mp[std::make_pair(v,u)]==(*c)){
					num_0++;
				}
			}
			mp[std::make_pair(u,v)]=(*c);
		}
		else{
			int k;
			scanf("%d",&k);
			if(k&1){
				if(num_1>0){
					puts("YES");
				}
				else{
					puts("NO");
				}
			}
			else{
				if(num_0>0){
					puts("YES");
				}
				else{
					puts("NO");
				}
			}
		}
	}
	return 0;
}
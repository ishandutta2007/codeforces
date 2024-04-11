#include <cstdio>
#include <map>
using namespace std;
map<int,int> mp;
int main(){
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		mp[a]++;
	}
	map<int,int>::iterator it;
	it=mp.begin();
	int ans=0,tmp;
	while(it!=mp.end()){
		for(tmp=0;tmp<=30;tmp++){
			if((1<<tmp)<=(it->first)||((1<<tmp)-(it->first)==(it->first)&&(it->second)==1)){
				continue;
			}
			if(mp.find((1<<tmp)-(it->first))!=mp.end()){
				break;
			}
		}
		if(tmp==31){
			ans+=(it->second);
		}
		it++;
	}
	printf("%d\n",ans);
	return 0;
}
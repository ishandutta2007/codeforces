#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=2000;
const int Inf=0x3f3f3f3f;
int n,k;
char s[Maxn+5][Maxn+5];
int val[Maxn+5][Maxn+5];
int cur[Maxn+5][Maxn+5];
std::vector<std::pair<int,int> > lis[Maxn*2+5];
char ans[Maxn*2+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lis[i+j].push_back(std::make_pair(i,j));
		}
	}
	memset(val,0x3f,sizeof val);
	val[0][1]=val[1][0]=0;
	for(int i=2;i<=n*2;i++){
		char mn_val='z'+1;
		std::vector<std::pair<int,int> > mn_lis;
		for(std::pair<int,int> j:lis[i]){
			int x=j.first,y=j.second;
			char cur_val='z'+1;
			int cur_k=Inf;
			if(val[x-1][y]<=k){
				if(val[x-1][y]<k&&s[x][y]!='a'){
					cur_val='a',cur_k=std::min(cur_k,val[x-1][y]+1);
				}
				else if(s[x][y]<=cur_val){
					cur_val=s[x][y],cur_k=std::min(cur_k,val[x-1][y]);
				}
			}
			if(val[x][y-1]<=k){
				if(val[x][y-1]<k&&s[x][y]!='a'){
					cur_val='a',cur_k=std::min(cur_k,val[x][y-1]+1);
				}
				else if(s[x][y]<=cur_val){
					cur_val=s[x][y],cur_k=std::min(cur_k,val[x][y-1]);
				}
			}
			cur[x][y]=cur_k;
			if(cur_val<mn_val){
				mn_val=cur_val,mn_lis.clear(),mn_lis.push_back(j);
			}
			else if(cur_val==mn_val){
				mn_lis.push_back(j);
			}
		}
		for(std::pair<int,int> j:mn_lis){
			int x=j.first,y=j.second;
			val[x][y]=cur[x][y];
		}
		ans[i]=mn_val;
	}
	for(int i=2;i<=n*2;i++){
		putchar(ans[i]);
	}
	puts("");
	return 0;
}
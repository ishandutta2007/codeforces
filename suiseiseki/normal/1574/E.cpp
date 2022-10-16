#include <map>
#include <cstdio>
const int Maxn=1000000;
const int Mod=998244353;
int n,m,k;
std::map<std::pair<int,int>,int> mp;
int pow_2[Maxn+5];
void init(){
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
namespace Subtask_1{
	int val[Maxn+5][2];
	int sum[2];
	int num_not;
	int ans;
	void insert(int x,int y,int c){
		if(c==-1){
			int last=mp[std::make_pair(x,y)]^(x&1)^1;
			if(val[y][last]-1==0){
				if(val[y][0]&&val[y][1]){
					num_not--;
				}
				sum[(y&1)^last]--;
			}
			val[y][last]--;
			if(val[y][0]==0&&val[y][1]==0){
				ans--;
			}
		}
		else{
			c^=(x&1)^1;
			if(val[y][c]==0){
				if(val[y][c^1]>0){
					num_not++;
				}
				sum[(y&1)^c]++;
			}
			if(val[y][0]==0&&val[y][1]==0){
				ans++;
			}
			val[y][c]++;
		}
	}
	int query(){
		if(num_not>0){
			return 0;
		}
		return (pow_2[m-ans]-(sum[0]==0)-(sum[1]==0)+Mod)%Mod;
	}
}
namespace Subtask_2{
	int sum[Maxn+5][2];
	int num_not;
	int ans;
	void insert(int x,int y,int c){
		if(c==-1){
			int last=mp[std::make_pair(x,y)]^(y&1)^1;
			if(sum[x][last]-1==0&&sum[x][last^1]>0){
				num_not--;
			}
			sum[x][last]--;
			if(sum[x][0]==0&&sum[x][1]==0){
				ans--;
			}
		}
		else{
			c^=(y&1)^1;
			if(sum[x][c]==0&&sum[x][c^1]>0){
				num_not++;
			}
			if(sum[x][0]==0&&sum[x][1]==0){
				ans++;
			}
			sum[x][c]++;
		}
	}
	int query(){
		if(num_not>0){
			return 0;
		}
		return pow_2[n-ans];
	}
}
int main(){
	init();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		if(mp.find(std::make_pair(x,y))==mp.end()){
			mp[std::make_pair(x,y)]=-1;
		}
		if(t==-1){
			if(mp[std::make_pair(x,y)]!=-1){
				Subtask_1::insert(x,y,t);
				Subtask_2::insert(x,y,t);
				mp[std::make_pair(x,y)]=-1;
			}
		}
		else{
			if(mp[std::make_pair(x,y)]!=-1){
				Subtask_1::insert(x,y,-1);
				Subtask_2::insert(x,y,-1);
				mp[std::make_pair(x,y)]=-1;
			}
			Subtask_1::insert(x,y,t);
			Subtask_2::insert(x,y,t);
			mp[std::make_pair(x,y)]=t;
		}
		int ans=(Subtask_1::query()+Subtask_2::query())%Mod;
		printf("%d\n",ans);
	}
	return 0;
}
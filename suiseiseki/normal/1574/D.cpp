#include <set>
#include <queue>
#include <cstdio>
#include <vector>
const int Maxn=10;
const int Maxm=200000;
int n,m;
std::vector<int> a[Maxn+5];
int len[Maxn+5];
std::priority_queue<std::pair<int,std::vector<int> > > q;
std::set<std::vector<int> > st,vis;
int main(){
	scanf("%d",&n);
	std::vector<int> lis;
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&len[i]);
		lis.push_back(len[i]);
		a[i].resize(len[i]+1);
		for(int j=1;j<=len[i];j++){
			scanf("%d",&a[i][j]);
		}
		sum+=a[i][len[i]];
	}
	q.push(std::make_pair(sum,lis));
	vis.insert(lis);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		std::vector<int> cur;
		cur.resize(n);
		for(int j=0;j<n;j++){
			scanf("%d",&cur[j]);
		}
		st.insert(cur);
	}
	while(!q.empty()){
		std::pair<int,std::vector<int> > u=q.top();
		if(st.count(u.second)==0){
			for(int i=0;i<n;i++){
				printf("%d ",u.second[i]);
			}
			puts("");
			break;
		}
		q.pop();
		for(int i=0;i<n;i++){
			if(u.second[i]>1){
				u.first-=a[i][u.second[i]];
				u.second[i]--;
				u.first+=a[i][u.second[i]];
				if(!vis.count(u.second)){
					q.push(u);
					vis.insert(u.second);
				}
				u.first-=a[i][u.second[i]];
				u.second[i]++;
				u.first+=a[i][u.second[i]];
			}
		}
	}
	return 0;
}
#include <set>
#include <vector>
#include <cstdio>
const int Maxn=300000;
int n,m;
std::set<int> g_1[Maxn+5],g_2[Maxn+5];
std::vector<int> ans;
void euler(int u){
	while(!g_2[u].empty()){
		int v=*g_2[u].begin();
		g_2[u].erase(v);
		g_2[v].erase(u);
		euler(v);
	}
	ans.push_back(u);
}
bool check(int u){
	for(int i=1;i<=n;i++){
		g_2[i]=g_1[i];
	}
	ans=std::vector<int>();
	euler(u);
	int sum_m=0;
	for(int i=1;i<=n;i++){
		sum_m+=(int)g_1[i].size();
	}
	for(int i=1;i<=n;i++){
		g_2[i]=g_1[i];
	}
	for(int i=1;i<(int)ans.size();i++){
		int x=ans[i-1],y=ans[i];
		if(g_2[x].count(y)==0){
			return 0;
		}
		g_2[x].erase(y);
		g_2[y].erase(x);
	}
	return (sum_m>>1)+1==(int)ans.size();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g_1[u].insert(v);
		g_1[v].insert(u);
	}
	for(int i=1;i<=n;i++){
		std::set<int> tmp=g_1[i],cur;
		std::set<int>::iterator it=tmp.begin();
		while(it!=tmp.end()){
			if(g_1[*it].size()&1){
				g_1[i].erase(*it);
				g_1[*it].erase(i);
				cur.insert(*it);
			}
			it++;
		}
		if(check(i)){
			ans.push_back(-1);
			it=cur.begin();
			while(it!=cur.end()){
				ans.push_back(*it);
				ans.push_back(i);
				it++;
			}
			printf("%d\n",(int)ans.size());
			for(int i=0;i<(int)ans.size();i++){
				printf("%d ",ans[i]);
			}
			puts("");
			return 0;
		}
		it=tmp.begin();
		while(it!=tmp.end()){
			if(g_1[i].count(*it)){
				g_1[i].erase(*it);
				g_1[*it].erase(i);
				cur.insert(*it);
			}
			else{
				g_1[i].insert(*it);
				g_1[*it].insert(i);
				cur.erase(*it);
			}
			if(check(i)){
				ans.push_back(-1);
				std::set<int>::iterator it_2;
				it_2=cur.begin();
				while(it_2!=cur.end()){
					ans.push_back(*it_2);
					ans.push_back(i);
					it_2++;
				}
				printf("%d\n",(int)ans.size());
				for(int i=0;i<(int)ans.size();i++){
					printf("%d ",ans[i]);
				}
				puts("");
				return 0;
			}
			if(g_1[i].count(*it)){
				g_1[i].erase(*it);
				g_1[*it].erase(i);
				cur.insert(*it);
			}
			else{
				g_1[i].insert(*it);
				g_1[*it].insert(i);
				cur.erase(*it);
			}
			it++;
		}
		it=cur.begin();
		while(it!=cur.end()){
			g_1[i].insert(*it);
			g_1[*it].insert(i);
			it++;
		}
	}
	puts("0");
	return 0;
}
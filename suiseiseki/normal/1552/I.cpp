#include<bits/stdc++.h>
using namespace std;
const int Maxn=100;
const int Mod=998244353;
typedef long long ll;
int n,m;
int fac[Maxn+5];
struct PQ_Tree{
	int n;
	struct node{
		std::vector<int> son;
		int type,op;
	}t[Maxn<<1|5];
	int tot,rt;
	bool OK;
	std::bitset<Maxn+5> vis;
	void init(int _n){
		tot=n=_n;rt=++tot;
		for(int i=1;i<=n;i++){
			t[rt].son.push_back(i);
		}
	}
	void dfs_1(int u){
		if(u<=n){
			t[u].op=vis[u]?2:1;
			return;
		}
		t[u].op=0;
		for(int i=0;i<(int)t[u].son.size();i++){
			int v=t[u].son[i];
			dfs_1(v);
			t[u].op|=t[v].op;
		}
	}
	void dfs_2(int u,int lim){
		if(!OK||t[u].op!=3){
			return;
		}
		std::vector<int> a[4];
		for(int i=0;i<(int)t[u].son.size();i++){
			int v=t[u].son[i];
			a[t[v].op].push_back(v);
		}
		if((lim>0)+a[3].size()>=3){
			OK=0;
		}
		if(lim==0&&(a[2].size()+a[3].size())<=1){
			if(!a[2].empty()){
				dfs_2(a[2][0],0);
			}
			if(!a[3].empty()){
				dfs_2(a[3][0],0);
			}
			return;
		}
		if(t[u].type){
			int now=0;
			std::vector<int> S;
			if(t[t[u].son[0]].op==2||t[t[u].son.back()].op==1){
				std::reverse(t[u].son.begin(),t[u].son.end());
			}
			for(int i=0;i<(int)t[u].son.size();i++){
				int v=t[u].son[i];
				if(t[v].op==1){
					S.push_back(v);
					now+=(now==1);
				}
				else if(t[v].op==2){
					S.push_back(v);
					now+=(now==0);
					if(now==2){
						OK=0;
					}
				}
				else{
					if(now==2){
						OK=0;
					}
					now++;
					dfs_2(v,3-now);
					S.insert(S.end(),t[v].son.begin(),t[v].son.end());
				}
			}
			if(lim>0&&now==2){
				OK=0;
			}
			if(lim==1){
				std::reverse(S.begin(),S.end());
			}
			t[u].son=S;
		}
		else{
			int z=-1;
			if(a[2].size()==1){
				z=a[2][0];
			}
			else if(a[2].size()>1){
				z=++tot;
				t[z].type=0;
				t[z].son=a[2];
			}
			std::vector<int> S;
			if(!a[3].empty()){
				dfs_2(a[3][0],2);
				S.insert(S.end(),t[a[3][0]].son.begin(),t[a[3][0]].son.end());
			}
			if(z!=-1){
				S.push_back(z);
			}
			if(a[3].size()>1){
				dfs_2(a[3][1],1);
				S.insert(S.end(),t[a[3][1]].son.begin(),t[a[3][1]].son.end());
			}
			if(a[1].empty()){
				if(lim==1){
					std::reverse(S.begin(),S.end());
				}
				t[u].type=1;
				t[u].son=S;
			}
			else{
				if(lim){
					t[u].son.clear();
					t[u].type=1;
					z=a[1][0];
					if(a[1].size()>1){
						z=++tot;
						t[z].type=0;
						t[z].son=a[1];
					}
					t[u].son.push_back(z);
					t[u].son.insert(t[u].son.end(),S.begin(),S.end());
					if(lim==1){
						std::reverse(t[u].son.begin(),t[u].son.end());
					}
				}
				else{
					z=S[0];
					if(S.size()>1){
						z=++tot;
						t[z].son=S;
						t[z].type=1;
					}
					t[u].son=a[1];
					t[u].son.push_back(z);
				}
			}
		}
	}
	bool insert(const std::bitset<Maxn+5> &B){
		vis=B;
		dfs_1(rt);
		OK=1;
		dfs_2(rt,0);
		return OK;
	}
	int calc(int u){
		if(u<=n){
			return 1;
		}
		int ans=t[u].type?2:fac[t[u].son.size()];
		for(int i=0;i<(int)t[u].son.size();i++){
			int v=t[u].son[i];
			ans=1ll*ans*calc(v)%Mod;
		}
		return ans;
	}
}T;
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	T.init(n);
	while(m--){
		static std::bitset<Maxn+5> B;
		B.reset();
		int k;
		scanf("%d",&k);
		while(k--){
			int a;
			scanf("%d",&a);
			B[a]=1;
		}
		if(!T.insert(B)){
			puts("0");
			return 0;
		}
	}
	printf("%d\n",T.calc(T.rt));
	return 0;
}
#include <queue>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 400000
int n,T,top=1,cnt,C[Maxn+5];
int In[Maxn+5],Out[Maxn+5],BIT[Maxn+5];
int num[Maxn+5],tree[Maxn+5][26];
int kmp[Maxn+5];
int rs[Maxn+5];
vector<int> ListString[Maxn+5],G[Maxn+5],g[Maxn+5];
queue<int> Q;
void Update(int idx,int data){
	while(idx<=top){
		BIT[idx]+=data;
		idx+=idx&-idx;
	}
}
int Query(int idx){
	int rs=0;
	while(idx>0){
		rs+=BIT[idx];
		idx-=idx&-idx;
	}
	return rs;
}
void Add(int id,string str){
	int tmp=1;
	for(int i=0;i<(int)str.size();i++){
		char c=str[i];
		if(tree[tmp][c-'a']==0){
			tree[tmp][c-'a']=++top;
		}
		tmp=tree[tmp][c-'a'];
	}
	num[id]=tmp;
}
void PreDFS(int u){
	In[u]=++cnt;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		PreDFS(v);
	}
	Out[u]=cnt;
}
void BuildAho(){
	Q.push(1);
	while(Q.size()>0){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<26;i++){
			if(tree[u][i]!=0){
				int v=tree[u][i];
				int tmp=kmp[u];
				while(tmp!=0&&tree[tmp][i]==0){
					tmp=kmp[tmp];
				}
				if(tmp==0){
					kmp[v]=1;
				}
				else{
					kmp[v]=tree[tmp][i];
				}
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=top;i++){
		g[kmp[i]].push_back(i);
	}
	PreDFS(1);
}
void DFS(int u,int tmp){
	Update(In[tmp],1);
	for(int i=0;i<(int)ListString[u].size();i++){
		int id=ListString[u][i];
		rs[id]=Query(Out[num[id]])-Query(In[num[id]]-1);
	}
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		char c=C[v];
		int newtmp=tmp;
		if(tree[newtmp][c-'a']!=0){
			newtmp=tree[newtmp][c-'a'];
		}
		else{
			newtmp=kmp[newtmp];
			while(newtmp!=0&&tree[newtmp][c-'a']==0){
				newtmp=kmp[newtmp];
			}
			if(newtmp==0){
				newtmp=1;
			}
			else{
				newtmp=tree[newtmp][c-'a'];
			}
		}
		DFS(v,newtmp);
	}
	Update(In[tmp],-1);
}
int main(){
	scanf("%d",&n);
	int type,j;
	char c;
	string s;
	for(int i=1;i<=n;i++){
		scanf("%d",&type);
		if(type==1){
			cin>>c;
			G[0].push_back(i);
		}
		else{
			cin>>j>>c;
			G[j].push_back(i);
		}
		C[i]=c;
	}
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&j);
		cin>>s;
		ListString[j].push_back(i);
		Add(i,s);
	}
	BuildAho();
	DFS(0,1);
	for(int i=1;i<=T;i++){
		printf("%d\n",rs[i]);
	}
	return 0;
}
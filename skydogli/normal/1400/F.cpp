#include<bits/stdc++.h>
using namespace std;
#define MN 10005
string s,a;
int n;
int cnt=1,add[MN][10],tag[MN];
void Ins(string s,bool op=1){
	int now=1;
	for(auto i:s){
		if(!add[now][i-'0'])add[now][i-'0']=++cnt;	
		now=add[now][i-'0'];
	}
	if(op)tag[now]=1;
}
void dfs(int x){
	if(!x){
		Ins(a);
		return;
	}
	for(int i=1;i<=9&&i<=x;++i){
		a.push_back(i+'0');
		int s=0,GG=0;
		for(int j=a.size()-1;j>=0;--j){
			s+=a[j]-'0';	
			if(n!=s&&n%s==0){GG=1;break;}
		}
		if(!GG)dfs(x-i);
		a.pop_back();
	}
}
int q[MN],fail[MN];
vector<int>edge[MN];
void getfail(){
	int l=1,r=0;
	for(int i=1;i<10;++i)
		if(add[1][i])q[++r]=add[1][i],fail[add[1][i]]=1;
		else add[1][i]=1;
	fail[1]=1;
	while(l<=r){
		int x=q[l++];
		edge[fail[x]].push_back(x);
		for(int i=1;i<10;++i){
			if(!add[x][i])add[x][i]=add[fail[x]][i];	
			else fail[add[x][i]]=add[fail[x]][i],q[++r]=add[x][i];
		}
	}
}
void DFS(int x){
	for(auto i:edge[x]){
		tag[i]|=tag[x];
		DFS(i);
	}
}
int f[1005][MN];
int main(){
	cin>>s>>n;
	Ins(s,0);
	dfs(n);
	getfail();
	DFS(1);
	s="$"+s;
	memset(f,0x3f,sizeof(f));
	f[0][1]=0;
	for(int i=1;i<s.size();++i){
		for(int j=1;j<=cnt;++j){
			if(f[i-1][j]<1e9){
				f[i][j]=min(f[i][j],f[i-1][j]+1);
				int to=add[j][s[i]-'0'];
				if(!tag[to]){
					f[i][to]=min(f[i][to],f[i-1][j]);
				}
//				else cerr<<"GG: "<<i<<" "<<j<<endl;
			}
		}
	}
	int ans=1e9;
	for(int j=1;j<=cnt;++j)
		if(!tag[j])ans=min(ans,f[s.size()-1][j]);
	printf("%d\n",ans);
	return 0;
}
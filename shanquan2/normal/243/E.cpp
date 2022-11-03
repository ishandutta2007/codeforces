#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int n,cnt,rt,siz[1500],s[1500],tp[1500];
char a[500][505],ch[505];
bool tg[1505];
vector<int> e[1500];
void fail(){
	printf("NO\n");exit(0);
}
void dfs(int x){
	if(x<n)return (void)(siz[x]=1,s[x]=ch[x]=='1');
	siz[x]=s[x]=0;
	for(int i=0;i<e[x].size();i++)dfs(e[x][i]),siz[x]+=siz[e[x][i]],s[x]+=s[e[x][i]];
}
void down(int x){
	if(tg[x]){
		reverse(e[x].begin(),e[x].end());
		for(int i=0;i<e[x].size();i++)tg[e[x][i]]^=1;
		tg[x]=0;
	}
}
void rev(int x){
	if(tp[x]!=2)fail();
	tp[x]=1;tg[x]=1;
	down(x);
}
int solve(int x,int dir){ // 0: no limit  1: left  2: right
	if(x<n)return x;
	down(x);
	if(!tp[x]){
		vector<int> a,b,c;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			if(siz[y]==s[y])a.push_back(y);else if(s[y]==0)b.push_back(y);else c.push_back(y);
		}
		if(c.size()>2 || c.size()==2 && dir)fail();
		if(!a.size() && c.size()==1 && !dir){
			for(int i=0;i<e[x].size();i++)if(e[x][i]==c[0]){
				e[x][i]=solve(c[0],0);
				return x;
			}
		}
		int A;
		if(!a.size())A=-1;
		else if(a.size()==1)A=a[0];
		else{
			A=cnt++;
			tp[A]=0;
			e[A]=a;
		}
		int X;
		vector<int> t;
		if(dir!=1 && c.size())t.push_back(solve(c[0],2));
		if(~A)t.push_back(A);
		if(dir!=2 && c.size()>(dir?0:1))t.push_back(solve(c[c.size()-1],1));
		if(t.size()==1)X=t[0];
		else{
			X=cnt++;
			tp[X]=2;
			e[X]=t;
		}
		int z;
		if(!b.size())z=X;else{
			z=cnt++;
			if(dir){
				int y;
				if(b.size()==1)y=b[0];else{
					y=cnt++;
					tp[y]=0;
					e[y]=b;
				}
				tp[z]=1;
				if(dir==1)e[z].push_back(X),e[z].push_back(y);
				else e[z].push_back(y),e[z].push_back(X);
			}else{
				tp[z]=0;e[z]=b;e[z].push_back(X);
			}
		}
		return z;
	}else{
		int l=e[x][0],r=e[x][e[x].size()-1];
		if(dir==1 && siz[l]!=s[l] && (s[l]==0 || s[r]==siz[r]))rev(x);
		if(dir==2 && siz[r]!=s[r] && (s[r]==0 || s[l]==siz[l]))rev(x);
		int lst=-1,c=0,ac=0;
		bool f=0;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i],t;
			if(siz[y]==s[y])t=2;else if(s[y]==0)t=0;else t=1;
			if(~lst){
				if(dir==1 && t>lst || dir==2 && t<lst)fail();
				if(t==0 && lst)f=1;
				if(f && t && !lst)fail();
			}
			lst=t;
			if(t==1)c++;
			if(t)ac++;
		}f=1;
		if(dir && c>1 || !dir && c>2)fail();
		for(int i=0;i<e[x].size();i++){
			int &y=e[x][i],t=s[y];
			if(t && t<siz[y])
				if(dir || ac==1)y=solve(y,dir);
				else if(f)y=solve(y,2);else y=solve(y,1);
			if(t)f=0;
		}
		return x;
	}
}
int ans[505],top;
void dfsans(int x){
	if(x<n)return void(ans[top++]=x);
	down(x);
	for(int i=0;i<e[x].size();i++)dfsans(e[x][i]);
}
int main(){
	scanf("%d",&n);cnt=n+1;
	for(int i=0;i<n;i++)e[n].push_back(i);
	tp[n]=0;rt=n;
	for(int i=0;i<n;i++){
		if(i==9){
			i=9;
		}
		scanf("%s",a[i]);
		memcpy(ch,a[i],sizeof(ch));
		dfs(rt);
		if(!s[rt])continue;
		rt=solve(rt,0);
	}
	dfsans(rt);
	printf("YES\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)printf("%c",a[i][ans[j]]);
		printf("\n");
	}
	return 0;
}
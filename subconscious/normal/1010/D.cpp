#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5;
int n;
char s[N][10];
int l[N],r[N],is[N];
void dfs(int cur){
	if(s[cur][1]=='I')return;
	if(s[cur][1]=='N'){
		dfs(l[cur]);
		is[cur]=1^is[l[cur]];
		//printf("%d %d\n",cur,is[cur]);
		return;
	}
	dfs(l[cur]);dfs(r[cur]);
	if(s[cur][1]=='A'){
		is[cur]=is[l[cur]]&is[r[cur]];
		//printf("%d %d\n",cur,is[cur]);
		return;
	}
	if(s[cur][1]=='O'){
		is[cur]=is[l[cur]]|is[r[cur]];
		//printf("%d %d\n",cur,is[cur]);
		return;
	}
	if(s[cur][1]=='X'){
		is[cur]=is[l[cur]]^is[r[cur]];
		//printf("%d %d\n",cur,is[cur]);
		return;
	}
}
int cha[N];
void sol(int cur){
	if(s[cur][1]=='I')return;
	if(s[cur][1]=='N'){
		//printf("%d\n",cur);
		//printf("%d %d %d\n",is[cur],is[l[cur]],is[r[cur]]);
		cha[l[cur]]=cha[cur];
		sol(l[cur]);
		return;
	}
	if(s[cur][1]=='A'){
		//printf("%d\n",cur);
		//printf("%d %d %d\n",is[cur],is[l[cur]],is[r[cur]]);
		if(is[cur]!=((is[l[cur]]^1)&is[r[cur]]))cha[l[cur]]=1;else cha[l[cur]]=0;
		if(is[cur]!=((is[l[cur]])&(is[r[cur]]^1)))cha[r[cur]]=1;else cha[r[cur]]=0;
		if(cha[cur]==0)cha[l[cur]]=cha[r[cur]]=0;
		sol(l[cur]);
		sol(r[cur]);
		return;
	}
	if(s[cur][1]=='O'){
		//printf("%d\n",cur);
		//printf("%d %d %d\n",is[cur],is[l[cur]],is[r[cur]]);
		if(is[cur]!=((is[l[cur]]^1)|is[r[cur]]))cha[l[cur]]=1;else cha[l[cur]]=0;
		if(is[cur]!=((is[l[cur]])|(is[r[cur]]^1)))cha[r[cur]]=1;else cha[r[cur]]=0;
		if(cha[cur]==0)cha[l[cur]]=cha[r[cur]]=0;
		sol(l[cur]);
		sol(r[cur]);
		return;
	}
	if(s[cur][1]=='X'){
		//printf("%d\n",cur);
		//printf("%d %d %d\n",is[cur],is[l[cur]],is[r[cur]]);
		if(is[cur]!=((is[l[cur]]^1)^is[r[cur]]))cha[l[cur]]=1;else cha[l[cur]]=0;
		if(is[cur]!=((is[l[cur]])^(is[r[cur]]^1)))cha[r[cur]]=1;else cha[r[cur]]=0;
		if(cha[cur]==0)cha[l[cur]]=cha[r[cur]]=0;
		sol(l[cur]);
		sol(r[cur]);
		return;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s[i]+1);
		if(s[i][1]=='I')scanf("%d",is+i);
		else if(s[i][1]=='N')scanf("%d",l+i);
		else scanf("%d%d",l+i,r+i);
	}
	dfs(1);//printf("%d\n",is[1]);
	cha[1]=1;sol(1);
	//rep(i,n)printf("%d ",cha[i]);
	rep(i,n)if(s[i][1]=='I')printf("%d",cha[i]?(1^is[1]):is[1]);
	puts("");
	//system("pause");
	return 0;
}
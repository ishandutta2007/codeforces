#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
LL ans;
map<LL,int>vis;
char ch[1505][35];
int id(char a){
	if(a=='S')return 1;
	if(a=='T')return 2;
	if(a=='E')return 3;
}
int gt(char a,char b){
	if(a!='S'&&b!='S')return 1;
	if(a!='T'&&b!='T')return 2;
	if(a!='E'&&b!='E')return 3;
}
int main(){
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;++i){
		scanf("%s",ch[i]+1);
		for(int j=1;j<i;++j){
			LL want=0,it=0;
			for(int k=1;k<=m;++k){
				want*=4ll;
				it*=4ll;
				it+=(LL)id(ch[j][k]);
				if(ch[i][k]!=ch[j][k]){want+=gt(ch[i][k],ch[j][k]);}
				else want+=id(ch[i][k]);
			}
		ans+=(LL)vis[want]-(it==want);
		}
		LL now=0;
			for(int k=1;k<=m;++k){
				now*=4ll;
				now+=(LL)id(ch[i][k]);
			}
		vis[now]++;
	}
	printf("%lld\n",ans/2);
	return 0;
}
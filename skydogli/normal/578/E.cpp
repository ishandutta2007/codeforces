#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define piv pair<int,vc >
int n,op[MN],lst[MN];
vc A,B;
char ch[MN];
vector<int>pos[2][2];
void out(int x){
	if(!x)return;
	out(lst[x]);
	printf("%lld ",x);
}
void out(int x,int y){
	for(auto i:pos[x][y]){
		out(i);
	}
}
signed main(){
	scanf("%s",ch+1);n=strlen(ch+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		op[i]=(ch[i]=='R');
		bool ok=0;
		for(int j=0;j<2;++j)
			if(pos[j][!op[i]].size()){
				lst[i]=pos[j][!op[i]].back();
				pos[j][!op[i]].pop_back();
				pos[j][op[i]].pb(i);
				ok=1;
				break;
			}
		if(!ok){pos[op[i]][op[i]].pb(i);ans++;}
	}
	while(pos[0][0].size()&&pos[1][1].size()){
		int aa=pos[0][0].back(),bb=pos[1][1].back();
		pos[0][0].pop_back();pos[1][1].pop_back();
		if(aa<bb){
			pos[1][0].pb(lst[bb]);
			lst[bb]=aa;
			pos[0][1].pb(bb);
		}
		else{
			pos[0][1].pb(lst[aa]);
			lst[aa]=bb;
			pos[1][0].pb(aa);
		}
	}
	cout<<ans-1<<endl;
	if(pos[0][1].size()&&pos[1][0].size()&&!pos[1][1].size()&&!pos[0][0].size()){
		int aa=pos[0][1].back(),bb=pos[1][0].back();
		pos[0][1].pop_back();pos[1][0].pop_back();
		if(aa<bb){
			pos[1][1].pb(lst[bb]);
			lst[bb]=aa;
			pos[0][0].pb(bb);
		}
		else{
			pos[0][0].pb(lst[aa]);
			lst[aa]=bb;
			pos[1][1].pb(aa);
		}
	}
	if(pos[1][1].size()){
		out(0,0);out(1,0);out(1,1);out(0,1);
	}
	else{
		out(1,1);out(0,1);out(0,0);out(1,0);
	}
	return 0;
}
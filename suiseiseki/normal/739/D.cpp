#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
typedef long long ll;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}
const int Maxn=300;
int n,m;
int dis[Maxn+5],id[Maxn+5],mxd[Maxn+5],cnt[Maxn+5];
int mxlen;
int x[Maxn+5],y[Maxn+5],vl[Maxn+5],vr[Maxn+5],match[Maxn+5];
int e[Maxn+5][Maxn+5],flg[Maxn+5];
void chkmax(int &x,int y){
	if(y>x){
		x=y;
	}
}
int find(int x){
	for(int i=1;i<=m;i++){
		if(!e[x][i]||vr[i]||flg[i]){
			continue;
		}
		flg[i]=1;
		if(!match[i]||find(match[i])){
			match[i]=x;
			return 1;
		}
	}
	return 0;
}
bool check(int s){
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	memset(vl,0,sizeof vl);
	memset(vr,0,sizeof vr);
	memset(match,0,sizeof match);
	memset(e,0,sizeof e);
	m=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!(~mxd[i])&&s!=i){
			continue;
		}
		int c=cnt[i],l=max(mxd[i],(s==i)*mxlen);
		for(int j=1;j<=c;j++){
			m++;
			if(m>n){
				return 0;
			}
			else{
				x[m]=i;
				y[m]=0;
			}
		}
		for(int j=1;j<=l;j++){
			m++;
			if(m>n){
				return 0;
			}
			else{
				x[m]=i;
				y[m]=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((id[i]==x[j]||!(~id[i]))&&(dis[i]==y[j]||!(~dis[i]))){
				e[i][j]=1;
			}
			if(id[i]==x[j]&&dis[i]==y[j]&&!vl[i]&&!vr[j]){
				vl[i]=vr[j]=1;
				match[j]=i;
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vl[i]){
			memset(flg,0,sizeof flg);
			ans+=find(i);
		}
	}
	return ans==m;
}
int fa[Maxn+5];
vector<int> Set[Maxn+5];
void generate(int s){
	for(int i=1;i<=m;i++){
		id[match[i]]=x[i];
		dis[match[i]]=y[i];
	}
	for(int i=1;i<=n;i++){
		if((~id[i])&&(~dis[i])){
			continue;
		}
		if(!(~id[i])&&dis[i]<=0){
			id[i]=1;
			dis[i]=0;
		}
		else if(!(~id[i])){
			id[i]=s;
		}
		else if(!(~dis[i])){
			dis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!dis[i]){
			Set[id[i]].push_back(i);
			if((int)Set[id[i]].size()==id[i]){
				for(int j=0;j<id[i];j++){
					fa[Set[id[i]][j]]=Set[id[i]][(j+1)%id[i]];
				}
				Set[id[i]].clear();
			}
			continue;
		}
		for(int j=1;j<=n;j++){
			if(id[i]==id[j]&&dis[i]==dis[j]+1){
				fa[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",fa[i]);
	}
	puts("");
}
int main(){
	char s[10];
	n=read();
	memset(mxd,-1,sizeof mxd);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='?'){
			dis[i]=-1;
		}
		else{
			dis[i]=atoi(s);
		}
		scanf("%s",s);
		if(s[0]=='?'){
			id[i]=-1;
		}
		else{
			id[i]=atoi(s);
		}
		if(~id[i]){
			chkmax(mxd[id[i]],max(dis[i],0));
			if(!dis[i]){
				cnt[id[i]]++;
			}
		}
		else{
			chkmax(mxlen,dis[i]);
		}
	}
	for(int i=1;i<=n;i++){
		cnt[i]=max(i,(int)ceil((double)cnt[i]/i)*i);
	}
	for(int i=1;i<=n;i++){
		if(!check(i)){
			continue;
		}
		generate(i);
		return 0;
	}
	puts("-1");
	return 0;
}
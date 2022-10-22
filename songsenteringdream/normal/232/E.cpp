#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int o=8e5;
int n,m,q,X1[o],Y1[o],X2[o],Y2[o];bool ans[o];char a[510][510];bitset<510> b[510][510],c[510][510];vector<int> vec[2010];
inline void ins(int id,int ql,int qr,int val,int l=1,int r=n){
	int md=l+r>>1;
	if(ql<=md&&md<=qr){vec[id].push_back(val);return;}
	if(qr<md) ins(id<<1,ql,qr,val,l,md-1);
	else ins((id<<1)|1,ql,qr,val,md+1,r);
}
inline void upd1(int z){for(int i=m;--i;) if(a[z][i]^'#') b[z][i]|=b[z][i+1];}
inline void upd2(int z){for(int i=1;i<m;++i) if(a[z][i+1]^'#') c[z][i+1]|=c[z][i];}
void dfs(int id,int l,int r){
	int md=l+r>>1;
	if(!vec[id].empty()){
		for(int i=1;i<=m;++i) b[md][i].reset(),c[md][i].reset();
		for(int i=1;i<=m;++i) if(a[md][i]^'#') b[md][i].set(i),c[md][i].set(i);
		upd1(md);upd2(md);
		for(int i=md-1;i>=l;upd1(i--)) for(int j=1;j<=m;++j)
			if(a[i][j]^'#') b[i][j]=b[i+1][j];else b[i][j].reset();
		for(int i=md+1;i<=r;upd2(i++)) for(int j=1;j<=m;++j)
			if(a[i][j]^'#') c[i][j]=c[i-1][j];else c[i][j].reset();
		for(int i=vec[id].size(),j;i--;) j=vec[id][i],ans[j]=(b[X1[j]][Y1[j]]&c[X2[j]][Y2[j]]).count();
	}
	if(l<md) dfs(id<<1,l,md-1);
	if(md<r) dfs((id<<1)|1,md+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]),ins(1,X1[i],X2[i],i);
	dfs(1,1,n);
	for(int i=1;i<=q;++i) printf(ans[i]?"Yes\n":"No\n");
	return 0;
}
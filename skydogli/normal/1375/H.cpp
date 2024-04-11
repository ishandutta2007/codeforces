#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define MN (1<<16|5)
#define mn (1<<12|5)
int n,q,a[mn],loc[mn],cnt;
int l[MN],r[MN],ans[MN];
int ls[mn<<2],rs[mn<<2];;
vector<vector<int> >id[mn<<2];
vector<pii >b[mn<<4],fk;
void Merge(int x,int y){
	fk.push_back(mp(x,y));
	cnt++;
}
int tot,root[mn];
int qry(int x,int l,int r){
	int L=lower_bound(b[x].begin(),b[x].end(),mp(l,0))-b[x].begin();
	int R=lower_bound(b[x].begin(),b[x].end(),mp(r+1,0))-b[x].begin()-1;
	if(L>R)return 0;
//	cerr<<"? "<<L<<" "<<R<<endl;
	return id[x][L][R];
}
void build(int &x,int l,int r,int st){
	x=++tot;
	assert(!l);
	if(l==r){
		b[x].push_back(mp(loc[st+l],st+l));
		id[x].resize(1);id[x][0].resize(1);
		id[x][0][0]=loc[st+l];
		return;
	}	
	int mid=(l+r)>>1;
	build(ls[x],l,mid,st);
	build(rs[x],0,r-mid-1,st+mid+1-l);
	b[x].resize(r+1);
	id[x].resize(r+1);
	for(auto &i:id[x])i.resize(r+1);
	merge(b[ls[x]].begin(),b[ls[x]].end(),b[rs[x]].begin(),b[rs[x]].end(),b[x].begin());
	for(int i=l;i<=r;++i)
		for(int j=i;j<=r;++j){
			int X=qry(ls[x],b[x][i].x,b[x][j].x),Y=qry(rs[x],b[x][i].x,b[x][j].x);	
			if(X&&Y) {Merge(X,Y);id[x][i][j]=cnt;}
			else if(X) id[x][i][j]=X;
			else if(Y) id[x][i][j]=Y;
//			cerr<<st+i<<" "<<st+j<<": "<<id[x][i][j]<<endl;
		}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		loc[a[i]]=i;
	}
	cnt=n;
	int B=min(n,(int)sqrt(q));
//	B=3;
	int T=(n-1)/B+1;
//	cerr<<"? "<<B<<" "<<T<<endl;
	for(int i=1;i<=T;++i){
		int l=(i-1)*B+1,r=min(n,i*B);
		build(root[i],0,r-l,l);	
		/*
		for(int j=0;j<b[i].size();++j){
			id[i][j][j]=b[i][j].x;
			for(int k=j+1;k<b[i].size();++k){
				id[i][j][k]=++cnt;
				ans.pb(mp(id[i][j][k-1],k));
			}
		}
		*/
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&l[i],&r[i]);
		int lst=0;
		for(int j=1;j<=T;++j){
			int ID=qry(root[j],l[i],r[i]);
			if(lst&&ID){Merge(lst,ID);lst=cnt;}
			else if(ID)lst=ID;
		}
		ans[i]=lst;
	}
	printf("%d\n",n+(int)fk.size());
	for(auto i:fk)printf("%d %d\n",i.x,i.y);
	for(int i=1;i<=q;++i)printf("%d ",ans[i]);
	return 0;
}
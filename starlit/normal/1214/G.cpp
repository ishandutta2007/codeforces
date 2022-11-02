#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int,int> pi;
typedef unsigned int ui;
const ui MAX=-1;
const int N=2003;
int n,m,q,x,l,r,pre,nxt,c[N],cnt[1<<16],a1,a2;
ui b[N][N/32+1],tp;
set<pi>sa,sb;
set<pi>::iterator it;
inline void cov(ui&p,int x,int y){
	if(y>=x+1<<5)p^=MAX;
	else if(y>x<<5)p^=(1u<<y-(x<<5))-1;
}
inline void get(){
	it=sa.find(mp(c[x],x));
	if(it!=sa.begin())
	--it,pre=it->second,it++;
	else pre=0;
	if(++it!=sa.end())
	nxt=it->second;
	else nxt=0;
}
inline void chk(int x,int y){
	if(x&&y){
		bool fl=1;
		for(int i=0;i<<5<m&&fl;i++)
		if((b[x][i]&b[y][i])!=b[x][i])fl=0;
		//cerr<<"chk "<<x<<','<<y<<':'<<fl<<endl;
		if(!fl)sb.insert(mp(x,y));
	}
}
inline int cal(int l,int r){
	for(int i=0;i<<5<m;i++)
	if((tp=b[l][i]&b[r][i])!=b[r][i])
	for(int j=0;j<32;j++)
	if((b[r][i]>>j&1)&&!(b[l][i]>>j&1))
	return 1+(i<<5|j);
}
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	sa.insert(mp(0,i));
	for(int i=1;i<65536;i++)
	cnt[i]=cnt[i>>1]+(i&1);
	for(;q--;){
		scanf("%d%d%d",&x,&l,&r);
		get();l--;
		sb.erase(mp(pre,x)),
		sb.erase(mp(x,nxt));
		chk(pre,nxt);
		sa.erase(--it);
		c[x]=0;
		for(int i=0;i<<5<m;i++)
		cov(b[x][i],i,r),cov(b[x][i],i,l),
		c[x]+=cnt[b[x][i]>>16]+cnt[b[x][i]&(1<<16)-1];
		sa.insert(mp(c[x],x));
		get();
		sb.erase(mp(pre,nxt));
		chk(pre,x),chk(x,nxt);
		if(sb.size()){
			l=sb.begin()->first;
			r=sb.begin()->second;
			a1=cal(l,r),a2=cal(r,l);
			if(l>r)swap(l,r);
			if(a1>a2)swap(a1,a2);
			printf("%d %d %d %d\n",l,a1,r,a2);

		}else puts("-1");
		/*
		for(int i=1;i<=n;i++){
			cerr<<c[i]<<endl;
		}
		for(auto i:sb)cerr<<(i.first)<<','<<(i.second)<<endl;
		cerr<<endl;*/
	}
}
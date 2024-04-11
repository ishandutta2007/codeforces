#include<cstdio>
#include<utility>
#include<set>
#include<map>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1e5+10;
int n,m1,m2,fa1[o],fa2[o],xx[o],yy[o],cnt;set<pair<int,int> > rows;set<int> row[o],col[o];map<int,int> mp[o];
int fr1(int x){return fa1[x]==x?x:fa1[x]=fr1(fa1[x]);}
int fr2(int x){return fa2[x]==x?x:fa2[x]=fr2(fa2[x]);}
inline void mergerow(int x,int y){
	for(set<int>::iterator iter=row[y].begin();iter!=row[y].end();++iter)
		mp[x][*iter]=mp[y][*iter],row[x].insert(*iter),col[*iter].erase(y),col[*iter].insert(x);
}
inline void mergecol(int x,int y){
	for(set<int>::iterator iter=col[y].begin();iter!=col[y].end();++iter)
		mp[*iter][x]=mp[*iter][y],col[x].insert(*iter),row[*iter].erase(y),row[*iter].insert(x);
}
int main(){
	read(n);read(m1);read(m2);
	for(int i=1;i<=n;++i) fa1[i]=fa2[i]=i;
	for(int i=1,j,k;i<=m1;++i) read(j),read(k),fa1[fr1(j)]=fr1(k);
	for(int i=1,j,k;i<=m2;++i) read(j),read(k),fa2[fr2(j)]=fr2(k);
	if(m1<m2) for(int i=1,j;i<=n;++i) j=fa1[i],fa1[i]=fa2[i],fa2[i]=j;
	for(int i=1,j,k;i<=n;++i) mp[j=fr1(i)][k=fr2(i)]=i,row[j].insert(k),col[k].insert(j);
	for(int i=1;i<=n;++i) if(fr1(i)==i) rows.insert(make_pair(-row[i].size(),i));
	for(int i,j,c1,c2,t;rows.size()>1;){
		i=(*rows.begin()).second;rows.erase(rows.begin());
		j=(*rows.begin()).second;rows.erase(rows.begin());
		set<int>::iterator iter=row[i].begin();c1=*iter;c2=*row[j].begin();
		if(c1==c2) c1=*++iter;
		xx[++cnt]=mp[i][c1];yy[cnt]=mp[j][c2];
		if(col[c1].size()<col[c2].size()) t=c1,c1=c2,c2=t;
		mergerow(i,j);mergecol(c1,c2);
		rows.insert(make_pair(-row[i].size(),i));
	}
	write(cnt);for(int i=1;i<=cnt;putchar('\n'),write(xx[i]),putchar(' '),write(yy[i++]));
	return 0;
}
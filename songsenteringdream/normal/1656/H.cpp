#include<cstdio>
#include<queue>
using namespace std;
const int o=1010;
__int128 gcd(__int128 a,__int128 b){return b?gcd(b,a%b):a;}
inline void read(__int128&a){char c=getchar();for(;c>'9'||c<'0';c=getchar());for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;}
void write(__int128 a){if(a>9) write(a/10);putchar(a%10+48);}
int T,n,m,sa,sb;__int128 a[o],b[o],sta[o][o*4],stb[o][o*4];bool da[o],db[o],va[o],vb[o];queue<int> qa,qb;
void builda(int id,int l,int r,int i){
	if(l==r){sta[i][id]=a[i]/gcd(a[i],b[l]);return;}
	int md=l+r>>1;
	builda(id<<1,l,md,i);builda((id<<1)|1,md+1,r,i);
	sta[i][id]=gcd(sta[i][id<<1],sta[i][(id<<1)|1]);
}
void buildb(int id,int l,int r,int i){
	if(l==r){stb[i][id]=b[i]/gcd(b[i],a[l]);return;}
	int md=l+r>>1;
	buildb(id<<1,l,md,i);buildb((id<<1)|1,md+1,r,i);
	stb[i][id]=gcd(stb[i][id<<1],stb[i][(id<<1)|1]);
}
void modifya(int i,int id,int pos,int l=1,int r=m){
	if(l==r){sta[i][id]=0;return;}
	int md=l+r>>1;
	if(pos<=md) modifya(i,id<<1,pos,l,md);
	else modifya(i,(id<<1)|1,pos,md+1,r);
	sta[i][id]=gcd(sta[i][id<<1],sta[i][(id<<1)|1]);
}
void modifyb(int i,int id,int pos,int l=1,int r=n){
	if(l==r){stb[i][id]=0;return;}
	int md=l+r>>1;
	if(pos<=md) modifyb(i,id<<1,pos,l,md);
	else modifyb(i,(id<<1)|1,pos,md+1,r);
	stb[i][id]=gcd(stb[i][id<<1],stb[i][(id<<1)|1]);
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);sa=n;sb=m;
		for(;!qa.empty();qa.pop());
		for(;!qb.empty();qb.pop());
		for(int i=1;i<=n;read(a[i++])) da[i]=va[i]=0;
		for(int i=1;i<=m;read(b[i++])) db[i]=vb[i]=0;
		for(int i=1;i<=n;++i){
			builda(1,1,m,i);
			if(sta[i][1]>1) qa.push(i),va[i]=1;
		}
		for(int i=1;i<=m;++i){
			buildb(1,1,n,i);
			if(stb[i][1]>1) qb.push(i),vb[i]=1;
		}
		for(;!qa.empty()||!qb.empty();){
			if(!sa||!sb) break;
			for(int t;!qa.empty();qa.pop()){
				da[t=qa.front()]=1;--sa;
				for(int i=1;i<=m;++i) if(!db[i]){
					modifyb(i,1,t);
					if(stb[i][1]>1&&!vb[i]) qb.push(i),vb[i]=1;
				}
			}
			for(int t;!qb.empty();qb.pop()){
				db[t=qb.front()]=1;--sb;
				for(int i=1;i<=n;++i) if(!da[i]){
					modifya(i,1,t);
					if(sta[i][1]>1&&!va[i]) qa.push(i),va[i]=1;
				}
			}
		}
		if(sa&&sb){
			printf("YES\n%d %d\n",sa,sb);
			for(int i=1;i<=n;++i) if(!da[i]) write(a[i]),putchar(' ');
			putchar('\n');
			for(int i=1;i<=m;++i) if(!db[i]) write(b[i]),putchar(' ');
			putchar('\n');
		}
		else printf("NO\n");
	}
	return 0;
}
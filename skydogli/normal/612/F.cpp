#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 4005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define get hhak
int T,n,m;
int a[MN],v[MN],N;
int lst[MN],nxt[MN],ljump[MN],rjump[MN];
vector<int>pos[MN];
int f[MN][MN][2];
pii fk[MN][2];
bool lead[MN][MN][2];
int dis(int i,int j){
//	cerr<<"dis "<<i<<" "<<j<<": ";
	i=(i-1)%n+1;j=(j-1)%n+1;
	if(i<j)swap(i,j);
//	cerr<<min(i-j,j+n-i)<<endl;
	return min(i-j,j+n-i);
}
void chk(int to,int j,int k,int op){
	if(!to)return;
	if(f[to][to][op]>f[j][k][op]+(op?dis(k,to):dis(j,to))){
		f[to][to][op]=f[j][k][op]+(op?dis(k,to):dis(j,to));
		fk[to][op]=mp(j,k);
//		if(a[to]==3)cerr<<"FK "<<to<<" "<<op<<": "<<j<<" "<<k<<endl;
	}
}
void printdis(int pos,int to){
	pos=(pos-1)%n+1;to=(to-1)%n+1;
	if(pos<to){
		int a=to-pos,b=pos+n-to;
//		cerr<<pos<<" "<<to<<": "<<a<<" "<<b<<endl;
		assert(a>=0&&b>=0);
		if(a<=b){
			printf("+%d\n",a);
		}
		else printf("-%d\n",b);
	}
	else{
		int a=to+n-pos,b=pos-to;
		assert(a>=0&&b>=0);
//		cerr<<"BB "<<pos<<" "<<to<<": "<<a<<" "<<b<<endl;
		if(a<=b){
			printf("+%d\n",a);
		}
		else printf("-%d\n",b);
	}
}
void outdis(int j,int k,int op,int to){
	int pos=op?k:j;
//	cerr<<"? "<<pos<<" "<<to<<endl;
	printdis(pos,to);
}
int s;
void get(int j,int k,int op){
	assert(j);
	if(j==k){
		if(a[j]==1){
			
			printdis(s,(j-1)%n+1);
			return;
		}
	//	cerr<<"? "<<j<<" "<<fk[j][op].x<<" "<<fk[j][op].y<<endl;
		get(fk[j][op].x,fk[j][op].y,op);
//		cerr<<"GET "<<j<<" "<<k<<" "<<op<<" "<<fk[j][op].x<<" "<<fk[j][op].y<<endl;
		outdis(fk[j][op].x,fk[j][op].y,op,j);
		return;
	}
	if(op) {
		get(j,lst[k],lead[j][k][op]);
//		cerr<<"get "<<j<<" "<<k<<" "<<op<<endl;
		outdis(j,lst[k],lead[j][k][op],k);
	}
	else{
		get(nxt[j],k,lead[j][k][op]);
//		cerr<<"get "<<j<<" "<<k<<" "<<op<<endl;
		outdis(nxt[j],k,lead[j][k][op],j);
	}
}
map<int,int>vis;
signed main(){
	n=read();s=read();
	for(int i=1;i<=n;++i){
		v[++N]=a[i]=a[n+i]=read();
	}
	sort(v+1,v+1+N);N=unique(v+1,v+1+N)-v-1;
	for(int i=1;i<=(n<<1);++i){
		a[i]=lower_bound(v+1,v+1+N,a[i])-v;
//		cerr<<"a "<<i<<": "<<a[i]<<endl;
	}
	vis.clear();
	for(int i=1;i<=(n<<1);++i){
		lst[i]=vis[a[i]];
		ljump[i]=vis[a[i]+1];
		vis[a[i]]=i;
		pos[a[i]].push_back(i);
	}
	vis.clear();
	for(int i=(n<<1);i;--i){
		nxt[i]=vis[a[i]];
		rjump[i]=vis[a[i]+1];
		vis[a[i]]=i;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=(n<<1);++i){
		if(a[i]==1) {
			f[i][i][0]=dis(i,s);
		}
	}
	int ans=1e9,J,K,O;
	for(int i=1;i<=N;++i){	
//		cerr<<"======"<<endl;
		for(int len=1;len<=n;++len){
			for(auto j:pos[i]){
				int k=j+len-1;
				if(a[k]==i){
					for(int op=0;op<2;++op){
//						if(f[j][k][op]<1e9)cerr<<j<<" "<<k<<" "<<op<<": "<<f[j][k][op]<<" "<<lead[j][k][op]<<endl;
						if(lst[j]){
							int to=lst[j];
							if(f[to][k][0]>f[j][k][op]+(op?dis(k,to):dis(j,to))){
								f[to][k][0]=f[j][k][op]+(op?dis(k,to):dis(j,to));
								lead[to][k][0]=op;
							}
						}
						if(nxt[k]){
							int to=nxt[k];
							if(f[j][to][1]>f[j][k][op]+(op?dis(k,to):dis(j,to))){
								f[j][to][1]=f[j][k][op]+(op?dis(k,to):dis(j,to));
								lead[j][to][1]=op;	
							}
						}
						if((k-(lst[j]?lst[j]:-1e9)+1>n&&(nxt[k]?nxt[k]:1e9)-j+1>n)){
							if(i==N){
								if(ans>f[j][k][op]){
									ans=f[j][k][op];
									J=j;K=k;O=op;
								}
							}
							chk(ljump[j],j,k,op);
							chk(rjump[j],j,k,op);
							chk(ljump[k],j,k,op);
							chk(rjump[k],j,k,op);
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	get(J,K,O);
	return 0;
}
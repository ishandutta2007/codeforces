#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m,k;
bool flag;
int f[2][1<<8];
struct node{
	int l,r;
	inline bool operator <(const node &x)const {
		return r==x.r?l<x.l:r<x.r;
	}
}a[100010];
vector<PII>d;
int pos[10];
int main(){
	n=read(),m=read(),k=read();
	int cnt=0;
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read();
		d.pb(mp(a[i].l,i)),d.pb(mp(a[i].r+1,-i));
	}
//	if(i==1){
//		printf("%d\n",a[1].r-a[1].l+1);return 0;
//	}
	sort(d.begin(),d.end());
	memset(f,-0x3f,sizeof(f));f[flag][0]=0; 
	for(int i=0;i<d.size();++i){
		flag^=1;
		int id=d[i].se;
//		printf("i:%d,id:%d\n",i,id);
		int num=-1;
		int len=i==d.size()-1?0:d[i+1].fi-d[i].fi;
		if(id>0){
			for(int j=0;j<k;++j){
				if(!pos[j]){
					pos[num=j]=id;break ;
				}
			}
			for(int j=0;j<(1<<k);++j){
				if((j>>num)&1){
					f[flag][j]=f[flag^1][j^(1<<num)]+len*__builtin_parity(j);
				}
				else f[flag][j]=f[flag^1][j]+len*__builtin_parity(j);
			}
		}
		else{
			for(int j=0;j<k;++j){
				if(pos[j]==-id){
					pos[num=j]=0;break ;
				}
			}
			for(int j=0;j<(1<<k);++j){
				if((j>>num)&1) f[flag][j]=-0x3f3f3f3f;
				else f[flag][j]=max(f[flag^1][j|(1<<num)],f[flag^1][j])+len*__builtin_parity(j);
			}
		}
	}
	printf("%d\n",f[flag][0]);
	return 0;
}
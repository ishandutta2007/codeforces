#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=50005,M=N*31;
int n,tot,m,a[N],b[M],fa[M],si[M];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int t=a[i];
		while(t){
			b[++tot]=t;t/=2;
		}
	}
	sort(b+1,b+tot+1);
	b[m=1]=b[1];
	for(int i=2;i<=tot;i++)
		if(b[i]!=b[m]) b[++m]=b[i];
	for(int i=2;i<=m;i++)
		fa[i]=lower_bound(b+1,b+m+1,b[i]/2)-b;
//	for(int i=1;i<=m;i++) printf("%d ",b[i]);puts("");
	for(int i=1;i<=n;i++){
		int k=lower_bound(b+1,b+m+1,a[i])-b;
		while(k){
			si[k]++;k=fa[k];
		}
	}
	for(int i=1;i<=m;i++){
		int k=i;
		while(k&&si[k]){
			si[k]--;k=fa[k];
		}
		if(!k) printf("%d ",b[i]);
		if(!si[1]) return 0;
	}
	return 0;
}
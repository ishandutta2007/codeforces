#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e6+5;

int n,m;
int a[N];
map<int,map<int,int> >to;
int s[N];
int tim[N];
struct position{
	int x,v;
	position(const int x_=0,const int v_=0){x=x_;v=v_;}
	friend bool operator <(position a,position b){return a.v!=b.v?a.v<b.v:a.x<b.x;}
};
set<position>st;
int key[N],k;
int pv[N],pa[N];

int main(){
	n=get();m=get();
	fo(i,1,m)pv[i]=a[i]=get();
	int all=0;
	fo(i,1,m)all+=a[i];
	int t=all/n+(all%n>0);
	a[1]+=t*n-all;
	all=t*n;
	st.clear();
	fo(i,1,m)st.insert(position(i,a[i]));
	for(;st.begin()!=st.end();){
		set<position>::iterator h=st.end();
		h--;
		int k=0;
		int sum=0;
		if ((*h).v>=n&&all>n){
			k=0;
			for(set<position>::iterator p=st.begin();p!=st.end();p++)key[++k]=(*p).x;
			int x=(*h).x;
			st.erase(h);
			fo(i,1,k)to[++tim[key[i]]][key[i]]=x;
			a[x]-=n;
			all-=n;
			st.insert(position(x,a[x]));
		}
		else{
			int x=(*st.begin()).x;
			s[x]=a[x];
			n-=a[x];
			st.erase(st.begin());
			to[++tim[x]][x]=x;
			a[x]=0;
			all-=s[x];
			if (s[x]&&tim[x]<t){
				int need=t-tim[x];
				all-=(t-tim[x])*s[x];
				k=0;
				for(set<position>::iterator p=st.begin();need>0;p++){
					int y=(*p).x;
					key[++k]=y;
					pa[y]=a[y];
					for(;a[y]>=s[x]&&need>0;){
						need--;
						a[y]-=s[x];
						to[++tim[x]][x]=y;
					}
				}
				fo(i,1,k){
					st.erase(position(key[i],pa[key[i]]));
					st.insert(position(key[i],a[key[i]]));
				}
			}
			else{
				for(;tim[x]<t;)to[++tim[x]][x]=x;
			}
		}
	}
	printf("%d\n",t);
	fo(i,1,m)printf("%d%c",s[i],i==m?'\n':' ');
	fo(i,1,t)fo(j,1,m)printf("%d%c",to[i][j],j==m?'\n':' ');
	/*{
		bool right=1;
		fo(i,1,t)fo(j,1,m)pv[to[i][j]]-=s[j];
		fo(i,1,m)right&=(pv[i]<=0);
		fo(i,1,m)fprintf(stderr,"%d%c",pv[i],i==m?'\n':' ');
	}*/
	return 0;
}
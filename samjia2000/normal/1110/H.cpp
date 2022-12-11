#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

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

const int N = 3205;
const int INF = 1e9;

int n;
char rig[N],lef[N];
int lenr,lenl;
int f[2005][N];
pair<int,int> lst[2005][N];
int sa[N],y[N];
int rk[N];
int a[N],b[N],cnt[N];
int all[N];
int to[N][10];
int nxt[N];

int main(){
	scanf("%s",lef+1);
	scanf("%s",rig+1);
	n=get();
	lenl=strlen(lef+1);
	lenr=strlen(rig+1);
	int w=lenl;
	for(;w&&lef[lenl]=='0';)lef[w--]='9';
	lef[w]--;
	if (lef[1]=='0'){
		fo(i,1,lenl-1)lef[i]=lef[i+1];
		lenl--;
	}
	if (lenl==0)lenl=1,lef[1]='0';
	int m=0;
	fo(i,1,lenl)all[y[++m]=i]=lef[i]-'0';
	fo(i,1,lenr)all[y[++m]=i+lenl+lenr]=rig[i]-'0';
	fo(i,lenl+1,lenl+lenr)all[i]=10,a[i]=b[i]=INF;
	fo(i,1,lenr)all[i+lenl+lenr*2]=10,a[i+lenl+lenr*2]=b[i+lenl+lenr*2]=INF;
	fo(i,1,m)cnt[all[y[i]]]++;
	fo(i,1,9)cnt[i]+=cnt[i-1];
	fo(i,1,m)sa[cnt[all[y[i]]]--]=y[i];
	int k=1;
	a[sa[1]]=1;
	fo(i,2,m){
		if (all[sa[i]]>all[sa[i-1]])k++;
		a[sa[i]]=k;
	}
	for(int j=1;j<=max(lenl,lenr);j<<=1){
		int u=0;
		fo(i,1,m)if (sa[i]>j&&all[sa[i]-j]<10)y[++u]=sa[i]-j;
		fo(i,1,m)if (all[sa[i]+j]==10)y[++u]=sa[i];
		fo(i,0,m)cnt[i]=0;
		fo(i,1,m)cnt[a[y[i]]]++;
		fo(i,1,m)cnt[i]+=cnt[i-1];
		fd(i,m,1)sa[cnt[a[y[i]]]--]=y[i];
		fo(i,1,m)b[sa[i]]=a[sa[i]];
		a[sa[1]]=k=1;
		fo(i,2,m){
			if(b[sa[i]]>b[sa[i-1]]||(b[sa[i]]==b[sa[i-1]]&&b[sa[i]+j]>b[sa[i-1]+j]))k++;
			a[sa[i]]=k;
		}
	}
	int wl,wr;
	fo(i,1,m){
		nxt[sa[i]]=sa[i]+1;
		if (sa[i]==1)wl=i;
		if (sa[i]==lenl+lenr+1)wr=i;
		if (sa[i]==lenl)nxt[sa[i]]=0;
		if (sa[i]==lenl+lenr+lenr)nxt[sa[i]]=0;
		rk[sa[i]]=i;
	}
	rk[0]=m+1;
	fo(i,1,m+1){
		int x=sa[i];
		fo(c,0,9){
			int y=m+1;
			int l=1,r=m;
			for(;l<=r;){
				int mid=(l+r)/2;
				int u=sa[mid];
				if (all[u]>c||(all[u]==c&&rk[nxt[u]]>=i))y=mid,r=mid-1;
				else l=mid+1;
			}
			to[i][c]=y;
		}
	}
	fo(i,0,n+1)fo(j,1,m+1)f[i][j]=-INF;
	f[n+1][m+1]=0;
	fd(i,n+1,2)
		fo(j,1,m+1)
		if (f[i][j]!=-INF){
			fo(c,0,9){
				int p=to[j][c];
				int len=n-i+2;
				int ad=max(0,min(len+1,lenr)-lenl-1);
				if (c!=0){
					if (lenl==lenr){
						if (len>=lenl&&p>wl&&p<=wr)ad=1;
					}
					else{
						if (len>=lenl&&p>wl)ad++;
						if (len>=lenr&&p<=wr)ad++;
					}
				}
				else ad=0;
				if (f[i][j]+ad>f[i-1][p]||(f[i][j]+ad==f[i-1][p]&&(c<lst[i-1][p].fi||(c==lst[i-1][p].fi&&j<lst[i-1][p].se)))){
					f[i-1][p]=f[i][j]+ad;
					lst[i-1][p]=make_pair(c,j);
				}
			}
		}
	w=1;
	fo(i,2,m+1)if (f[1][w]<f[1][i])w=i;
	printf("%d\n",f[1][w]);
	int pw=w;
	w=pw;
	fo(i,1,n){
		putchar('0'+lst[i][w].fi);
		w=lst[i][w].se;
	}
	putchar('\n');
	return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const double eps=1e-6;
struct inout{
    static const int ibufl=1<<25;
    char in_buf[ibufl+5],out_buf[ibufl+5],*inf,*ouf;
    void init(){
        fread(in_buf,1,ibufl,stdin);
        inf=in_buf;
        ouf=out_buf;
    }
    inout& operator >>(int &a){
        int fh=1;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        a*=fh;
        return *this;
    }
    inout& operator >>(char &a){
        while(*inf==' '||*inf=='\n')++inf;
        a=*inf;
        ++inf;
        return *this;
    }
    inout& operator >>(char *a){
        while(*inf==' '||*inf=='\n')++inf;
        while(!(*inf==' '||*inf=='\n')){*a=*inf;++inf;++a;}
        *a='\0';
        return *this;
    }
    inout& operator >>(double &a){
        int fh=1;
        double s;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        if(*inf=='.'){
            s=0.1;
            ++inf;
            while(isdigit(*inf)){
                a+=s*(*inf-'0');
                ++inf;
                s*=0.1;
            }
        }
        a*=fh;
        return *this;
    }
    void writeint(int x){
        if(x/10)writeint(x/10);
        *ouf=x%10+'0';
        ++ouf;
    }
    inout& operator <<(int a){
 
        if(a<0){*ouf='-';++ouf;a=-a;}
        writeint(a);
        return *this;
    }
    static const int sz=2;
    inout& operator <<(char a){
        *ouf=a;++ouf;
        return *this;
    }
    inout& operator <<(char *a){
        while(*a){
            *ouf=*a;
            ++ouf;
            ++a;
        }
        return *this;
    }
    inout& operator <<(double a){
        if(a<-eps){*ouf='-';++ouf;a=-a;}
        writeint((int)a);
        a-=(int)a;
        *ouf='.';
        ++ouf;
        FOR(i,1,sz){
            a=a*10;
            *ouf=(int)a+'0';
            ++ouf;
            a-=(int)a;
        }
        return *this;
    }
    void out(){
        fwrite(out_buf,1,ouf-out_buf,stdout);
    }
};
inout io;
#define cin io
#define cout io
//const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,k,t,tot,f[15],num[15],top[15],p[15][15];
bool con[15][15],vis[1<<15][15][15];
array<int,3> a[600001];
bool dfs1(int mask,int x,int y)
{
	a[++t]={mask,x,y};
	if(mask==(1<<n)-1)
		return 1;
	for(int i=1;i<=tot;i++)
		for(int l=1;l<=top[i];l++)
			if(((mask>>p[i][l])&1)==0)
				for(int j=l+1;j<=top[i];j++)
					if(((mask>>p[i][j])&1)==0)
						if((con[x][p[i][l]]&&con[y][p[i][j]])||(con[x][p[i][j]]&&con[y][p[i][l]]))
						{
							if(vis[mask|(1<<p[i][l])|(1<<p[i][j])][p[i][l]][p[i][j]])
								continue;
							vis[mask|(1<<p[i][l])|(1<<p[i][j])][p[i][l]][p[i][j]]=1;
							if(dfs1(mask|(1<<p[i][l])|(1<<p[i][j]),p[i][l],p[i][j]))
								return 1;
						}
	return 0;
}
void dfs(int x,int col,int now)
{
	if(x+now>n)
		return ;
	if(x==n)
	{
		t=0,tot=col;
		for(int i=1;i<=col;i++)
			for(int l=1;l<=top[i];l++)
				for(int j=l+1;j<=top[i];j++)
					if(con[p[i][l]][p[i][j]])
					{
						vis[(1<<p[i][l])|(1<<p[i][j])][p[i][l]][p[i][j]]=1;
						if(dfs1((1<<p[i][l])|(1<<p[i][j]),p[i][l],p[i][j]))
						{
							f[col]++;
							for(int k=1;k<=t;k++)
								vis[a[k][0]][a[k][1]][a[k][2]]=0;
							return ;
						}
//						vis[(1<<p[i][l])|(1<<p[i][j])][p[i][l]][p[i][j]]=0;
					}
		for(int i=1;i<=t;i++)
			vis[a[i][0]][a[i][1]][a[i][2]]=0;
		return ;
	}
	for(int i=1;i<=col+1;i++)
	{
		num[i]++;
		p[i][++top[i]]=x;
		dfs(x+1,max(col,i),now+((num[i]&1)?1:(-1)));
		num[i]--;
		top[i]--;
	}
}
signed main()
{
	io.init();
	cin>>n>>m>>k;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		con[x][y]=con[y][x]=1;
	}
	dfs(0,0,0);
	long long cnt=1,ans=0;
	for(int i=1;i<=k;i++)
	{
//		cout<<f[i]<<endl;
		cnt*=(k-i+1);
		ans+=cnt*f[i];
	}
	printf("%lld",ans);
	return 0;
}
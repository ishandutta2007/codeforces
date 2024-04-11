#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;const double eps=1e-6;
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
 
/*----------------------------------------------------------------------------------------------*/
const int N=2e6+1;
int n,m,ans,t[N][2],pre[N],suf[N],z1[N],z2[N];
char a[N],b[N],s[N];
void gmin(int &x,int y)
{
	if(x>y)
		x=y;
}
void Z(char* x,int* y)
{
	int it=0,len=n+m+1;
	for(int i=2;i<=len;i++)
	{
		if(it+y[it]>i)
		{
			y[i]=y[i-it+1];
			gmin(y[i],y[it]+it-i);
		}
		while(i+y[i]<=len&&x[i+y[i]]==x[y[i]+1])
			y[i]++;
		if(i+y[i]>it+y[it])
			it=i;
	}
}
#define lowbit(x) (x&(-x))
void add(int x,int y)
{
	for(int z=x*y;x<N;x+=lowbit(x))
	{
		t[x][0]+=y;
		t[x][1]+=z;
	}
}
int query(int x)
{
	int res1=0,res2=0;
	for(int i=x;i;i^=lowbit(i))
	{
		res1+=t[i][0];
		res2+=t[i][1];
	}
	return (x+1)*res1-res2;
}
signed main()
{
	io.init();
	cin>>n>>m;
	for(int i=m+2;i<=n+m+1;i++)
		cin>>a[i];
	for(int i=m+2;i<=n+m+1;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		cin>>s[i];
	reverse(b+m+2,b+n+m+2);
	for(int i=1;i<=m;i++)
	{
		a[i]=s[i];
		b[i]=s[m-i+1];
	}
	a[m+1]=a[m]=b[m+1]=b[m]='$';
	Z(a,z1);
	Z(b,z2);
	for(int i=1;i<=n;i++)
	{
		pre[i]=z1[i+m+1];
		suf[n-i+1]=z2[i+m+1];
	}
//	for(int i=1;i<=n;i++)
//		cout<<pre[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//		cout<<suf[i]<<" ";
//	cout<<endl;
	for(int i=n;i;i--)
	{
		add(m-suf[i],1);
		if(i+m-1<=n)
			add(m-suf[i+m-1],-1);
		ans+=query(pre[i]);	
//		for(int l=1;l<=n;l++)
//			cout<<query(l)<<" ";
//		cout<<endl;
	}
	cout<<ans;
	io.out();
	return 0;
}
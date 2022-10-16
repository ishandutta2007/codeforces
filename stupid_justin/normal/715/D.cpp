#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define y1 _
#define pii pair<int,int> 
#define mp make_pair
using namespace std;
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

struct Four{int x1,y1,x2,y2;};
set<pair< pii,pii > > S;
void add(int x1,int y1,int x2,int y2) {if (x1<1 || y1<1 || x2<1 || y2<1) return;if (x1+y1>x2+y2) swap(x1,x2),swap(y1,y2);S.insert(mp(mp(x1,y1),mp(x2,y2)));}
int X,Y;


void change(int k)
{
	add(X-2,X+3,X-1,X+3);
	add(X-1,X+1,X,X+1);
    add(X,X+2,X,X+3);
	add(X,X+4,X+1,X+4);
	add(X+1,X+2,X+1,X+3);
	add(X+2,X,X+3,X);
	add(X+2,X+1,X+3,X+1);
	add(X+3,X-2,X+3,X-1);
	add(X+4,X,X+4,X+1);
	if(k%3==0) add(X-1,X+2,X,X+2);
	if(k%3!=2) add(X+2,X-1,X+2,X);
	if(k<3) add(X+1,X-1,X+1,X);
	X+=2;Y+=2;
}
int T;
int a[N],t,sz;
signed main()
{
    rd(T);
    add(1,2,2,2);add(2,1,2,2);
    X=Y=2;
    while (T) a[++t]=T%6,T/=6;
    for (int i=t;i>=1;i--) change(a[i]);
    cout<<X<<" "<<Y<<endl;
    for (pair< pii,pii > p:S)
    {
        if (p.first.first>X || p.second.second>X || p.first.second>X || p.second.first>X) sz++;
    }
    cout<<S.size()-sz<<endl;
    for (pair< pii,pii > p:S)
    {
        if (p.first.first>X || p.second.second>X || p.first.second>X || p.second.first>X) continue;
        cout<<p.first.first<<" "<<p.first.second<<" "<<p.second.first<<" "<<p.second.second<<"\n";
    }

}
/*
*/
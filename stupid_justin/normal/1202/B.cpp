
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
string s;
int x[100];
int calc(int m,int n)
{
	for(int i=0;i<=10;i++) x[i]=100;
	for(int i=0;i<=10;i++) for(int j=0;j<=10;j++) if (i!=0 || j!=0) x[(i*m+j*n)%10] = min(x[(i*m+j*n)%10],i+j);
	int sum=0,num;
	for(int i=1;i<s.length();i++)
    {
		num=s[i]-s[i-1];
		if(num<0) num+=10;
		if(x[num]==100) return -1;
		sum+=x[num]-1;
	}
	return sum;
}
signed main()
{
    cin>>s;
    for (int i=0;i<=9;i++) for (int j=0;j<=9;j++) cout<<calc(i,j)<<" \n"[j==9];
}
/*

*/
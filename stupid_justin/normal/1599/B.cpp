#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define print(i) {if (i)cout<<n-1<<"\n";else cout<<0<<"\n";return;}
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}

int n,A,B;
int ans;
string a,b;
bool flag=0;
void DOIT()
{
	rd(n);rd(A);rd(B);A++;B++;
	cin>>a>>b;
	if (A>B)
	{
		if (a=="left") A--;else A++;if (A==0) A=2;if (A==n+1) A=n-1;
		swap(A,B);swap(a,b);
	}
	if (A==1 && B==1) print(1)
	if (A==1 && B==2) print(0)
	if (A==n) print(0)
	if (A==n-1) print(0)
	if (A<B)
	{
		if (a=="right" && b=="left") print((A+B+1)%2)
		if (a=="left" && b=="left") 
		{
			B-=A-1;A=1;
			if (A==1 && B==1) print(1)
			if (A==1 && B==2) print(0)
			print((A+B+1)%2)
		}
		if (a=="right" && b=="right") 
		{
			A+=n-B;B=n;
			if (A==n) print(0)
			if (A==n-1) print(0)
			print((A+B+1)%2)
		}
		if (a=="left" && b=="right")
		{
			int t=max(A-1,n-B);
			A-=t;if (A<1) A=2-A;
			B+=t;if (B>n) B=2*n-B;
			if (A==1 && B==1) print(1)
			if (A==1 && B==2) print(0)
			if (B==n && A==n) print(0)
			if (B==n && A==n-1) print(1)
			print((A+B+1)%2)
		}
	} else 
	if (A==B)
	{
		if (a=="left" && b=="right") print(0)
		if (a=="left" && b=="left") print(1)
		if (a=="right" && b=="right") print(0)
		if (a=="right" && b=="left") print(1)
	}
	
}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
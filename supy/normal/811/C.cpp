#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 5005
int n,a[N],cnt[N],f[N],tot[N],num[N];
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int main()
{
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) tot[a[i]]++;
	rep(i,1,n) {
		f[i]=f[i-1];
		//cnt : now appear
		int v=0,sum=0;
		for (int j=i; j>=1; j--) {
			if (cnt[a[j]]==i) {
				num[a[j]]++;
				if (num[a[j]]==tot[a[j]]) sum--;
			}
			else {
				cnt[a[j]]=i;
				v^=a[j];
				if (tot[a[j]]>1) {sum++; num[a[j]]=1;}
			}
			if (!sum) f[i]=max(f[i],f[j-1]+v);
		}
	}
	printf("%d",f[n]);
	return 0;
}
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;
 
const int N=1e5+5;
const int M=2e7+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}
 
 
int ABS(int x){return x<0?-x:x;}
int n;
string ans;
int k[N];
struct Node
{
	int a,b,c; 
};
vector<Node> v;
bool cmp(Node x,Node y){return x.a>y.a;}
signed main()
{
	rd(n);for (int i=1;i<=n;i++) rd(k[i]);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) v.push_back((Node){ABS(k[i]-k[j]),i,j});
	sort(v.begin(),v.end(),cmp);
	for (Node x:v)
	{
		int a=x.b,b=x.c;
		if (k[a]<k[b]) swap(a,b);
		cout<<"? "<<a<<" "<<b<<"\n";
		cin>>ans;
		if(ans=="Yes") {cout<<"! "<<a<<" "<<b<<"\n";return 0;}
	}
	cout<<"! 0 0"<<"\n";
}
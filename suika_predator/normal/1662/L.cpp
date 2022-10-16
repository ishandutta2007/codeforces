#include<bits/stdc++.h>
#define ll long long
#define int long long
#define lowbit(x) ((x)&(-x))
using namespace std;

inline void up(int &a,const int &b){ if(a<b)a=b; }
const int maxn = 210000;

int n,V;
int ti[maxn],ai[maxn];
int A[maxn],B[maxn];
//  -       +
int t[maxn],tp;

int id[maxn],f[maxn];
bool cmpb(const int x,const int y){ return B[x]<B[y]; }
bool cmpt(const int x,const int y){ return ti[x]<ti[y]; }
int s[maxn];
void init()
{
	for(int i=1;i<=n;i++) s[i]=INT_MIN;
}
void add(int x,int c)
{
	for(;x<=n;x+=lowbit(x)) up(s[x],c);
}
void rec(int x)
{
	for(;x<=n;x+=lowbit(x)) s[x]=INT_MIN;
}
int query(int x)
{
	int re=INT_MIN;
	for(;x;x-=lowbit(x)) up(re,s[x]);
	return re;
}
void cdq(const int l,const int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid); 
	
	sort(id+l,id+mid+1,cmpb);
	sort(id+mid+1,id+r+1,cmpb);
	int i=l,j=mid+1;
	while(i<=mid || j<=r)
	{
		if(i==mid+1)
		{
			up( f[id[j]],  query(A[id[j]])+1);
			j++;
			continue;
		}
		if(j==r+1) break;
		if(B[id[i]] <= B[id[j]])
		{
			add(A[id[i]],f[id[i]]);
			i++;
		}
		else 
		{
			up( f[id[j]],  query(A[id[j]])+1);
			j++;
		}
	}
	for(int k=l;k<=mid;k++) rec(A[id[k]]);
	
	sort(id+l,id+mid+1,cmpt);
	sort(id+mid+1,id+r+1,cmpt);
	cdq(mid+1,r);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>V;
	//n=200; V=1;
	for(int i=1;i<=n;i++) cin>>ti[i];
	for(int i=1;i<=n;i++) cin>>ai[i];
	
	for(int i=1;i<=n;i++) A[i]=ai[i]-V*ti[i];
	for(int i=1;i<=n;i++) B[i]=ai[i]+V*ti[i];
	
	for(int i=1;i<=n;i++) t[i]=A[i];
	sort(t+1,t+n+1);
	tp=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;i++) A[i]=n- (lower_bound(t+1,t+tp+1,A[i])-t)+1;
	
	for(int i=1;i<=n;i++) t[i]=B[i];
	sort(t+1,t+n+1);
	tp=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;i++) B[i]=lower_bound(t+1,t+tp+1,B[i])-t;
	
	//for(int i=1;i<=n;i++) A[i]=i;
	//for(int i=1;i<=n;i++) B[i]=i;
	
	init();
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=n;i++)
	{
		f[i]=INT_MIN;
		if( abs(ai[i]) <= V*ti[i] )
			f[i]=1;
	}
	cdq(1,n);
	int ans=0;
	for(int i=1;i<=n;i++) up(ans,f[i]);
	cout<<ans<<endl;
	
	return 0;
}
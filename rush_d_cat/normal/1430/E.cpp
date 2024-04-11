#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n; char s[N],t[N];
int sum[N<<2];
void update(int l,int r,int rt,int pos,int x){
	if(l==r){
		sum[rt]=x; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return sum[rt];
	int mid=(l+r)>>1,ans=0;
	if(L<=mid) ans+=query(l,mid,rt<<1,L,R);
	if(R >mid) ans+=query(mid+1,r,rt<<1|1,L,R);
	return ans; 
}
set<int> st[27];
int main() {
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)t[i]=s[n+1-i];
	for(int i=1;i<=n;i++)update(1,n,1,i,1);
	for(int i=1;i<=n;i++)
		st[s[i]-'a'].insert(i);
	LL ans=0;
	for(int i=1;i<=n;i++){
		int need=t[i]-'a';
		int pos=*st[need].begin();
		update(1,n,1,pos,0);
		ans+=query(1,n,1,1,pos);
		st[need].erase(st[need].begin());
	}
	cout<<ans<<endl;
}
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define Maxn 100000
struct P{
	int l,r;
}t[(Maxn<<1)|5];
struct Q{
	int lc,rc,tag,sum;
}tre[(Maxn<<1)|5];
int n,k,num[(Maxn<<1)|5];
vector<int> bkt[Maxn+5];
bool cmp(P a,P b){
	if(a.l==b.l){
		return a.r<b.r;
	}
	return a.l<b.l;
}
void push_down(int s,int l,int r){
	int mid=((l+r)>>1);
	int tmp=(tre[s].tag&1);
	if(!tmp){
		tre[s].tag=0;
		return;
	}
	int lson=tre[s].lc,rson=tre[s].rc;
	tre[lson].sum=(mid-l+1)-tre[lson].sum;
	tre[lson].tag+=tre[s].tag;
	tre[rson].sum=(r-mid)-tre[rson].sum;
	tre[rson].tag+=tre[s].tag;
	tre[s].tag=0;
}
int cnt=1;
void build(int s,int l,int r){
	if(l==r){
		return;
	}
	int mid=((l+r)>>1);
	tre[s].lc=++cnt;
	build(tre[s].lc,l,mid);
	tre[s].rc=++cnt;
	build(tre[s].rc,mid+1,r);
}
void update(int s,int l,int r,int cl,int cr){
	if(l==cl&&r==cr){
		tre[s].sum=(r-l+1)-tre[s].sum;
		tre[s].tag++;
		return;
	}
	if(tre[s].tag){
		push_down(s,l,r);
	}
	int mid=((l+r)>>1);
	if(cr<=mid){
		update(tre[s].lc,l,mid,cl,cr);
	}
	else if(cl>mid){
		update(tre[s].rc,mid+1,r,cl,cr);
	}
	else{
		update(tre[s].lc,l,mid,cl,mid);
		update(tre[s].rc,mid+1,r,mid+1,cr);
	}
	tre[s].sum=tre[tre[s].lc].sum+tre[tre[s].rc].sum;
}
int query(int s,int l,int r,int cl,int cr){
	if(l==cl&&r==cr){
		return tre[s].sum;
	}
	if(tre[s].tag){
		push_down(s,l,r);
	}
	int mid=((l+r)>>1);
	if(cr<=mid){
		return query(tre[s].lc,l,mid,cl,cr);
	}
	else if(cl>mid){
		return query(tre[s].rc,mid+1,r,cl,cr);
	}
	else{
		return query(tre[s].lc,l,mid,cl,mid)+query(tre[s].rc,mid+1,r,mid+1,cr);
	}
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	build(1,1,n);
	num[n+1]=1e17;
	int fina=n*(n-1)*(n-2)/6;
	for(int i=1,a,b;i<=k;i++){
		cin>>a>>b;
		t[i].l=lower_bound(num+1,num+1+n,a)-num;
		t[i].r=upper_bound(num+1,num+1+n+1,b)-num-1;
		if(t[i].l>t[i].r){
			t[i].l=t[i].r=1e17;
		}
	}
	sort(t+1,t+1+k,cmp);
	int now=1;
	for(int i=1;i<=n;i++){
		while(t[now].l==i){
			update(1,1,n,t[now].l,t[now].r);
			bkt[t[now].r].push_back(t[now].l);
			now++;
		}
		int tmp=0;
		if(i>1){
			tmp+=query(1,1,n,1,i-1);
		}
		if(i<n){
			tmp+=(n-i)-query(1,1,n,i+1,n);
		}
		for(int j=0;j<(int)bkt[i].size();j++){
			update(1,1,n,bkt[i][j],i);
		}
		fina-=tmp*(tmp-1)/2;
	}
	cout<<fina<<endl;
	return 0;
}
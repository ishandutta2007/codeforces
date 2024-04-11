# include <bits/stdc++.h>
using namespace std;
struct node
{
	long long val;
	long long l;
	long long r;
	long long sum;
};
long long INF = 30000000000000LL;
node tree[2500000];
long long a[1000001];
long long c[1000001];
long long d[1000001];
void build(int x,int l,int r)
{
	if (l==r)
	{
		tree[x].val=a[l];
		tree[x].l=a[l];
		tree[x].r=a[l];
		tree[x].sum=a[l];
	}
	else
	{
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
        tree[x].r=max(tree[2*x+1].sum+tree[2*x].r,tree[2*x+1].r);
        tree[x].l=max(tree[2*x].l,tree[2*x].sum+tree[2*x+1].l);
		tree[x].val=max(tree[2*x+1].val,max(tree[2*x].val,tree[2*x].r+tree[2*x+1].l));
		tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
	}
}
node query(int x,int s,int e,int l,int r)
{
	node ans;
	ans.val=-INF;
	ans.l=-INF;
	ans.r=-INF;
	ans.sum=-INF;
	if (s>r || e<l)
		return ans;
	if (s<=l && e>=r)
		return tree[x];
	node p1=query(x*2,s,e,l,(l+r)/2);
	node p2=query(x*2+1,s,e,(l+r)/2+1,r);
	if (p1.val==-INF && p1.r==INF && p1.l==INF && p1.sum==-INF)
		return p2;
	if (p2.val==-INF && p2.r==INF && p2.l==INF && p2.sum==-INF)
		return p1;
	ans.r=max(p1.r+p2.sum,p2.r);
	ans.l=max(p1.sum+p2.l,p1.l);
	ans.val=max(p1.val,max(p2.val,p1.r+p2.l));
	return ans;
}
void update(int x,int i,long long v,int l,int r)
{
	if (i<l || i>r)
		;
	else if (i==l && i==r)
	{
		tree[x].val=v;
		tree[x].l=v;
		tree[x].r=v;
		tree[x].sum=v;
	}
	else
	{
		int left=2*x;
		int right=left+1;
		int mid=(l+r)/2;
		update(left,i,v,l,mid);
		update(right,i,v,mid+1,r);
		tree[x].val=max(tree[left].val,max(tree[right].val,tree[left].r+tree[right].l));
		tree[x].r=max(tree[right].r,tree[right].sum+tree[left].r);
		tree[x].l=max(tree[left].sum+tree[right].l,tree[left].l);
		tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
	}
}
vector<pair<long long,int> > vec;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	long long x;
	cin>>n>>x;
	int tot=n*2-1;

    long long ret = 0;
	for (int i=0;i<n;i++)
	{
	    cin>>d[i*2]>>c[i*2];
	    if (i>0)
            vec.push_back({d[i*2]-d[i*2-2],i*2-1});
	    a[i*2]=x-c[i*2];
	    ret=max(ret,a[i*2]);
	}
	build(1,0,tot-1);
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for (int i=0;i<vec.size();)
    {
        int j=i;
        while(j+1<vec.size() && vec[j+1].first==vec[j].first)j++;
        long long cur = query(1,0,tot-1,0,tot-1).val;
        ret=max(ret,cur - vec[j].first*vec[j].first);
        while(i<=j)
        {
            update(1,vec[i].second,-INF,0,tot-1);
            i++;
        }
    }
    cout<<ret<<endl;
}
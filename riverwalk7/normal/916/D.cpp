#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define gl(n) cin >> n
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define present(s,x) (s.find(x) != s.end())
using namespace std;

typedef long long int ll;
ll qrst[4000];

struct node
{
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w,int v);
};

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int w,int v)
{
	if(l == r)
	{
		return new node(this->count+v, null, null);
	}
    int m = (l+r)>>1;

    if(w<=m)
    return new node(this->count+v, this->left->insert(l, m, w,v),this->right);
    return new node(this->count+v, this->left, this->right->insert(m+1, r, w,v));

}

node *root[100005];

int get(node *a,int l,int r,int w)
{
	if(l==r)return a->count;
	int m=(l+r)/2;
	if(w<=m)return get(a->left,l,m,w);
	return a->left->count+get(a->right,m+1,r,w);
}

struct node1
{
	int count;
	node1 *left, *right;

	node1(int count, node1 *left, node1 *right):
		count(count), left(left), right(right) {}

	node1* insert(int l, int r, int w,int v);
};

node1 *null1 = new node1(0, NULL, NULL);

node1 * node1::insert(int l, int r, int w, int v)
{
	if(l == r)
	{
		return new node1(v, null1, null1);
	}
    int m = (l+r)>>1;

    if(w<=m)
    return new node1(v, this->left->insert(l, m, w,v),this->right);
    return new node1(v, this->left, this->right->insert(m+1, r, w,v));

}

node1 *root1[100005];

int get1(node1 *a,int l,int r,int w)
{
	if(l==r)return a->count;
	int m=(l+r)/2;
	if(w<=m)return get1(a->left,l,m,w);
	return get1(a->right,m+1,r,w);
}

ll pp=1e5+7,mod=1e9+7,ptr=0;
map<string,int> m;
int getno(string s)
{
	if(present(m,s))return m[s];
	m[s]=++ptr;
	return m[s];
}

int main()
{ios_base::sync_with_stdio(false);
int q;
cin>>q;
null->left=null->right=null;
null1->left=null1->right=null1;
root[0]=null;
root1[0]=null1;
rep(i,1,q)
{
	root[i]=root[i-1];
	root1[i]=root1[i-1];
	string qq;
	cin>>qq;
	for(int ii=0; ii<4000; ii++)
    {
        qrst[ii]++;
    }
	if(qq=="undo")
	{
		int x;
		cin>>x;
		x++;
		root[i]=root[i-x];
		root1[i]=root1[i-x];
	}
	else if(qq=="set")
	{
		string a;
		int p;
		cin>>a>>p;
		int id=getno(a);
		int prev=get1(root1[i],0,mod,id);
		if(prev>0)
		{
			root[i]=root[i]->insert(0,mod,prev,-1);
		}
		root[i]=root[i]->insert(0,mod,p,1);
		root1[i]=root1[i]->insert(0,mod,id,p);
	}
	else if(qq=="remove")
	{
		string a;
		cin>>a;
		int id=getno(a);
		int prev=get1(root1[i],0,mod,id);
		if(prev>0)
		{
			root[i]=root[i]->insert(0,mod,prev,-1);
		}
		root1[i]=root1[i]->insert(0,mod,id,0);
	}
	else
	{
		string a;
		cin>>a;
		int id=getno(a);
		int x=get1(root1[i],0,mod,id);
		if(x==0)ol("-1");
		else
		ol(get(root[i],0,mod,x-1));
		on;
	}
}


return 0;
}
#include <iostream>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
int b[110000];
int t[510000],a[510000];

int num[110000];

bool comp(int x, int y)
{
	return b[x]<b[y];
}

void build(int i, int l,int r)
{
	if (l==r)
	{
		a[i]=i;
		return ;
	}
	build(2*i,l,(l+r)/2);
	build(2*i+1,(l+r)/2+1,r);
	a[i]=r;
}

pair <int,int> get(int i,int cl,int cr,int l,int r)
{
	if (l==cl&&r==cr) return make_pair(a[i], t[i]);

	if (l>(cl+cr)/2) return get(2*i+1, (cl+cr)/2+1, cr, l, r);
	if (r<=(cl+cr)/2) return get(2*i, cl, (cl+cr)/2, l, r);

	pair <int,int> A=get(2*i, cl, (cl+cr)/2, l, (cl+cr)/2);
	pair <int,int> B=get(2*i+1, (cl+cr)/2+1, cr, (cl+cr)/2+1, r);

	if (B.second>=A.second) return B;
	return A;
}

void upd(int i,int l,int r,int k,int delta)
{
	if (l == r)
	{
		t[i]=delta;
		a[i]=r;
		return ;
	}
	if (k>(l+r)/2) upd(2*i+1, (l+r)/2+1, r, k, delta); else
		upd(2*i, l, (l+r)/2, k, delta);

	pair <int,int> A = make_pair(a[2*i],t[2*i]);
	pair <int,int> B = make_pair(a[2*i+1],t[2*i+1]);
	if (B.second>=A.second) t[i]=B.second,a[i]=B.first; else
		t[i]=A.second,a[i]=A.first;
}

int res[110000];

int main()
{
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
		scanf("%d", &b[i]), num[i]=i;
	sort(num+1, num+n+1, comp);
	build(1,1,n);
	int l = 1;
	for (int i=1; i<=n; i++)
	{
		if (i!=1 && b[num[i]]>b[num[i-1]])
		{
			for (int j=l;j<i; j++)
				upd(1,1,n,num[j],1);
			l=i;
		}
		int v=num[i];
		pair<int, int > cur = get(1, 1, n, v, n);
		if (cur.second==0) res[v]=-1; else res[v] = cur.first-v-1;
	}
	for (int i=1; i<=n; i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}
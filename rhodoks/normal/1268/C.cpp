#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

class BinaryIndexTree
{
public:
	int* bit;
	int size;
	
	BinaryIndexTree(int _size=MAXN)
	{
		size=_size;
		bit=(int*)new int[size+2]; 
		for (int i=0;i<=size;i++)
			bit[i]=0;
	}
	
	int lowbit(int x)
	{
		return x&-x;
	}
	
	void add(int x,int a)
	{
		for (;x<=size;x+=lowbit(x))
		{
			//WRT(x);
			bit[x]+=a;
		}
	}
	
	int query(int x)
	{
		int ans=0;
		for (;x;x-=lowbit(x))
			ans+=bit[x];
		return ans;
	}
};
typedef BinaryIndexTree BIT;

int pos[MAXN];
int a[MAXN];
int n,x;
set<int> st;
LL tmp;
LL res;
int cur;
int l,r;

int main()
{
	cin>>n;
	BIT bit(n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=x;
		pos[x]=i;
	}
	set<int>::iterator p;
	for (int i=1;i<=n;i++)
	{
		tmp+=bit.query(pos[i]);
		bit.add(pos[i],1);
		if (i==1)
		{
			st.insert(pos[i]);
			p=st.find(pos[i]);
		}
		else
		{
			st.insert(pos[i]);
			res+=abs(pos[i]-*p);
			if (pos[i]>*p)
			{
				r++;
				res-=r;
			}
			else
			{
				l++;
				res-=l;
			}
			if (l-r==2)
			{
				int lst=*p;
				p--;
				res-=lst-*p-1;
				l--;
				r++;
			}
			if (r-l==2)
			{
				int lst=*p;
				p++;
				res-=*p-lst-1;
				l++;
				r--;
			}
		}
		//cout<<l<<' '<<r<<' '<<res<<endl;
		//WRT(tmp);
		printf("%lld ",res+(LL)i*(i-1)/2-tmp);
	}
	return ~~(0^_^0);
}
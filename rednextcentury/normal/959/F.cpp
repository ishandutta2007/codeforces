#include<bits/stdc++.h>
using namespace std;
long long P[1000000];
int cur;
long long ret[1000000];
int a[1000000];
vector<pair<int,int> > vec[1000000];
struct Base
{
	#define type int
	#define mx 22
	type d[mx+1];
	type p[mx+1];
	int sz;
	int cnt;
	Base()
	{
	    sz=0;
        cnt=0;
        for (int i=0;i<=mx;i++)
            d[i]=p[i]=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		if (x)
            p[sz++]=x;
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if ((res^d[i]) > res)res^=d[i];
		}
		return res;
	}
	type query_min()
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]) return d[i];
		}
		return 0;
	}

	type getX(type X)
    {
        for(int i=mx;~i;i--)
        {
            if ((1<<i)&X)
                X^=d[i];
        }
        if (X==0)
            return P[cur-sz];
        else return 0;
    }

};

int main()
{
    int n,q;

    cin>>n>>q;
    P[0]=1;
    for (int i=1;i<=n;i++)
        P[i]=(P[i-1]*2)%1000000007;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=0;i<q;i++)
    {
        int l,x;
        cin>>l>>x;
        vec[l].push_back({x,i});
    }
    Base b;
    for (int i=1;i<=n;i++)
    {
        cur=i;
        b.insert(a[i]);
        for (auto p:vec[i])
        {
            ret[p.second]=b.getX(p.first);
        }
    }
    for (int i=0;i<q;i++)
        cout<<ret[i]<<endl;
}
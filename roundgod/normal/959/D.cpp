#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
bool used[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
bool erased[MAXN],er[MAXN];
vector<int> G[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
set<int> s;
int main()
{
	int p=sieve(2000000);
	for(int i=0;i<p;i++)
	{
		for(int j=prime[i];j<=2000000;j+=prime[i])
			G[j].push_back(i);
	}
	s.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=2000000;i++)
		s.insert(i);
	bool f=true;
	memset(erased,false,sizeof(erased));
	memset(er,false,sizeof(er));
	for(int i=1;i<=n;i++)
	{
		if(!f)
		{
			auto it=s.lower_bound(2);
			b[i]=*it;
			for(int j=0;j<G[b[i]].size();j++)
			{
				int pp=G[b[i]][j];
				if(erased[pp]) continue;
				erased[pp]=true;
				pp=prime[pp];
				for(int k=pp;k<=2000000;k+=pp)
					if(!er[k]) {s.erase(k); er[k]=true;}
			}
			continue;
		}
		if(er[a[i]])
		{
			f=false;
			auto it=s.lower_bound(a[i]+1);
			b[i]=*it;
			for(int j=0;j<G[b[i]].size();j++)
			{
				int pp=G[b[i]][j];
				if(erased[pp]) continue;
				erased[pp]=true;
				pp=prime[pp];
				for(int k=pp;k<=2000000;k+=pp)
					if(!er[k]) {s.erase(k); er[k]=true;}
			}
			continue;
		}
		b[i]=a[i];
		for(int j=0;j<G[b[i]].size();j++)
		{
			int pp=G[b[i]][j];
			if(erased[pp]) continue;
			erased[pp]=true;
			pp=prime[pp];
			for(int k=pp;k<=2000000;k+=pp)
				if(!er[k]) {s.erase(k); er[k]=true;}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	return 0;
}
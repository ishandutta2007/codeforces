#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int cnt[MAXN];
vector<int> mult[MAXN];
vector<int> divi[MAXN];
vector<int> st;
int save[MAXN];
ll ans;
int prime[MAXN],mu[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    mu[1]=1;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void add(int val)
{
	for(auto x:divi[val])
		save[x]++;
}
void del(int val)
{
	for(auto x:divi[val])
		save[x]--;
}
int check(int val)
{
	int res=0;
	for(auto x:divi[val]) res+=mu[x]*save[x];
	return res;
}
void solve(int g)
{
	for(auto x:mult[g])
	{
		while(check(x))
		{
			int v=st.back(); st.pop_back(); del(v);
			if(__gcd(x,v)==1) ans=max(ans,1LL*x*v*g);
		}
		st.push_back(x); add(x);
	}
	for(auto x:st) del(x);
	st.clear();
}
int main()
{
	sieve(100000);
	for(int i=1;i<=100000;i++)
		for(int j=i;j<=100000;j+=i)
			divi[j].push_back(i);
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=100000;i>=1;i--)
	{
		if(cnt[i]>=2) ans=i;
		if(cnt[i]) 
			for(auto x:divi[i])
				mult[x].push_back(i/x);
	}
	for(int i=1;i<=100000;i++) solve(i);
	printf("%lld\n",ans);
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pll pair<ll,ll>
#define vll vector<ll>
#define vint vector<int>
#define usll unordered_set<ll>
#define sll set<ll>
#define mll map<ll,ll>
#define pb push_back
#define mp make_pair
#define forr(i, n) for(ll int i = 0; i < n; i++)
#define forr1(i,n) for(ll int i=1;i<n;i++)
#define forra(i,a,b) for(ll int i=a;i<b;i++)
#define arrin(a,n) forr(i,n) cin>>a[i];
#define arrout(a,n) forr(i,n) {cout<<a[i]<<' ';} cout<<'\n';
#define umap unordered_map
typedef long long int lli;
typedef long int li;
using namespace std;
bool primes[1000000+1];
void sieve(lli n){
	 primes[0]=false;
	 primes[1]=false;
	 for(lli i{2};i<=n;i++){primes[i]=true;}
	 for(lli i{2};i<=sqrt(n);i++){
			 if(primes[i]==true){
				for(lli j{2};j*i<=n;j++){primes[i*j]=false;}
			 }
	 }
}
bool comp(pair<int,int> &a, pair<int,int> &b) 
{
    return (a.first < b.first);
}
lli gcd(lli a,lli b){
	if(a==0) return b;
	return gcd(b%a,a);
}
lli lcm(lli a,lli b){
	return a*b/gcd(a,b);
}
lli fastpow(long long base, long long n)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fastpow(base,n/2);
    if(n%2==0)
        return ( halfn * halfn );
    else
        return ( ( ( halfn * halfn ) ) * base );
}
void bfs(lli s, vector<lli> v[], bool vis[])
{
    queue<lli> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        lli a=q.front();
        q.pop();
        //process node 'a'
        for(auto x : v[a])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                //e[x] = e[a]+1; where e[i] is distance from 0/root and e[0/root]=0
            }
        }
    }
}
void dfs(lli s, vector<lli> v[], bool vis[])
{
    //process node 's'
    vis[s]=true;
    for(auto x : v[s])
    {
        if(!vis[x])
        {
            dfs(x,v,vis);
        }
    }
}
bool checksubsq(string s,lli l,string t,lli j){
	for(lli i{l};i<s.size();i++){
		if(s[i]==t[j]){
			if(j==t.size()-1){
				return true;
			}
			else{
				return checksubsq(s,i+1,t,j+1);
			}
		}
	}
	return false;
}
lli mod=1000000007;
lli dp[500];
lli rs(lli n,lli u){
	if(n==0)
		return 1;
	if(u<1&&n!=0)
		return 0;
	lli sum=0;
	for(lli i{1};i<=u;i++){
		if(i<=n){
			if(dp[n-i]==-1){
				dp[n-i]=rs(n-i,u);
			}
			sum+=(dp[n-i]%mod);
		}
		else{
			break;
		}
	}
	return dp[n]=(sum%mod);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli n,k,d;
	cin>>n>>k>>d;
	memset(dp,-1,sizeof dp);
	lli x=rs(n,k);
	memset(dp,-1,sizeof dp);
	lli y=rs(n,d-1);
	cout<<(x-y + mod)%mod<<endl;
}
// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define lbit(n) ((n) & -(n))
#define who(n) (__builtin_ctz(n))
#define Sub(a,b) (((a) & (b))==a)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,maxm=42;

int t[maxn],id[maxn],C;
string s[maxn];
map<string,int>mp;
set<int>st;

ll adj[maxm],And[1<<(maxm/2)];
bool gd1[1<<(maxm/2)],gd2[(1<<(maxm/2))];
int Max[1<<(maxm/2)];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>t[i];
	if(t[i]==2){
	    cin>>s[i];
	    if(mp.count(s[i])==0)
		mp[s[i]]=C++;
	    id[i]=mp[s[i]];
	}
    }
    for(int i=0;i<n;i++){
	if(t[i]==1) continue;
	st.clear();
	while(i<n && t[i]==2)
	    st.insert(id[i++]);
	for(int x:st)
	    for(int y:st)
		if(x!=y)
		    adj[x]|=(1ll<<y),adj[y]|=(1ll<<x);
    }
    for(int i=0;i<m;i++){
	adj[i]=(1ll<<m)-1-adj[i];
    }
    int m1=m/2,m2=m-m1;
    And[0]=(1ll<<m)-1;
    gd1[0]=gd2[0]=1;
    for(int i=1;i<(1<<m1);i++){
	And[i]=And[i ^ lbit(i)]&adj[who(lbit(i))];
	gd1[i]=Sub(i,And[i]);
    }
    for(int i=1;i<(1<<m2);i++){
	gd2[i]=gd2[i ^ lbit(i)] && Sub(i,adj[who(lbit(i))+m1]>>m1);
	Max[i]=gd2[i]?__builtin_popcount(i):0;
	for(int j=0;j<m2;j++)
	    if(bit(i,j))
		Max[i]=max(Max[i],Max[i ^ (1<<j)]);
    }
    int ans=0;
    for(int i=0;i<(1<<m1);i++){
	if(gd1[i]) ans=max(ans,__builtin_popcount(i)+Max[And[i]>>m1]);
    }
    return cout<<ans<<endl,0;
}
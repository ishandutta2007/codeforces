// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int p[maxn],pos[maxn];
vector<int>v[maxn];
bool is[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>p[i];
	pos[p[i]]=i;
    }
    for(int i=1;i<=m;i++){
	int a,b;cin>>a>>b;
	if(pos[a]<pos[b]){
	    v[a].PB(b);
	    v[b].PB(a);
	}
    }
    is[n]=1;
    int One=1;
    for(int i=n-1;i>=1;i--){
	int cnt=0;
	for(int y:v[p[i]]){
	    cnt+=is[pos[y]];
	}
	is[i]=cnt<One;
	One+=is[i];
    }
    return cout<<n-One<<endl,0;
}
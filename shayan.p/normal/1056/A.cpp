// Phoenix

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

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

bitset<maxn>a,b;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    for(int i=0;i<maxn;i++)
	a[i]=1;
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int m;cin>>m;
	b=0;
	for(int j=0;j<m;j++){
	    int x;cin>>x;
	    b[x]=1;
	}
	a&=b;
    }
    for(int i=0;i<maxn;i++)
	if(a[i])
	    cout<<i<<" ";
    cout<<endl;
    return 0;
}
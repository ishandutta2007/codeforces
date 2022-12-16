// Can U hack it?

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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

vector<int>ans;
int a[maxn],b[maxn];

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>b[i];
	a[i]=b[i]-(i==0?0:b[i-1]);
    }
    for(int i=1;i<=n;i++){
	bool yp=1;
	for(int j=i;j<n;j++)
	    if(a[j]!=a[j-i])
		yp=0;
	if(yp)
	    ans.PB(i);
    }
    cout<<sz(ans)<<endl;
    for(int x:ans)
	cout<<x<<" ";
    cout<<endl;
    return 0;
}
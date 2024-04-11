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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],mx,ans=-1;

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)
	cin>>a[i];
    for(int i=1;i<=n;i++){
	if(a[i]>mx){
	    ans=i;
	    break;
	}
	if(a[i]==mx){
	    mx++;
	}
    }
    cout<<ans<<endl;
    return 0;
}
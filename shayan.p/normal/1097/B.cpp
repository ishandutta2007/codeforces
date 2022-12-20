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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[20];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int msk=0;msk<(1<<n);msk++){
	int sm=0;
	for(int i=0;i<n;i++){
	    sm+=(bit(msk,i)?1:-1)*a[i];
	}
	if(sm%360==0){
	    return cout<<"YES\n",0;
	}
    }
    return cout<<"NO\n",0;
}
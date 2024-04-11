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

bool prime(int n){
    for(int i=2;(1ll*i*i)<=n;i++)
	if(n%i==0)return 0;
    return 1;
}

int main(){
    int n,ans=3;cin>>n;
    if(n&1){
	if(prime(n)) ans=1;
	else if(prime(n-2)) ans=2;
    }
    else{
	if(n==2) ans=1;
	else ans=2;
    }
    cout<<ans<<endl;
    return 0;
}
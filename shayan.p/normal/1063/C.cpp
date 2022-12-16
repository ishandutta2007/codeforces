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

bool ask(int x){
    cout<<x<<" "<<0<<endl;
    string s;cin>>s;
    return s=="white";
}

int main(){
    int n;cin>>n;
    int l=0,r=536870912;
    bool ch=ask(0)^1;
    for(int i=0;i<n-1;i++){
	int mid=(l+r)/2;
	if(ask(mid)^ch)
	    l=mid;
	else
	    r=mid;
    }
    if(r-l >1){
	int mid=(l+r)/2;
	cout<<mid<<" "<<0<<" "<<mid<<" "<<1<<endl;
    }
    else{
	cout<<r<<" "<<1<<" "<<(r+1)<<" "<<3<<endl;
    }
    return 0;
}
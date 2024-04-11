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

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

bool is(int x){
    for(int i=2;i*i<=x;i++)
	if(x%i==0)
	    return 0;
    return 1;
}

vector<int>vec;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=2;i<=n;i++)
	if(is(i))
	    vec.PB(i);
    for(int i=0;i<sz(vec)-1;i++){
	if(vec[i]+vec[i+1]<n)
	    k-=is(vec[i]+vec[i+1]+1);
    }
    cout<<(k<=0?"YES":"NO")<<endl;
}
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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn],b[maxn];
vector<ll>va,vb;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    if(a[n-1]!=b[n-1]) return cout<<"No\n",0;
    for(int i=0;i<n-1;i++){
	va.PB(a[i]-a[i+1]);
	vb.PB(b[i]-b[i+1]);
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    return cout<<(va==vb?"Yes\n":"No\n"),0;
}
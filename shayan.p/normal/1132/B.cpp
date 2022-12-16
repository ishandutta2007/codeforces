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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll sm=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	sm+=a[i];
    }
    sort(a,a+n);
    int m;cin>>m;
    for(int i=0;i<m;i++){
	int x;cin>>x;
	cout<<sm-a[n-x]<<" ";
    }
    return cout<<endl,0;
}
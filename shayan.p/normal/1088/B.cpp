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

const int maxn=1e5+10,inf=2e9;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)
	cin>>a[i];
    sort(a,a+n);
    int delta=0;
    for(int i=0;i<k;i++){
	int id=upper_bound(a,a+n,delta)-a;
	if(id==n) cout<<0<<"\n";
	else cout<<a[id]-delta<<"\n",delta=a[id];
    }
    return 0;
}
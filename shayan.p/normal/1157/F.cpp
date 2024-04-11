// Faster!

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int cnt[maxn],arr[maxn];
int l,r,tot,now,n;

void test(int a,int b){
    if(a>b) return;
    if(now>tot) tot=now,l=a,r=b;
}

void tell(){
    int ptl=0,ptr=tot;
    for(int i=l;i<=r;i++){
	for(int j=0;j<cnt[i]-1;j++)
	    arr[ptl++]=i;
	arr[--ptr]=i;
    }
    for(int i=0;i<tot;i++){
	cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	cnt[x]++;
    }
    int bef=0;
    for(int i=1;i<maxn;i++){
	now+=cnt[i];
	if(cnt[i]<2) test( bef+(cnt[bef]==0),i-(cnt[i]==0) ), bef=i, now=cnt[i];
    }
    return cout<<tot<<"\n",tell(),0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
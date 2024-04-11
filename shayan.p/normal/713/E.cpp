// High above the clouds there is a rainbow...

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

int a[maxn],n,m;

bool solve(int f,int s,int l,int r,int x){
    //    cout<<"HEYY "<<f<<" "<<s<<" "<<l<<" "<<r<<" "<<x<<endl;
    if(l>r || l>=m) return 1;
    if(f>s) return 0;
    while(f<=s && r<=a[s]){
	r=min(r,a[s]-x);
	s--;
    }
    while(f<=s){
	if(a[f]<=l){
	    l=max(l,a[f]+x);
	    f++;
	}
	else{
	    if(l<=a[f]-x) return 0;
	    if(f==s || l<=a[f+1]-x || a[f]+1==a[f+1]) l=a[f]+1,f++;
	    else l=a[f]+x, f+=2;
	}
    }
    return l>r;
}

bool prep(int x){
    int pt=0;
    while(pt<n && a[pt]<x) pt++;
    if(pt==0) return solve(0,n-1,x,m-1,x);
    else if(pt==1) return solve(1,n-1,a[0]+x,m-1,x) || solve(1,n-1,x,a[0]-x+m,x);
    else return solve(pt,n-1,a[pt-1]+x,a[0]-x+m,x);
}

bool ok(int x){
    if(prep(x)) return 1;
    for(int i=0;i<n;i++)
	a[i]=m-a[i];
    reverse(a,a+n);
    bool ans=prep(x);
    for(int i=0;i<n;i++)
	a[i]=m-a[i];
    reverse(a,a+n);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>m>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    sort(a,a+n);

    for(int i=n-1;i>=0;i--){
	a[i]-=a[0];
    }
    for(int i=1;i<n;i++){
	a[i-1]=a[i];
    }
    --n;

    int l=0,r=m;
    while(r-l>1){
	int mid=(l+r)>>1;
	if(ok(mid)) r=mid;
	else l=mid;	
    }
    return cout<<r-1<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
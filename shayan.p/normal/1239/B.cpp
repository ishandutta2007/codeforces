// Remember...

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

int a[maxn], b[maxn], bst1, bst2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    string s,ss; cin>>s;
    int sm=0, mnp=0, mn=10;
    for(int i=0;i<n;i++){
	b[i]= s[i]=='(' ? 1 : -1;
	sm+= b[i];
	if(mn>sm) mn=sm, mnp=i;
    }
    if(sm!=0) return cout<<0<<endl<<1<<" "<<1<<endl,0;
    ss=s;

    mnp=(mnp+1)%n;
    
    int pre=0, ans=0, L=0, R=0;
    
    for(int i=0;i<n;i++){
	a[i]= (i==0 ? 0 : a[i-1]) + b[(i+mnp)%n];
	s[i]= ss[(i+mnp)%n];
	ans+= a[i]==0;
	pre+= a[i]==0;
    }

    int bst1=-1, bst2=-1, pos1=-1, pos2=-1;

    for(int i=n-1;i>=0;i--){
	if(a[i]==0) bst1=-1, bst2=-1;
	if(a[i]==1) bst2=-1, bst1= bst1==-1 ? -1 : bst1+1;
	if(a[i]==2) bst2= bst2==-1 ? -1 : bst2+1;
	if(s[i]==')'){
	    if(bst1==-1) bst1=0, pos1=i;
	    if(bst2==-1) bst2=0, pos2=i;
	}
	else{
	    if(bst2!=-1 && ans<pre + bst2) ans=pre+bst2, L=i, R=pos2;
	    if(bst1!=-1 && ans<bst1) ans=bst1, L=i, R=pos1;
	}
    }
    return cout<<ans<<endl<<1+((L+mnp)%n)<<" "<<1+((R+mnp)%n)<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
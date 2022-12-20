// Jump, and you will find out how to unfold your wings as you fall.

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

int a[maxn],b[maxn],n,ln;
int sm[maxn];

inline int LB(int x){
    return (lower_bound(b,b+n,x)-b)%n;
}
bool ok(int x){
    memset(sm,0,sizeof sm);
    for(int i=0;i<n;i++){
	int L=LB((a[i]-x+ln)%ln),R=LB((x+a[i]+1)%ln);
	int num=(a[i]-b[L]+ln)%ln;
	num=min(num,ln-num);
	if(num>x) continue;
	if(L==R){ sm[0]++; continue;}
	L=(L-i+n)%n,R=(R-i+n)%n;
	if(L<=R) sm[L]++,sm[R]--;
	else sm[L]++,sm[0]++,sm[R]--;
    }
    int val=0;
    for(int i=0;i<n;i++){
	val+=sm[i];
	if(val==n) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>ln;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int l=0,r=ln/2;
    while(r-l>1){
	int mid=(l+r)>>1;
	if(ok(mid)) r=mid;
	else l=mid;
    }
    return cout<<r<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
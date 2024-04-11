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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,A=0,B=0;cin>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	if(x==1) A++;
	else B++;
    }
    if(B>0){
	cout<<2<<" ";
	B--;
    }
    if(A>0){
	cout<<1<<" ";
	A--;
    }
    while(B>0){
	cout<<2<<" ";
	B--;
    }
    while(A>0){
	cout<<1<<" ";
	A--;
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
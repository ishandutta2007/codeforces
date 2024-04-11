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

pii a[maxn],b[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    pii A={inf,inf},B={-inf,-inf};
    for(int i=0;i<n;i++)
	cin>>a[i].F>>a[i].S,A=min(A,a[i]);
    for(int i=0;i<n;i++)
	cin>>b[i].F>>b[i].S,B=max(B,b[i]);
    cout<<A.F+B.F<<" "<<A.S+B.S<<endl;
}
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

const int maxn=210,mod=1e9+7;
const ll inf=1e18;

bitset<maxn>bs[maxn];
bitset<maxn>tdo,tmp;
int n,m;

void check(){
    int spc=-1;
    for(int i=0;i<n;i++){
	tmp=bs[i] ^ tdo;
	int lst0=-1,lst1=-1;
	for(int j=0;j<m;j++){
	    if(tmp[j]==0 && lst0<lst1 && lst0!=-1) return;
	    if(tmp[j]==1 && lst1<lst0 && lst1!=-1) return;
	    if(tmp[j]==0) lst0=j;
	    if(tmp[j]==1) lst1=j;
	}
	if(lst0!=-1 && lst1!=-1){
	    if(spc!=-1) return;
	    spc=i;
	}
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
	if(i<=spc) cout<< (bs[i][0] ^ tdo[0]);
	else cout<< (1 ^ bs[i][0] ^ tdo[0]);
    }
    cout<<"\n";
    for(int i=0;i<m;i++){
	cout<<tdo[i];
    }
    cout<<"\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    bool x;cin>>x;
	    bs[i][j]=x;
	}
    }
    tdo=bs[0];
    check();
    bs[0].flip();
    tdo=bs[0];
    bs[0].flip();
    check();

    tdo=bs[n-1];
    check();
    bs[0].flip();
    tdo=bs[n-1];
    bs[0].flip();
    check();

    return cout<<"NO\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n;
int aft[26][20][maxn], bef[26][20][maxn], _bef[maxn][26], _aft[maxn][26], arr[26];
ll aftsm[26][maxn], befsm[26][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s; cin>>s;
    n=sz(s);

    for(int i=0;i<26;i++){
	arr[i]= i;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<26;j++)
	    _bef[i][j]= i==0 ? -1 : _bef[i-1][j];
	bef[0][0][i]= _bef[i][ s[i]-'a' ];
	_bef[i][ s[i]-'a' ]=i;	
    }
    for(int i=n-1;i>=0;i--){
	for(int j=0;j<26;j++)
	    _aft[i][j]= i==n-1 ? n : _aft[i+1][j];
	aft[0][0][i]= _aft[i][ s[i]-'a' ];
	_aft[i][ s[i]-'a' ]=i;
    }

    for(int i=0;i<n;i++){
	sort(arr,arr+26, [&](int x,int y){ return _bef[i][x] > _bef[i][y]; } );
	for(int j=1;j<26;j++)
	    aft[j][0][i]= max( aft[j-1][0][i], _bef[i][arr[j]]==-1 ? n : aft[0][0][ _bef[i][ arr[j] ] ] );
	sort(arr,arr+26, [&](int x,int y){ return _aft[i][x] < _aft[i][y]; } );
	for(int j=1;j<26;j++)
	    bef[j][0][i]= min( bef[j-1][0][i], _aft[i][arr[j]]==n ? -1 : bef[0][0][ _aft[i][ arr[j] ] ] );
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<26;j++){
	    for(int k=1;k<20;k++){
		bef[j][k][i]= bef[j][k-1][i];
		if(bef[j][k][i]>=0) bef[j][k][i]= bef[j][k-1][ bef[j][k-1][i] ];
	    }
	    befsm[j][i]= i + (bef[j][0][i]==-1 ? 0 : befsm[j][ bef[j][0][i] ]);
	}
    }
    for(int i=n-1;i>=0;i--){
	for(int j=0;j<26;j++){
	    for(int k=1;k<20;k++){
		aft[j][k][i]= aft[j][k-1][i];
		if(aft[j][k][i]<n) aft[j][k][i]= aft[j][k-1][ aft[j][k-1][i] ];
	    }
	    aftsm[j][i]= n-1-i + (aft[j][0][i]==n ? 0 : aftsm[j][ aft[j][0][i] ]);
	}
    }

    ll ans=0;
    
    for(int i=0;i<n;i++){
	int l=i,r=i;

	while(l>0 || r<n-1){
	    
	    int L=-1, R=n, cnt=-1;
	    for(int i=0;i<26;i++){
		if(_aft[l][i] > r)
		    L=max(L, _bef[l][i]), R=min(R, _aft[l][i]);
		else
		    cnt++;
	    }
	    ans+= befsm[cnt][l] + aftsm[cnt][r];
	    
	    int _l=l, _r=r;
	    int ml=0, mr=0;
	    for(int i=19;i>=0;i--){
		if(aft[cnt][i][_r]<R) _r= aft[cnt][i][_r], mr+=1<<i;
	    }
	    for(int i=19;i>=0;i--){
		if(bef[cnt][i][_l]>L) _l= bef[cnt][i][_l], ml+=1<<i;
	    }

	    int mv=max( ml,mr );
	    if(_l!=0) mv=min( mv,ml );
	    if(_r!=n-1) mv=min( mv,mr );

	    for(int i=19;i>=0;i--){
		if(bit(mv,i)){
		    l=max(0, bef[cnt][i][l]);
		    r=min(n-1, aft[cnt][i][r]);
		}
	    }
	    
	    l=max(0,bef[cnt][0][l]);
	    r=min(n-1,aft[cnt][0][r]);
	    ans-= befsm[cnt][l] + aftsm[cnt][r];
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
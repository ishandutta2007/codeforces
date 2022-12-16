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

char a[8]={'a','b','c','d','e','f','g','h'};
char b[8]={'1','2','3','4','5','6','7','8'};
int x=0,y=0;

string ans;

void add(){
    ans+=a[x];
    ans+=b[y];
    ans+=' ';
}
void nxt(){
    if(x==6 && y==6){
	x++;
	return;
    }
    if(x==7 && y==0){
	y=7;
	return;
    }    
    int Y=y + (x&1 ? -1 : 1);
    if(Y==-1 || Y==8){
	x++;
    }
    else{
	y=Y;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;

    add();
    
    if(n==63){
	while(x!=6)
	    nxt(), add();
	for(int i=7;i>=1;i--)
	    y=i, add();
	x=7, y=1, add();
	y=0, add();
	for(int i=2;i<=7;i++)
	    y=i, add();
    }
    else{
	for(int q=0;q<n;q++){
	    if(q+2 == n){
		if(x==7){
		    nxt(), add();
		    y=7, add();
		}
		else{
		    if(y==7){
			x=6, add();
			x=7, add();
		    }
		    else{
			x=7, add();
			y=7, add();
		    }
		}
		break;
	    }
	    else{
		nxt(), add();
	    }
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
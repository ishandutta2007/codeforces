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

const int maxn=55,mod=1e9+7;
const ll inf=1e18;

char s[maxn][maxn];
vector<pii>v,ans;

void move1(int x,int y){
    v.PB({x+1,y+1});
    if(s[x][y]=='L') s[x][y]=s[x][y+1]='U',s[x+1][y]=s[x+1][y+1]='D';
    else s[x][y]=s[x+1][y]='L',s[x][y+1]=s[x+1][y+1]='R';
}
void move2(int x,int y){
    if(s[x][y]=='L'){
	if(s[x+1][y]=='L')
	    move1(x,y);
	else
	    move2(x+1,y),move1(x,y);
    }
    else{
	if(s[x][y+1]=='U')
	    move1(x,y);
	else
	    move2(x,y+1),move1(x,y);
    }
}

void solve(int n,int m){
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    if(n&1){
	for(int i=0;i<m;i+=2){
	    for(int j=0;j<n;j++){
		if(s[j][i]=='U')
		    move2(j,i);
	    }
	}
    }
    else{
	for(int i=0;i<n;i+=2){
	    for(int j=0;j<m;j++){
		if(s[i][j]=='L')
		    move2(i,j);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    solve(n,m);
    ans=v,v.clear();
    solve(n,m);
    reverse(v.begin(),v.end());
    for(pii p:v)
	ans.PB(p);
    cout<<sz(ans)<<"\n";
    for(pii p:ans)
	cout<<p.F<<" "<<p.S<<"\n";
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
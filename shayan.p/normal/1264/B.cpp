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

int a[2][4], cop[2][4];
int c[6][6];

vector<int> ans;

void go(int u){
    int tmp=u;
    vector<int> vec;
    while(true){
	int fnd=-1;
	for(int i=0;i<6;i++)
	    if(c[tmp][i]!=0)
		fnd=i;
	if(fnd==-1) break;
	c[tmp][fnd]--, tmp=fnd, vec.PB(fnd);
    }
    for(int x:vec){
	ans.PB(x), go(x);
    }
}

void print(int s,int e){
    //    cout<<"SALAM "<<s<<" "<<e<<endl;
    c[4][s]=1, c[e][5]=1;
    for(int i=0;i<3;i++){
	c[i][i+1] = a[1][i];
	c[i+1][i] = a[0][i];
	//	cout<<c[i][i+1]<<"   "<<c[i+1][i]<<endl;
    }
    go(4);
    ans.pop_back();
    for(int x:ans)
	cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i=0;i<4;i++)
	cin>>a[0][i], a[1][i] = a[0][i];
    for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	    if(a[0][i]==0 || a[1][j]==0) continue;
	    
	    memcpy(cop, a, sizeof a);
	    a[0][i]--, a[1][j]--;
	    
	    int tot=1, stil=0;
	    bool ok=1;
	    
	    for(int k=0;k<3;k++){
		a[0][k+1]-= a[1][k];
		a[1][k+1]-= a[0][k];
		tot+= a[0][k] + a[1][k];
		ok&= a[0][k]>=0 && a[1][k]>=0;
	    }
	    ok&= a[0][3]==0 && a[1][3]==0;
	    for(int k=0;k<3;k++){
		stil+= i==k;
		if(a[0][k] == 0 && a[1][k]==0 && ( ((i<=k) ^ (j<=k) ) || (stil!=0 && stil!=tot) ) )
		    ok=0;
		stil+= a[0][k] + a[1][k];
	    }
	    if(ok){
		cout<<"YES\n";
		print(i,j);
		return 0;
	    }
	    memcpy(a, cop, sizeof a);
	}
    }
    return cout<<"NO\n",0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
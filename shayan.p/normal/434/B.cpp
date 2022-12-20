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

const int maxn=1010;

set<int>stx[maxn],sty[maxn];
vector<int>bl;
bool a[maxn][maxn];
int bef[maxn],aft[maxn];

int solve(int pos){
    bef[0]=-1;
    for(int i=1;i<sz(bl);i++){
	bef[i]=i-1;
	while(bef[i]>=0 && bl[bef[i]]>=bl[i])
	    bef[i]=bef[bef[i]];
    }
    aft[sz(bl)-1]=sz(bl);
    for(int i=sz(bl)-2;i>=0;i--){
	aft[i]=i+1;
	while(aft[i]<sz(bl) && bl[aft[i]]>=bl[i])
	    aft[i]=aft[aft[i]];
    }
    int ans=0;
    for(int i=0;i<sz(bl);i++){
	if(bef[i]<pos && pos<aft[i]){
	    ans=max(ans,(aft[i]-bef[i]-1)*bl[i]);
	}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cin>>a[i][j];
	    if(!a[i][j]){
		stx[i].insert(j);
		sty[j].insert(i);
	    }
	}
    }
    for(int i=0;i<n;i++){
	stx[i].insert(-1);
	stx[i].insert(m);
    }
    for(int j=0;j<m;j++){
	sty[j].insert(-1);
	sty[j].insert(n);
    }
    
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int A,B;cin>>A>>B;
	    if(a[--A][--B]) stx[A].insert(B),sty[B].insert(A);
	    else stx[A].erase(B),sty[B].erase(A);
	    a[A][B]^=1;
	}
	else{
	    int A,B,ans=0;cin>>A>>B;--A;--B;
	    
	    bl.clear();
	    for(int j=0;j<m;j++)
		bl.PB((*sty[j].lower_bound(A)) - A);
	    ans=max(ans,solve(B));
       	    bl.clear();
	    for(int j=0;j<m;j++)
		bl.PB(A-(*(--sty[j].upper_bound(A))));
	    ans=max(ans,solve(B));

	    bl.clear();
	    for(int i=0;i<n;i++)
		bl.PB((*stx[i].lower_bound(B)) - B);
	    ans=max(ans,solve(A));

	    bl.clear();
	    for(int i=0;i<n;i++)
		bl.PB(B- (*(--stx[i].upper_bound(B))) );
	    ans=max(ans,solve(A));
	    cout<<ans<<"\n";
	}
    }
}
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

const int maxn=2e5+10;

int x[maxn],y[maxn];
bool ans[maxn];
set<int>sx[maxn],sy[maxn];

void go(int e,bool who=0){
    int X=x[e],Y=y[e];
    sx[X].erase(e);
    sy[Y].erase(e);
    ans[e]=who;
    if(who==0 && sz(sy[Y])) go(*sy[Y].begin(),!who);
    if(who==1 && sz(sx[X])) go(*sx[X].begin(),!who);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>x[i]>>y[i];
	sx[x[i]].insert(i);
	sy[y[i]].insert(i);
    }
    for(int i=0;i<maxn;i++){
	if(sz(sx[i])&1)
	    go(*sx[i].begin());
    }
    for(int i=0;i<maxn;i++){
	if(sz(sy[i])&1)
	    go(*sy[i].begin(),1);
    }
    for(int i=0;i<maxn;i++){
	if(sz(sx[i]))
	    go(*sx[i].begin());
    }
    for(int i=0;i<n;i++){
	cout<<char(ans[i]?'b':'r');
    }
    return cout<<endl,0;
}
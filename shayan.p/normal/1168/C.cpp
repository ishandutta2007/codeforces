// High above the clouds there is a rainbow...

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

const int maxn=3e5+10,inf=1e8;

struct STR{
    int frs[20];
    STR(){
	for(int i=0;i<20;i++)
	    frs[i]=inf;
    }
};
void f(STR &a,STR &b){
    for(int i=0;i<20;i++)
	a.frs[i]=min(a.frs[i],b.frs[i]);
}

STR val[maxn],upd[20];
int a[maxn];

bool check(int id1,int id2){
    for(int i=0;i<20;i++){
	if(bit(a[id2],i) && val[id1].frs[i]<=id2) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
	for(int j=0;j<20;j++){
	    if(bit(a[i],j)) val[i].frs[j]=i;
	}
	for(int j=0;j<20;j++){
	    if(bit(a[i],j)) f(val[i],upd[j]);
	}
	for(int j=0;j<20;j++){
	    if(bit(a[i],j)) f(upd[j],val[i]);
	}
    }
    while(q--){
	int a,b;cin>>a>>b; --a,--b;
	if(check(a,b)) cout<<"Shi\n";
	else cout<<"Fou\n";
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
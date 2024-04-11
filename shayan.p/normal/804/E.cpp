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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

void swap1(int a,int b,int till){
    for(int i=1;i<=till;i++){
	cout<<i<<" "<<a<<"\n";
    }
    cout<<a<<" "<<b<<"\n";
    for(int i=till;i>=1;i--){
	cout<<i<<" "<<b<<"\n";
    }
}
void swap2(int a,int b){
    cout<<a<<" "<<b<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    if(n%4!=1 && n%4!=0) return cout<<"NO\n",0;
    cout<<"YES\n";
    while(n>=4){
	swap1(n-3,n-2,n-4);
	swap2(n-3,n-1);
	swap2(n-2,n  );
	swap2(n-3,n  );
	swap2(n-2,n-1);
	swap1(n-1,n  ,n-4);
	n-=4;
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.

/*
1 2
1 3
2 4
1 4
2 3
3 4
*/
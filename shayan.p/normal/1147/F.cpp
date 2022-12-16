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

const int maxn=55,mod=1e9+7,inf=1e9;

vector<pii> v[maxn];
int a[maxn][maxn], A, B, arr[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;
    while(q--){
	int n; cin>>n;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		cin>>a[i][j];
	cout<<"B"<<endl;
	char ch; cin>>ch;
	if(ch=='I'){
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		    a[i][j]= n*n+1 - a[i][j];
	}
	int x; cin>>x;
	B=(x>n ? 1 : n+1);
	A=(x>n ? -n-1 : -1);

	if(x>n)
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		    if(i<j)
			swap(a[i][j], a[j][i]);
	x+=A;
	for(int i=0;i<n;i++)
	    v[i].clear();
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		v[i].PB({a[i][j],j});
	for(int i=0;i<n;i++)
	    sort(v[i].begin(), v[i].end());
	while(true){
	    int CNT=0;
	    fill(arr,arr+n,inf);
	    for(int i=0;i<n;i++)
		arr[v[i].back().S]= min( arr[v[i].back().S], v[i].back().F );
	    for(int i=0;i<n;i++)
		if(arr[v[i].back().S] < v[i].back().F)
		    CNT++, v[i].pop_back();
	    if(CNT==0) break;
	}

	while(true){
	    cout<<B+v[x].back().S<<endl;
	    cin>>x;
	    if(x==-1) break;
	    x+=A;	    
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
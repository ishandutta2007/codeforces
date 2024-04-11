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
typedef pair<ll,int> pli;

const int maxn=210 ,mod=1e9+7;
const ll inf=3e18;

vector<int> v[maxn], v1, v2;

int n, SZ[maxn];
bool rt[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

  //  srand(time(0));
    
    while(q--){
	cin>>n;

	for(int i=0;i<2*n;i++){
	    v[i].clear();
	}
	for(int i=0;i<2*n;i++){
	    SZ[i]=1;
	    rt[i]=1;		    
	}

	int del=0;
	
	while(del<n){
	    v1.clear(), v2.clear();
	    for(int i=0;i<2*n;i++){
		if(rt[i]==0) continue;
		if(SZ[i]==1)
		    v1.PB(i);
		if(SZ[i]>1)
		    v2.PB(i);
	    }
	//    random_shuffle(v1.begin(), v1.end());
	//    random_shuffle(v2.begin(), v2.end());
	    
	    int A=-1, B=-1;
	    if(sz(v1)>1){
		A=v1[0], B=v1[1];
	    }
	    if(sz(v2)>1){
		A=v2[0], B=v2[1];
	    }
	    
	    if(A==-1){
		A=v1[0], B=v2[0];
	    }
	    
	    cout<<"? "<<A+1<<" "<<B+1<<endl;
	    char ch; cin>>ch;
	    if(ch=='<'){
		v[A].PB(B);
		rt[B]=0;
		SZ[A]+=SZ[B];
		if(SZ[A]>n){
		    del++;
		    rt[A]=0;
		    for(int x:v[A])
			rt[x]=1;
		}		
	    }
	    else{
		v[B].PB(A);
		rt[A]=0;
		SZ[B]+=SZ[A];
		if(SZ[B]>n){
		    del++;
		    rt[B]=0;
		    for(int x:v[B])
			rt[x]=1;
		}
	    }
	}
	cout<<"!"<<endl;
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
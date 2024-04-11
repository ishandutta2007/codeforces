// Mikaeel_noob_e_sag_e

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

const int maxn=13e5;

bitset<maxn>A,B,C;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x;cin>>n>>x;
    if(x==2) return cout<<0<<endl,0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1) return cout<<1<<endl,0;
    }
    if(x>=maxn) return cout<<-1<<endl,0;
    while(n--){
	if(a[n]<x) B[a[n]]=1;
    }
    for(int i=2;i<x;i++){
	if(A[i]==0){
	    C[i]=1;
	    for(int j=i;j<x;j+=i)
		A[j]=1;
	}
    }
    if((C&B) != C) return cout<<-1<<endl,0;
    return cout<<C.count()<<endl,0;
}
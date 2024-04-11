// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,Max=4000,mod=1e9+7;
const ll inf=1e18;

int a[maxn];
vector<int>vec;
bool pr[maxn];

map<int,int>mp;

int main(){
    for(int i=2;i<Max;i++){
	if(!pr[i]){
	    vec.PB(i);
	    for(int j=i*i;j<Max;j+=i)
		pr[j]=1;
	}
    }
    int n;scanf("%d",&n);
    FOR(i,1,n){
	scanf("%d",&a[i]);
    }
    int ans=n;
    for(int p:vec){
	int A=-1,B=0;
	FOR(i,1,n){
	    int cnt=0;
	    while(a[i]%p==0){
		cnt++;
		a[i]/=p;
	    }
	    if(A==-1){
		A=cnt;
		B=0;
	    }
	    if(A>cnt){
		A=cnt;
		B=0;
	    }
	    if(A==cnt){
		B++;
	    }
	}
	ans=min(ans,B);
    }
    FOR(i,1,n){
	if(a[i]>1)
	    mp[a[i]]++;
    }
    for(pii p:mp){
	if(p.S<n)
	    ans=min(ans,n-p.S);
    }
    if(ans==n)
	ans=-1;
    printf("%d\n",ans);
}
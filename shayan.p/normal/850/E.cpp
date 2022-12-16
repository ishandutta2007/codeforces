// Can U hack it?

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

const int maxn=15e5,mod=1e9+7,modi=5e8+4;

string s;
vector<int>v[2];
int n;

int arr1[maxn],arr2[maxn];

void transform(int *l,int *r,bool rev){
    if(r-l==1)return;
    int *mid=l+(r-l)/2;
    transform(l,mid,rev);
    transform(mid,r,rev);
    for(int i=0;i<(mid-l);i++){
	int A=*(l+i),B=*(mid+i);
	if(rev){
	    *(l+i)=1ll*(A+B)*modi  %mod;
	    *(mid+i)=1ll*(A-B)*modi %mod;
	}
	else{	
	    *(l+i)=(A+B)%mod;
	    *(mid+i)=(A-B)%mod;
	}
    }
}

int solve(int a,int b){
    memset(arr1,0,sizeof arr1);
    memset(arr2,0,sizeof arr2);
    int N=(1<<n);
    for(int i=0;i<(N/2);i++)
	++arr1[v[a][i]],++arr2[v[b][i]];
    transform(arr1,arr1+N,0);
    transform(arr2,arr2+N,0);
    for(int i=0;i<N;i++)
	arr1[i]=(1ll*arr1[i]*arr2[i])%mod;
    transform(arr1,arr1+N,1);
    int bt=a^b,ans=0;
    for(int i=0;i<N;i++){
	int c=__builtin_popcount(i);
	if(!bt) c=n-c;
	ans=(ans+1ll*arr1[i]*(1<<c))%mod;
    }
    return ans;
}

int main(){
    cin>>n>>s;
    for(int i=0;i<sz(s);i++)
	v[(s[i]-'0')].PB(i);
    ll ans=(1ll*solve(1,1)+solve(0,1)+solve(0,0))%mod;
    cout<<ans<<endl;
}
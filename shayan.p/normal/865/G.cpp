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

const int maxn=251,mod=1e9+7;

int a[maxn],MD[maxn],P[maxn],arr[maxn];

void Mul(int *arr1,int *arr2){
    int arr3[2*maxn];
    memset(arr3,0,sizeof arr3);
    for(int i=0;i<maxn;i++)
	for(int j=0;j<maxn;j++)
	    arr3[i+j]=(1ll*arr1[i]*arr2[j]+arr3[i+j])%mod;
    for(int i=2*maxn-1;i>=maxn;i--)
	for(int j=0;j<maxn;j++)
	    arr3[i-(maxn-j)]=(1ll*arr3[i]*MD[j]+arr3[i-(maxn-j)])%mod;
    for(int i=0;i<maxn;i++)
	arr1[i]=arr3[i];
}

void Add(int *arr1,int *arr2){
    for(int i=0;i<maxn;i++)
	arr1[i]=(arr1[i]+arr2[i])%mod;
}

void Pow(int *arr,ll x){
    int ans[maxn];
    memset(ans,0,sizeof ans);
    ans[0]=1;
    while(x){
	if(x&1) Mul(ans,arr);
	Mul(arr,arr);
	x>>=1;
    }
    for(int i=0;i<maxn;i++)
	arr[i]=ans[i];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    ll N;
    cin>>n>>m>>N;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<m;i++){
	int x;cin>>x;
	MD[maxn-x]++;
    }
    for(int i=0;i<n;i++){
	memset(arr,0,sizeof arr);
	arr[1]=1;
	Pow(arr,a[i]);
	Add(P,arr);
    }
    Pow(P,N);
    memset(arr,0,sizeof arr);
    arr[maxn-1]=1;
    Mul(P,arr);
    cout<<P[maxn-1]<<endl;
    return 0;
}
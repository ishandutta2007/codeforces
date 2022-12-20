// Wanna Hack? GL...

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

const int maxn=1e6+10,mod=1e9+7,Big=1e9+3;
const ll inf=1e18;

vector<int>v;
int arr[maxn];

int Q1(int id){
    cout<<"? "<<id+1<<endl;
    int num;cin>>num;
    if(num==-1) cout<<1/0<<endl;
    return num;
}
bool Q2(int num){
    cout<<"> "<<num<<endl;
    int x;cin>>x;
    if(x==-1) cout<<1/0<<endl;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
    int n;cin>>n;
    int l=0,r=Big,cnt=58;
    while(l<r){
	--cnt;
	int mid=(l+r)>>1;
	if(Q2(mid)==0) r=mid;
	else l=mid+1;
    }
    int mx=l;
    cnt=min(cnt,n);
    for(int i=0;i<n;i++){
	arr[i]=i;
    }
    shuffle(arr,arr+n,rng);
    for(int i=0;i<cnt;i++){
	v.PB(Q1(arr[i]));
    }
    sort(v.begin(),v.end());
    int d=v[1]-v[0];
    for(int i=2;i<sz(v);i++){
	d=__gcd(d,v[i]-v[i-1]);
    }
    int start=mx-d*(n-1);
    return cout<<"! "<<start<<" "<<d<<endl,0;
}
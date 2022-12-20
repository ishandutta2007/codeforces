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

const int maxn=1e5+10;

vector<int>ones,Val[maxn],vec;
int a[maxn];

int Pow(int a,int b,int md){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %md;
	a=1ll*a*a %md;
	b>>=1;
    }
    return ans;
}

int phi(int num){
    if(num==1) return 1;
    int ans=num;
    for(int i=2;i*i<=num;i++){
	if(num%i==0){
	    while(num%i==0) num/=i;
	    ans/=i;ans*=(i-1);
	}
    }
    if(num>1) ans/=num,ans*=num-1;
    return ans;
}

int calc(int l,int r,int pos=0){
    if(pos==sz(vec)-1) return 0;
    if(l==r) return 1;
    if(l+1==r) return a[l]%vec[pos];
    if(r-sz(Val[r-1])<=l+1) return Pow(a[l],Val[r-1][r-1-(l+1)],vec[pos]);
    return Pow(a[l],vec[pos+1]+calc(l+1,r,pos+1),vec[pos]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1){
	    ones.PB(i);
	    continue;
	}
	Val[i].PB(a[i]);
	for(int j=i-1;j>=0 && a[j]!=1;j--){
	    int A=Pow(a[j],Val[i].back(),1e9+7),B=Pow(a[j],Val[i].back(),1e9+9);
	    if(A!=B) break;
	    Val[i].PB(A);
	}
    }
    vec.PB(m);
    while(m>1)
	vec.PB(m=phi(m));
    int q;cin>>q;
    while(q--){
	int l,r;cin>>l>>r;
	auto it=lower_bound(ones.begin(),ones.end(),--l);
	if(it!=ones.end()) r=min(r,*it);
	cout<<calc(l,r)<<"\n";
    }
}
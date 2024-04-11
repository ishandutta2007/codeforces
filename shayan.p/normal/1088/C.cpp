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

const int maxn=1e5+10,Big=1e5;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int delta=0;
    for(int i=1;i<=n;i++)
	cin>>a[i];
    cout<<n+1<<endl;
    for(int i=n;i>=1;i--){
	a[i]=(i-a[i]-delta)%Big;
	a[i]=(a[i]+Big)%Big;
	delta=(delta+a[i])%Big;
	cout<<"1 "<<i<<" "<<a[i]<<"\n";
    }
    cout<<"2 "<<n<<" "<<Big<<endl;
    return 0;
}
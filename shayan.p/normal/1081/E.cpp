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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll ans[2*maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,bf=0;cin>>n;
    for(int i=0;i<n/2;i++){
	int x;cin>>x;
	int aa=-1,bb=-1;
	for(int j=1;j*j<=x;j++){
	    if(x%j==0){
		int A=j,B=x/j;
		if((A&1)!=(B&1)) continue;
		if(A>B) swap(A,B);
		int AA=(B-A)/2,BB=(A+B)/2;
		if(bf<AA){
		    if(aa==-1 || BB<bb){
			aa=AA;
			bb=BB;
		    }
		}
	    }
	}
	ans[2*i]=1ll*aa*aa-1ll*bf*bf;
	ans[2*i+1]=x;
	if(aa==-1)
	    return cout<<"No\n",0;
	bf=bb;
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
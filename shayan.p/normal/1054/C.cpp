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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

int a[maxn],b[maxn],ans[maxn];;
int mark[maxn];
int nw;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<n;i++)
	cin>>b[i];
    int CNT=n;
    while(CNT){
	int bf=CNT;
	int c=0;
	for(int i=0;i<n;i++){
	    if(mark[i]==0 && a[i]==0 && b[i]==0)
		c++,mark[i]=2;
	    else
		a[i]-=c;
	}
	c=0;
	for(int i=n-1;i>=0;i--){
	    if(mark[i]==2 && a[i]==0 && b[i]==0)
		c++,ans[i]=nw,mark[i]=1,CNT--;
	    else
		b[i]-=c;
	}
	if(CNT==bf){
	    cout<<"NO\n";
	    return 0;
	}
	nw--;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
	cout<<(ans[i]-nw)<<" ";
    cout<<endl;
    return 0;
}
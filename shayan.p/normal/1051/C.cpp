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

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

int a[maxn],cnt[maxn],ans[maxn],CNT;

int main(){
    int n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
	cnt[a[i]]++;
    }
    FOR(i,1,100){
	if(cnt[i]==1)
	    CNT++;
    }
    if(CNT&1){
	bool yp=0;
	FOR(i,1,100){
	    if(cnt[i]>2){
		int lst=0;
		FOR(j,1,n){
		    if(a[j]==i){
			lst=j;
			ans[j]=1;
		    }
		}
		ans[lst]=2;
		yp=1;
		break;
	    }
	}
	if(!yp){
	    cout<<"NO\n";
	    return 0;
	}
    }
    cout<<"YES\n";
    int nw=0;
    FOR(i,1,n){
	if(ans[i]==0){
	    if(cnt[a[i]]>1){
		ans[i]=1;
	    }
	    else if(nw&1){
		ans[i]=2;
		nw++;
	    }
	    else{
		ans[i]=1;
		nw++;
	    }
	}
    }
    FOR(i,1,n){
	cout<<(ans[i]==1?'A':'B');
    }
}
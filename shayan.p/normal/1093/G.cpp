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

const int maxn=2e5+10,mod=1e9+7,inf=1e9;

int n,k;
int arr[5];
int val[2*maxn][32];

void add(int id){
    id+=n;
    val[id][0]=0;
    for(int i=0;i<k;i++)
	val[id][0]+=arr[i];
    for(int msk=1;msk<(1<<k);msk++){
	int M=msk & -msk,pos=__builtin_ctz(M);
	val[id][msk]=val[id][msk^M]-2*arr[pos];
    }
    id>>=1;
    while(id>0){
	for(int msk=0;msk<(1<<k);msk++)
	    val[id][msk]=max(val[2*id][msk],val[2*id+1][msk]);
	id>>=1;
    }
}

int ask(int f,int s,int msk){
    f+=n;s+=n;
    int ans=-inf;
    while(f<s){
	if(f&1) ans=max(ans,val[f++][msk]);//,cout<<"HEY "<<val[f-1][msk]<<"      "<<f-1<<"   "<<msk<<endl;;
	if(s&1) ans=max(ans,val[--s][msk]);//,cout<<"HEY "<<val[s][msk]<<"          "<<s<<"    "<<msk<<endl;;
	f>>=1;s>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<2*maxn;i++)
	for(int j=0;j<32;j++)
	    val[i][j]=-inf;
    cin>>n>>k;
    for(int i=0;i<n;i++){
	for(int j=0;j<k;j++)
	    cin>>arr[j];
	add(i);
    }
    int q;cin>>q;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int id;cin>>id;
	    for(int i=0;i<k;i++)
		cin>>arr[i];
	    add(--id);
	}
	else{
	    int f,s,ans=-inf;cin>>f>>s;
	    --f;
	    for(int msk=0;msk<(1<<k);msk++){
		ans=max(ans,ask(f,s,msk)+ask(f,s,(1<<k)-1-msk));
	    }
	    cout<<ans<<"\n";
	}
    }
    return 0;
}
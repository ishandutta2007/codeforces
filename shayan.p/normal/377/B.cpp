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

int ans[maxn],n,m,s,pt;
pii p[maxn];
pair<pii,int> p2[maxn];

priority_queue<pii,vector<pii>,greater<pii> > pq;

void open(int num){
    while(pt>=0 && num<=p2[pt].F.F) pq.push({p2[pt].F.S,p2[pt].S}),--pt;
}

void init(){
    while(!pq.empty()) pq.pop();
    pt=n-1;
}

bool check(int len){
    init();
    open(p[m-1].F);
    int sm=0;
    for(int i=m-1;i>=0;i--){
	if(pq.empty() || (sm=sm+pq.top().F)>s) return 0;
	int id=pq.top().S;
	pq.pop();
	int fix=i-len;
	while(i>max(fix,-1)){
	    ans[p[i].S]=id;
	    if(i>0) open(p[i-1].F);
	    --i;
	}
	++i;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
	cin>>p[i].F,p[i].S=i;
    for(int i=0;i<n;i++)
	cin>>p2[i].F.F;
    for(int i=0;i<n;i++)
	cin>>p2[i].F.S,p2[i].S=i;
    sort(p,p+m);
    sort(p2,p2+n);
    int l=1,r=m,ANS=m+1;
    while(l<=r){
	int mid=(l+r)>>1;
	if(check(mid))
	    ANS=mid,r=mid-1;
	else
	    l=mid+1;
    }
    if(ANS==m+1) return cout<<"NO\n",0;
    check(ANS);
    cout<<"YES\n";
    for(int i=0;i<m;i++)
	cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}
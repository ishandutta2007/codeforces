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
typedef vector<int> vii;

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn],b[maxn],n;
vii EMP;
pair<vii,vii> val[4*maxn];

ll f(int id,bool is){
    return b[id]+(is?-1:1)*a[id];
}

vii Merge(vii &a,vii &b,bool bl){
    vii ans=a;
    for(int id:b)
	ans.PB(id);
    for(int i=1;i<sz(ans);i++){
	if(f(ans[i],bl)>f(ans[0],bl))
	    swap(ans[0],ans[i]);
    }
    for(int i=2;i<sz(ans);i++){
	if(f(ans[i],bl)>f(ans[1],bl))
	    swap(ans[1],ans[i]);
    }
    while(sz(ans)>2) ans.pop_back();
    return ans;
}

void build(int l,int r,int id){
    //    cout<<l<<" "<<r<<" "<<id<<endl;
    if(l==r){
	val[id].F.PB(l);
	val[id].S.PB(l);
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    //    cout<<"WANNA MERGE "<<l<<" "<<mid<<"    "<<mid+1<<" "<<r<<endl;
    val[id]={Merge(val[2*id].F,val[2*id+1].F,0),Merge(val[2*id].S,val[2*id+1].S,1)};
}

pair<vii,vii> ask(int f,int s,int l=0,int r=2*n-1,int id=1){
    if(l>r || f>s || s<l || r<f) return {EMP,EMP};
    if(f<=l && r<=s) return val[id];
    int mid=(l+r)/2;
    pair<vii,vii> p1=ask(f,s,l,mid,2*id);
    pair<vii,vii> p2=ask(f,s,mid+1,r,2*id+1);
    return {Merge(p1.F,p2.F,0),Merge(p1.S,p2.S,1)};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m;cin>>n>>m;
    for(int i=1;i<=n;i++)
	cin>>a[i],a[i+n]=a[i];
    for(int i=0;i<n;i++)
	cin>>b[i],b[i]=b[i+n]=2*b[i];
    for(int i=1;i<2*n;i++)
	a[i]+=a[i-1];
    build(0,2*n-1,1);
    while(m--){
	int A,B,x,y;cin>>A>>B;
	A--;B--;
	if(A<=B)
	    x=B+1,y=A+n-1;
	else
	    x=B+1,y=A-1;
	pair<vii,vii> vv=ask(x,y);
	vii vec1=vv.F,vec2=vv.S;
	ll ans=0;
	for(int id1:vec1)
	    for(int id2:vec2)
		if(id1!=id2)
		    ans=max(ans,a[id1]-a[id2]+b[id1]+b[id2]);
	cout<<ans<<"\n";
    }
    return 0;
}
// High above the clouds there is a rainbow...

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

const int maxn=1e5+70,Max=70 * maxn,P=1e6+3,mod=1e9+7;////////// alert! do ta mod yekian
const ll inf=1e18;

int C,pw[maxn],prhsh[maxn],L[Max],R[Max],cnt[Max],hsh[Max];

int numb[maxn];

int Set(int f,int s,bool x,int id,int l=0,int r=maxn){
    if(s<=l || r<=f) return id;
    if(f<=l && r<=s) return x;
    int nw=C++, mid=(l+r)>>1;
    L[nw]= Set(f, s, x, L[id], l, mid);
    R[nw]= Set(f, s, x, R[id], mid, r);
    int A=hsh[ L[nw] ], B=hsh[ R[nw] ], C=cnt[ L[nw] ], D=cnt[ R[nw] ];
    if( L[nw]==0 ) A=0, C=0;
    if( L[nw]==1 ) A=prhsh[mid-l], C=mid-l;
    if( R[nw]==0 ) B=0, D=0;
    if( R[nw]==1 ) B=prhsh[r-mid], D=r-mid;
    
    hsh[nw]= ( 1ll*A*pw[r-mid] + 1ll*B )%mod;
    cnt[nw]= C+D;
    return nw;
}
int Fnd(int pos,int id,int l=0,int r=maxn){
    if(r<=pos) assert(0);
    if( id==0 || cnt[id]==0  ) return max(pos,l);
    if( id==1 || cnt[id]==r-l) return r;
    if(r-l==1) assert(0);
    int mid=(l+r)>>1;
    if(mid<=pos) return Fnd(pos, R[id], mid, r);
    int num= Fnd(pos, L[id], l, mid);
    if(num!=mid) return num;
    return Fnd(pos, R[id], mid, r);
}
int Dif(int id1,int id2,int l=0,int r=maxn){
    int A= hsh[id1], B=hsh[id2];
    if( id1==0 ) A=0;
    if( id1==1 ) A=prhsh[r-l];
    if( id2==0 ) B=0;
    if( id2==1 ) B=prhsh[r-l];

    if(A==B) return l;
    if(r-l==1) return r;
    
    int mid=(l+r)>>1;

    int num= Dif( R[id1], R[id2], mid, r );
    if(num!=mid) return num;
    return Dif( L[id1], L[id2], l, mid );
}
bool What(int pos,int id,int l=0,int r=maxn){
    if(r-l==1) return cnt[id];// mentioning 0,1
    int mid=(l+r)>>1;
    if(pos<mid) return What(pos, L[id], l, mid);
    return What(pos, R[id], mid, r);
}
bool Cmp(int rt1,int rt2){
    int pos= Dif(rt1, rt2) - 1;
    if(pos==-1) return 0;
    return What(pos, rt1) < What(pos, rt2);
}

int Add(int rt1,int pos){
    int pos2=Fnd(pos,rt1);    
    int id=Set(pos, pos2, 0, rt1);
    return Set(pos2 ,pos2+1, 1, id);
}

struct cmp{// cmp pq barakse! ajab giri kardima
    bool operator () (pii a,pii b){
	return !Cmp(a.S,b.S);
    }
};

priority_queue<pii,vector<pii>,cmp> pq;

vector<pii>v[maxn];

bool done[maxn];

int par[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
#ifdef shayan
    freopen("in","r",stdin);
#endif

    pw[0]=1;
    for(int i=1;i<maxn;i++){
	pw[i]= 1ll *pw[i-1] * P %mod;
	prhsh[i]= (1ll*prhsh[i-1] * P + 1 )%mod;
    }
    L[0]=R[0]=cnt[0]=0, L[1]=R[1]=cnt[1]=1, C=2;

    int n,m; cin>>n>>m;
    while(m--){
	int a,b,c; cin>>a>>b>>c;
	v[--a].PB({--b,c});
	v[b].PB({a,c});
    }

    int s,t; cin>>s>>t; s--, t--;
    
    for(int i=0;i<n;i++)
	numb[i]=1;
    
    numb[s]=0, pq.push({s,0});

    while(sz(pq)){
	int u=pq.top().F;
      
	pq.pop();
	
	if(done[u]==1) continue;
	done[u]=1;

	for(pii p:v[u]){
	    int y=p.F;
	    int num= Add( numb[u], p.S);
	    if( Cmp( num, numb[y] ) ) numb[y]=num, pq.push({y,num}), par[y]=u;
	}
    }

    if(done[t]==0) return cout<<-1<<endl,0;
    
    int ans=0;
    for(int i=0, bt=1 ;i<maxn ;i++, bt=2ll*bt %mod){
	if( What(i,numb[t]) ) ans=(ans + bt) %mod;
    }
    cout<<ans<<"\n";

    vector<int> verts;

    int tmp=t;
    while(tmp!=s){
	verts.PB(tmp);
	tmp= par[tmp];
    }
    verts.PB(s);
    reverse( verts.begin(), verts.end() );

    cout<<sz(verts)<<"\n";
    for(int x:verts){
	cout<<x+1<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
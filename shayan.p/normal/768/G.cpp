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

const int maxn=1e5+10,inf=1e9;

vector<int>v[maxn];
map<int,int> mp[4*maxn],mpe;
int SZ[maxn],ans[maxn],sf[maxn],ss[maxn],MX[maxn],MX2[maxn],MXI[maxn],MN[maxn],C=1;
int n,wh[maxn];

void dfs1(int u,int par=-1){
    MX[u]=MX2[u]=-1;
    MN[u]=inf;
    sf[u]=C;
    SZ[u]=1;
    for(int y:v[u]){
	if(y!=par){
	    dfs1(y,u);
	    SZ[u]+=SZ[y];
	    if(SZ[y]>MX2[u] && SZ[y]<=MX[u])
		MX2[u]=SZ[y];
	    if(SZ[y]>MX[u])
		MX2[u]=MX[u],MX[u]=SZ[y],MXI[u]=y;
	    if(SZ[y]<MN[u])
		MN[u]=SZ[y];
	}
    }
    wh[C]=u;
    ss[u]=C++;
}

void build(int l=1,int r=n,int id=1){
    if(l==r){
	mp[id][SZ[wh[l]]]++;
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    mp[id]=mp[2*id+1];
    for(pii p:mp[2*id]){
	mp[id][p.F]+=p.S;
    }
}

void Add(int pos,int val,int x,int l=1,int r=n,int id=1){
    if(l>r || pos<l || r<pos)return;
    if((mp[id][val]=mp[id][val]+x)==0) mp[id].erase(val);
    if(l==r) return;
    int mid=(l+r)/2;
    Add(pos,val,x,l,mid,2*id);
    Add(pos,val,x,mid+1,r,2*id+1);
}

int Bef(int f,int s,int x,int l=1,int r=n,int id=1){
    if(l>r || f>s || r<f || s<l)return -1;
    if(f<=l && r<=s){
	auto it=mp[id].lower_bound(x);
	if(it==mp[id].begin()) return -1;
	else return (--it)->F;
    }
    int mid=(l+r)/2;
    return max(Bef(f,s,x,l,mid,2*id),Bef(f,s,x,mid+1,r,2*id+1));
    
}
int Aft(int f,int s,int x,int l=1,int r=n,int id=1){
    if(l>r || f>s || r<f || s<l)return inf;
    if(f<=l && r<=s){
	auto it=mp[id].lower_bound(x);
	if(it==mp[id].end()) return inf;
	else return it->F;
    }
    int mid=(l+r)/2;
    return min(Aft(f,s,x,l,mid,2*id),Aft(f,s,x,mid+1,r,2*id+1));
}

void dfs2(int u,int par=-1){
    ans[u]=max(MX[u],n-SZ[u]);
    Add(ss[u],SZ[u],-1);
    if(sz(v[u])>1){
	if(MX[u]>(n-SZ[u])){
	    int mn=min(MN[u],(n==SZ[u]?inf:n-SZ[u])),NUM=MX[u]-((mn+MX[u])/2);
	    int num1=Bef(sf[MXI[u]],ss[MXI[u]],NUM);
	    int num2=Aft(sf[MXI[u]],ss[MXI[u]],NUM);
	    if(num1!=-1) ans[u]=min(ans[u],max(MX[u]-num1,max(n-SZ[u],max(MX2[u],mn+num1))));
	    if(num2!=inf) ans[u]=min(ans[u],max(MX[u]-num2,max(n-SZ[u],max(MX2[u],mn+num2))));
	    // aya hamine faghat ?
	}
	else{
	    int mx=n-SZ[u],mn=MN[u],NUM=mx-((mn+mx)/2);
	    //	    cout<<"HERE "<<u<<" "<<mn<<" "<<NUM<<" "<<mx<<" ";
	    int num1=max( Bef(1,sf[u]-1,NUM) , Bef(ss[u]+1,n,NUM));
	    int num2=min( Aft(1,sf[u]-1,NUM) , Aft(ss[u]+1,n,NUM));
	    auto it=mpe.lower_bound(NUM+SZ[u]);
	    int num4=(it==mpe.end()?inf:(it->F)-SZ[u]);
	    int num3=(it==mpe.begin()?-1:((--it)->F)-SZ[u]);
	    int NUM1=max(num1,num3),NUM2=min(num4,num2);
	    //	    cout<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<" "<<NUM1<<" "<<NUM2<<endl;
	    if(NUM1!=-1) ans[u]=min(ans[u],max(mx-NUM1,max(MX[u],mn+NUM1)));
	    if(NUM2!=-1) ans[u]=min(ans[u],max(mx-NUM2,max(MX[u],mn+NUM2)));
	}
    }
    mpe[SZ[u]]++;
    for(int y:v[u]){
	if(y!=par)
	    dfs2(y,u);
    }
    if(--mpe[SZ[u]]==0) mpe.erase(SZ[u]);
    Add(ss[u],SZ[u],1);
}

int main(){
    int r=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
	int a,b;scanf("%d%d",&a,&b);
	if(a==0) r=b;
	else v[a].PB(b),v[b].PB(a);
    }
    dfs1(r);
    build();
    dfs2(r);
    int CNT=0,U=-1;
    for(int i=1;i<=n;i++){
	if(sz(v[i])>1) U=i;
	else CNT++;
    }
    if(CNT==n-1)
	ans[U]=1;
    for(int i=1;i<=n;i++)
	printf("%d\n",ans[i]);
    return 0;
}
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

const int maxn=3e5+10,mod=1e9+7,Big=1e9;

struct BS{
    int L,R,num,mid,who;
    BS(){
	L=-1, R=2e9 + 10, mid= (L+R)>>1;
    }
    void go(int x){
	if(x>=num) R=mid;
	else L=mid;
	mid=(1ll*L+R)>>1;
    } // -1 ham mishe ehtemalan
};
BS bs[maxn];

pii in[maxn],out[maxn];
int ANS,val[maxn],c[maxn],C,n;

vector<pii>v[maxn];

int fn[maxn];

int cod[maxn],SZ,LST;
int ans[maxn];

void fnadd(int pos,int x){
    for(pos+=5; pos<maxn; pos+=(pos & -pos))
	fn[pos]= max(fn[pos],x);
}
int fnask(int pos){
    int ans=0;
    for(pos+=5; pos>0; pos-=(pos & -pos))
	ans=max(ans, fn[pos]);
    return ans;
}
int fnd(int a,int b){
    int ans=0;
    for(auto x:v[a])
	if(x.F==b) ans=max(ans,x.S);
    return ans;
}
void rest(int a){
    pii id={-1,-1};
    for(auto x:v[a]){
	if(id.F==-1) id=x;
	if(val[id.F] + id.S < val[x.F] + x.S) id=x;
	ANS=max(ANS, val[x.F]+val[a]+x.S);
    }
    v[a].clear();
    if(id.F!=-1) v[a].PB(id);
}
void add1(int a,int cnt){
    if(LST!=-1 && a!=LST) fnadd(c[LST],val[LST]);
    val[a]+=cnt;    
    rest(a);    
    if(cod[c[a]] <=C) ANS=max(ANS, val[a] + fnask( upper_bound(cod,cod+SZ, C-cod[c[a]])-cod-1 ) );    
    LST=a;
}
void add2(int a,int b,int cnt){
    if(cod[c[a]]+cod[c[b]] > C) return;
    int num= fnd(a,b) + cnt;
    rest(a), rest(b);
    v[a].PB({b, num}), v[b].PB({a, num});
    ANS=max(ANS, val[a]+val[b]+num);
}

bool is[maxn];
int inis;
vector<int> vec;

int main(){
    //    ios_base::sync_with_stdio(false);cin.tie(0);

    #ifdef shayan
    srand(time(0));
    n=3e5, C=1e9;
    #else
    scanf("%d%d",&n,&C);
    #endif
    
    for(int i=0;i<n;i++){
	#ifdef shayan
	int l=rand()%Big, r=rand()%Big;
	c[i]=rand()%Big;
	if(l>r) swap(l,r);
	if(l==r) r++;
	#else
	int l,r;
	scanf("%d%d%d",&l,&r,&c[i]);
	#endif
	
	in[i]={l,i};
	out[i]={r,i};
	
	cod[i]=c[i];
    }
    sort(in,in+n);
    sort(out,out+n);

    sort(cod,cod+n);
    SZ=unique(cod,cod+n)- cod;

    for(int i=0;i<n;i++){
	c[i]=lower_bound(cod,cod+SZ,c[i])-cod;
    }

    #ifdef shayan
    int m=3e5;
    #else
    int m; scanf("%d",&m);
    #endif
    
    for(int i=0;i<m;i++){
	#ifdef shayan
	bs[i].num= rand()%Big;
	#else
	scanf("%d",&bs[i].num);
	#endif
	bs[i].who=i;
    }
    
    for(int _=0;_<32;_++){// log
	sort(bs,bs+m,[](BS a,BS b){ return a.mid < b.mid; }), memset( fn,0,sizeof fn), memset(val,0,sizeof val), memset(is,0,sizeof is), vec.clear(), inis=0;
	
	int pt1=0,pt2=0,pt3=0,lst=0,delta=0;
	ANS=0, LST=-1;
	
	for(int i=0;i<n;i++)
	    v[i].clear();
	
	while(pt3<m && bs[pt3].mid<0) pt3++;

	while(pt3<m){
	    int mn= bs[pt3].mid;
	    if(pt1<n) mn= min(mn,in[pt1].F);
	    if(pt2<n) mn= min(mn,out[pt2].F);

	    int A=-1,B=-1;

	    if(inis<=2){
		for(int x:vec){
		    if(is[x]){
			if(A==-1) A=x;
			else if(A!=x) B=x;
		    }
		}
		vec.clear();
		if(A!=-1) vec.PB(A);
		if(B!=-1) vec.PB(B);
	    }
	    if(inis==0) delta+= mn-lst;	    
	    if(inis==1) add1( A, mn-lst );
	    if(inis==2) add2( A, B, mn-lst);
	    
	    while(pt3<m && bs[pt3].mid==mn) bs[pt3].go(ANS+delta), pt3++;
	    while(pt1<n && in[pt1].F==mn)  inis++, vec.PB(in[pt1].S), is[ in[pt1].S ]=1, pt1++;
	    while(pt2<n && out[pt2].F==mn) inis--, is[ out[pt2].S]=0, pt2++;
	    
	    lst=mn;
	}
    }
    for(int i=0;i<m;i++){
	ans[bs[i].who]=bs[i].R;
    }
    for(int i=0;i<m;i++){
	printf("%d\n",ans[i]);
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
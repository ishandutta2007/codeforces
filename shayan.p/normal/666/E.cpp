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

const int maxn=5e5+10,SQ=230,Half=5e4+10,inf=1e9;

namespace suffix_array{
    const int maxn=1e6,LG=20,inf=1e9;
    vector<pii>str;
    vector<int>arr,vecp;
    int rnk[LG][maxn],sp[LG][maxn],ID[maxn];
    pair<pii,int> p[maxn];
    void input(int id){
	string s;cin>>s;
	for(int i=0;i<sz(s);i++)
	    str.PB({s[i]-'a'+1,id});
	str.PB({inf,0});
    }
    vector<int> build(){
	for(int i=0;i<sz(str);i++)
	    rnk[0][i]=str[i].F;
	for(int ln=1;ln<LG;ln++){
	    for(int i=0;i<sz(str);i++)
		p[i]={{rnk[ln-1][i],i+(1<<(ln-1))>=sz(str)?-1:rnk[ln-1][i+(1<<(ln-1))]},i};
	    sort(p,p+sz(str));
	    for(int i=1;i<sz(str);i++)
		rnk[ln][p[i].S]=rnk[ln][p[i-1].S]+(p[i].F!=p[i-1].F);
	}
	for(int i=0;i<sz(str)-1;i++){
	    int pos1=p[i].S,pos2=p[i+1].S;
	    for(int j=LG-1;j>=0;j--){
		if(max(pos1,pos2)+(1<<j)<=sz(str) && rnk[j][pos1]==rnk[j][pos2])
		    pos1+=(1<<j),pos2+=(1<<j),sp[0][i]+=(1<<j);
	    }
	}
	for(int i=1;i<LG;i++){
	    for(int j=0;j<sz(str);j++)
		sp[i][j]=min(sp[i-1][j],sp[i-1][min(sz(str)-1,j+(1<<(i-1)))]);
	}
	for(int i=0;i<sz(str);i++){   
	    if(str[p[i].S].S!=0){
		arr.PB(str[p[i].S].S-1);// make it 0 base
		vecp.PB(i);
	    }
	    ID[p[i].S]=i;
	}
	return arr;
    }
    int lcp(int pos1,int pos2){
	if(pos1==pos2) return inf;
	int ln=31-__builtin_clz(pos2-pos1);
	return min(sp[ln][pos1],sp[ln][pos2-(1<<ln)]);
    }
    pii change_query(int LL,int RR){
	int ln=RR-LL+1,pos=ID[LL],l,r,ansl,ansr;
	
	l=0;r=pos;ansl=pos;
	while(l<=r){
	    int mid=(l+r)>>1;
	    if(lcp(mid,pos)>=ln)
		ansl=mid,r=mid-1;
	    else
		l=mid+1;
	}
	l=pos;r=sz(str)-1;ansr=pos;
	while(l<=r){
	    int mid=(l+r)>>1;
	    if(lcp(pos,mid)>=ln)
		ansr=mid,l=mid+1;
	    else
		r=mid-1;
	}
	auto it1=lower_bound(vecp.begin(),vecp.end(),ansl),it2=upper_bound(vecp.begin(),vecp.end(),ansr);
	if(it1==vecp.end() || it2==vecp.begin() || it1==it2) return {-1,-1};
	return {it1-vecp.begin(),it2-vecp.begin()-1};
    }
};

pii val[maxn];

void build(){
    for(int i=Half;i<maxn;i++)
	val[i]={0,-i+Half};
    for(int i=Half-1;i>=0;i--)
	val[i]=max(val[2*i],val[2*i+1]);
}

void add(int id,int x){    
    id+=Half;
    val[id].F+=x;
    id>>=1;
    while(id>0){
	val[id]=max(val[2*id],val[2*id+1]);
	id>>=1;
    }
}

pii ask(int f,int s){// [)
    pii ans={-inf,-inf};
    f+=Half;s+=Half;
    while(f<s){
	if(f&1) ans=max(ans,val[f++]);
	if(s&1) ans=max(ans,val[--s]);
	f>>=1;s>>=1;
    }
    return ans;
}

typedef pair<pii,pair<pii,int> >    pi5;

bool cmp(pi5 a,pi5 b){
    if(a.F.F/SQ != b.F.F/SQ) return a.F.F<b.F.F;
    return a.F.S<b.F.S;
}

pii ans[maxn];
pi5 qu[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    suffix_array::input(0);

    int m;cin>>m;
    for(int i=1;i<=m;i++)
	suffix_array::input(i);
    vector<int>vec=suffix_array::build();
    
    int q,Q=0;cin>>q;
    for(int i=0;i<q;i++){
	int l,r,f,s;cin>>l>>r>>f>>s;
	pii P=suffix_array::change_query(--f,--s);
	if(P.F==-1)
	    ans[i]={0,-l+1};
	else
	    qu[Q++]={P,{{--l,--r},i}};
    }
    sort(qu,qu+Q,cmp);
    build();
    int L=0,R=-1;
    for(int i=0;i<Q;i++){
	int l=qu[i].F.F,r=qu[i].F.S,ff=qu[i].S.F.F,ss=qu[i].S.F.S,id=qu[i].S.S;
	while(l<L)
	    add(vec[--L],1);
	while(R<r)
	    add(vec[++R],1);
	while(r<R)
	    add(vec[R--],-1);
	while(L<l)
	    add(vec[L++],-1);
	ans[id]=ask(ff,ss+1);
    }
    for(int i=0;i<q;i++){
	cout<<-ans[i].S+1<<" "<<ans[i].F<<"\n";
    }
    return 0;
}
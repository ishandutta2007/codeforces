#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int k,n,m,sa[19][MAX<<1],cnt[MAX],stp,jmp,id,z[MAX],ans[MAX],a,b,le,ri,mid,res,resa,resb,q,qu,tgt;
int snw[MAX],snx[MAX];
int x[MAX],y[MAX];
vector<pii> v;

map<int,int> hs;

int nx,ret;
inline int getlcp(int x,int y){
	ret = 0, nx = jmp;
	rap(i,stp,0){
		if(y+nx<=n && sa[i][x]==sa[i][y]){
			ret+= nx;
			x+= nx, y+=nx;
		}
		nx>>=1;
	}
	return ret;
}

int bit[MAX<<1];
inline void upd(int i){
	for(;i<=m;i+=i&-i)++bit[i];
	return;
}
inline int que(int i){
	ret = 0;
	for(;i>0;i-=i&-i)ret+= bit[i];
	return ret;
}
vector<piiii> pd;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    if(n==1){
    	cin>>q;
    	while(q--)cout<<"0\n";
    	return 0;
	}
    asd(i,1,n)y[i-1] = x[i]-x[i+1];
    --n;
    asd(i,0,n){
    	if(!hs.count(y[i]))hs[y[i]] = ++id;
    	if(!hs.count(-y[i]))hs[-y[i]] = ++id;
    	sa[0][i] = hs[y[i]], sa[0][i+n+1] = hs[-y[i]];
	}
	
    m = n*2+1, swap(n,m);
//    asd(i,0,n)cout<<sa[0][i]<<' '; cout<<endl;
    
    jmp = 1;
    while(jmp<n){
    	mems(cnt,0);
    	asd(i,0,n)++cnt[sa[stp][i+jmp]];
    	rep(i,1,n)cnt[i]+= cnt[i-1];
    	rap(i,n-1,0)snx[cnt[sa[stp][i+jmp]]--] = i;
    	
    	mems(cnt,0);
    	asd(i,0,n)++cnt[sa[stp][i]];
    	rep(i,1,n)cnt[i]+= cnt[i-1];
    	rap(i,n,1)snw[cnt[sa[stp][snx[i]]]--] = snx[i];
    	
    	++stp;
    	sa[stp][snw[1]] = 1;
    	rep(i,2,n)sa[stp][snw[i]] = sa[stp][snw[i-1]] + !(sa[stp-1][snw[i]] == sa[stp-1][snw[i-1]]
		&& sa[stp-1][snw[i]+jmp] == sa[stp-1][snw[i-1]+jmp]);
		jmp<<=1;
	}
	
	asd(i,0,n)z[sa[stp][i]] = i;
//	rep(i,1,n){
//		printf("%-3d",z[i]);
//		asd(j,z[i],n)printf("%d ",sa[0][j]); puts("");
//	}
//	db(getlcp(14,0));
	
//	asd(i,0,n)db(sa[stp][i]);
	rep(i,1,n)if(z[i]<m)v.pb({i,z[i]});
//	sort(all(v));
//	cout<<"______\n";
//	for(pii i:v)cout<<i.se<<endl;
	
	auto it = v.begin();
	cin>>q;
	rep(ntc,1,q){
		cin>>a>>b;
		if(a==b){ans[ntc] = m; continue;} tgt = b-a, --b;
		
		qu = a+m;
		it = lower_bound(all(v),mp(sa[stp][qu],0));
		resa = it-v.begin(), resb = resa-1;
		
		le = 0, ri = resa-1;
		while(le<=ri){
			mid = le+ri>>1;
			if(getlcp(v[mid].se,qu)>=tgt)resa = mid, ri = mid-1;
			else le = mid+1;
		}
		
		le = resb+1, ri = v.size()-1;
		while(le<=ri){
			mid = le+ri>>1;
			if(getlcp(v[mid].se,qu)>=tgt)resb = mid, le = mid+1;
			else ri = mid-1;
		}
		
		if(resa>resb)continue;
//		cout<<ntc<<" = "<<resa<<' '<<resb<<" , "<<a-tgt-2<<endl;
//		cout<<">> ";
//		rep(j,resa,resb)cout<<v[j].se<<' '; cout<<endl;
		ans[ntc] = resb-resa+1;
		if(resa){
			pd.pb({{resa-1,ntc},{1,b}});
			if(a-tgt-2>=0)pd.pb({{resa-1,ntc},{-1,a-tgt-2}});
		}
		pd.pb({{resb,ntc},{-1,b}});
		if(a-tgt-2>=0)pd.pb({{resb,ntc},{1,a-tgt-2}});
	}
	sort(all(pd));
	
	a = 0, ++m;
	for(piiii i:pd){
		while(a<=i.ff)upd(v[a].se+1), ++a;
		ans[i.fs]+=i.sf*que(i.ss+1);
//		if(i.fs==3)cout<<"<> "<<i.ff<<' '<<i.fs<<' '<<i.sf<<' '<<i.ss<<endl;
	}
	rep(i,1,q)cout<<ans[i]<<endl;
	return 0;
}
#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

struct wd{
	int x[26];
}tree[MAX*3],res;

int n,q,a,b,nw,lz[3*MAX],cg,cek;
bool cm;
char c[MAX];

inline void f(int &id,int &le,int &ri){
	rep(i,0,25)tree[id].x[i] = 0;
	tree[id].x[lz[id]] = ri-le+1;
	if(le!=ri)lz[id*2] = lz[id*2+1] = lz[id];
	lz[id] = -1;
	return;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id].x[c[le]-'a'] = 1;
		return;
	}
	int mid = (le+ri)/2;
	build(id*2,le,mid);
	build(id*2+1,mid+1,ri);
	rep(i,0,25)tree[id].x[i] = tree[id*2].x[i] + tree[id*2+1].x[i];
	return;
}
void upd(int id,int le,int ri){
	if(lz[id]!=-1)f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = cg; f(id,le,ri); return;}
	int mid = (le+ri)/2;
	upd(id*2,le,mid);
	upd(id*2+1,mid+1,ri);
	rep(i,0,25)tree[id].x[i] = tree[id*2].x[i] + tree[id*2+1].x[i];
	return;
}
wd que(int id,int le,int ri){
	if(lz[id]!=-1)f(id,le,ri);
	if(le>b||ri<a)return tree[0];
	if(le>=a&&ri<=b)return tree[id];
	int mid = (le+ri)/2;
	wd t1 = que(id*2,le,mid), t2 = que(id*2+1,mid+1,ri), ret;
	rep(i,0,25)ret.x[i] = t1.x[i]+t2.x[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>c[i];
    build(1,1,n);
    memset(lz,-1,sizeof lz);
    while(q--){
    	cin>>a>>b>>cm;
    	res = que(1,1,n);
    	if(cm)
    		rep(i,0,25){
    			if(!res.x[i])continue;
    			b = a+res.x[i]-1;
    			cg = i;
    			upd(1,1,n);
    			a = b+1;
			}
		else 
			rap(i,25,0){
    			if(!res.x[i])continue;
    			b = a+res.x[i]-1;
    			cg = i;
    			upd(1,1,n);
    			a = b+1;
			}
	}
	rep(i,1,n){
		a = b = i;
		res = que(1,1,n);
		rep(j,0,25)if(res.x[j]){
			cout<<(char)('a'+j); break;
		}
	}
    return 0;
}
#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int N=1e9+5;
const int M=1e7;



struct node{	
	int l;int r;
	int val=0;
}t[M];
int cnt=0;

int n;
map<int,int>mp;
vector<pii>ans;

void extend(int v){
	if(t[v].l==0){
		t[v].l=++cnt;
		t[v].r=++cnt;
	}
}

void pushup(int v){
	t[v].val=max(t[t[v].l].val,t[t[v].r].val);
}	

void update(int v,int l,int r,int val,int tl=0,int tr=N){
	if(tl>r || l>tr)return;
	if(l<=tl && tr<=r){
		t[v].val+=val;
		return;
	}
	extend(v);
	int mid=(tl+tr)/2;
	update(t[v].l,l,r,val,tl,mid);
	update(t[v].r,l,r,val,mid+1,tr);
	pushup(v);
}

map<int,pii>st;
void query(int v,int i,int s,int tl=0,int tr=N){
	if(tl==tr){
		if(tl<=i){
			int j=mp[tl];
			assert(j!=0);
			ans[j].x++;
			ans[j].y+=s;
			t[v].val+=s;
			while(!st.empty()){
				auto itr=st.lower_bound(tl);
				if(itr==st.end() || itr->x>t[v].val)break;
				ans[j].x+=itr->y.x;
				ans[j].y+=itr->y.y;
				t[v].val+=itr->y.y;
				st.erase(itr);
			}
		}
		else{
			st[i].x++;
			st[i].y+=s;
		}
		return;
	}
	int mid=(tl+tr)/2;
	extend(v);
	if(t[t[v].l].val>=i){
		query(t[v].l,i,s,tl,mid);
	}
	else{
		query(t[v].r,i,s,mid+1,tr);
	}
	pushup(v);
	
}



int solve(){
 	int n,m;cin>>n>>m;
 	ans.resize(n+1);
 	int min=hell;
 	rep(i,1,n+1){
 		int x,t;cin>>x>>t;
 		mp[x]=i;
 		ans[i].y=t;
 		update(0,x,x,x+t);
 		mins(min,x);
 	}
 	rep(i,0,m){
 		int x,s;cin>>x>>s;
 		if(min>x)continue;
 		query(0,x,s);
 	}
 	rep(i,1,n+1){
 		cout<<ans[i]<<endl;
 	}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
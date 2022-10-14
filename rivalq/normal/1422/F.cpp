#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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



const int N =200050;
const int M=2e7;
const int maxn=4e7;

int lp[N+1];
int pr[N];int cur=0;
void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[cur++]=i;
            }
        for (int j=0; j<cur && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


struct node{
        int l=0,r=0;
        int sum=0;
}t[maxn];
int temp=0;


void extend(int v){
        t[v].l=++temp;
        t[temp].sum=1;
        t[v].r=++temp;
        t[temp].sum=1;
}
void build(int v,int tl,int tr){
        t[v].sum=1;
        if(tl==tr){
               return; 
        }
        int mid=(tl+tr)/2;
        extend(v);
        build(t[v].l,tl,mid);
        build(t[v].r,mid+1,tr);
}
void update(int v,int tl,int tr,int j,int val){	
        if(tl==tr){
                t[v].sum=1LL*t[v].sum*val%hell;return;
        }
        int mid=(tl+tr)/2;
        if(j<=mid){
                int old_l=t[v].l;int new_l=++temp;
                t[new_l]=t[old_l];t[v].l=new_l;
                update(t[v].l,tl,mid,j,val);
        }
        else{
            int old_r=t[v].r;int new_r=++temp;
            t[new_r]=t[old_r];t[v].r=new_r;
            update(t[v].r,mid+1,tr,j,val);
        }
        t[v].sum=(1LL*t[t[v].l].sum*t[t[v].r].sum)%hell;
}
int query(int v,int l,int r,int tl,int tr){
        if(tl>r || l>tr || v==0)return 1;
        if(l<=tl && tr<=r)return t[v].sum;
        int mid=(tl+tr)/2;
        return 1LL*query(t[v].l,l,r,tl,mid)*query(t[v].r,l,r,mid+1,tr)%hell; 
}


const int Q=2e5+5;

int ver[Q];
int vis[Q];
vector<pii>mx[Q];

int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(1LL*a*x)%p;
        x=(1LL*x*x)%p;
        y/=2;
    }
    return a;
}


int solve(){
	int n;cin>>n;
	for(int i=2;i<Q;i++){
		mx[i].pb({0,0});
	}
	t[temp].sum=1;
	ver[0]=++temp;
	t[temp].sum=1;
	//build(ver[0],1,n);
	auto add=[&](int t,int l,int r,int val){
		update(t,1,n,l,val);
		if(r!=n)update(t,1,n,r+1,expo(val,hell-2,hell));
	};
	rep(i,1,n+1){
		ver[i]=++temp;
		t[ver[i]]=t[ver[i-1]];
		int t;
		cin>>t;
		while(t>1){
			int temp=lp[t];
			int cnt=0;
			while(lp[t]==temp){
				t/=temp;
				cnt++;
			}
			pii j={temp,cnt};
			int pr=j.x;			
			while(mx[j.x].back().x!=0 && j.y>=mx[j.x].back().y){
				int k=mx[j.x].back().x;
				int old=mx[j.x].back().y;mx[j.x].pop_back();
 				int val=expo(pr,j.y-old,hell);
 				add(ver[i],mx[j.x].back().x+1,k,val);
			}
			add(ver[i],vis[j.x]+1,i,expo(pr,j.y,hell));
			vis[j.x]=i;
			mx[j.x].pb({i,j.y});
			
		}

	}
	int last=0;
	int q;cin>>q;

	rep(i,0,q){
		int l,r;cin>>l>>r;
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if(l>r)swap(l,r);
		last =query(ver[r],1,l,1,n);
		cout<<last<<endl;
	}

	return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
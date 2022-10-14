#include<iostream>

#define rep(i,a,n)     for(int i=a;i<n;i++)

using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N=1e9+5;
const int M=1e7;



struct node{	
	int l;int r;
	int val;
}t[M];
int cnt=0;

int n;

void extend(int v){
	if(t[v].l==0){
		t[v].l=++cnt;
		t[v].r=++cnt;
	}
}

void pushdown(int v,int tl,int tr,int val){
	if(tl!=tr){
		extend(v);
		maxs(t[t[v].l].val,val);
		maxs(t[t[v].r].val,val);
	}
}	

void update(int v,int l,int r,int val,int tl=1,int tr=n){
	if(tl>r || l>tr)return;
	if(l<=tl && tr<=r){
		maxs(t[v].val,val);
		return;
	}
	extend(v);
	int mid=(tl+tr)/2;
	update(t[v].l,l,r,val,tl,mid);
	update(t[v].r,l,r,val,mid+1,tr);
}

void query(int v,int i,int &mx,int tl=1,int tr=n){
	if(tl==tr){
		maxs(mx,t[v].val);
		return;
	}
	maxs(mx,t[v].val);
	int mid=(tl+tr)/2;
	extend(v);
	if(i<=mid)query(t[v].l,i,mx,tl,mid);
	else query(t[v].r,i,mx,mid+1,tr);
}


// ith row starts from n-i+1 th column;

int solve(){
 	int q;
 	scanf("%d %d",&n,&q);
 	int root1=++cnt;  // row wise
 	int root2=++cnt; // column wise
 	int ans=0;
 	rep(i,0,q){
 		int x,y;char c;
 		scanf("%d %d %c",&x,&y,&c);
 		if(c=='L'){
 			//yth row
 			int mx=0;query(root1,y,mx);
 			printf("%d\n",n-y+1-mx);
 			update(root1,y,y,n-y+1);
 			if(mx+1<=n-y+1)update(root2,mx+1,n-y+1,y);
 		}
 		else{
 			// xth column
 			int mx=0;query(root2,x,mx);
 			printf("%d\n",n-x+1-mx);
 			update(root2,x,x,n-x+1);
 			if(mx+1<=n-x+1)update(root1,mx+1,n-x+1,x);

 		}

 	}
 return 0;
}
signed main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
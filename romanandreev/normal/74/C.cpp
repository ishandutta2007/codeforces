#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int r[5000000];
int nx[5000000];
int b[5000000];
int n,m;
int get(int v){
	if (v==nx[v]) return v;
	nx[v]=get(nx[v]);
	return nx[v];
}
void uni(int x,int y){
	x=get(x);
	y=get(y);
	if (r[x]<r[y]){
		nx[x]=y;
		return;
	}
	if (r[y]<r[x]){
		nx[y]=x;
		return;
	}
	nx[x]=y;
	r[y]++;
}
int num(int x,int y){
	if (x==0) return y;
	if (y==n-1) return n-1+x;
	if (x==m-1) return n-1+m-1+n-1-y;
	return n-1+m-1+n-1+m-1-x;
}
void go(int x,int y,int vx,int vy){
	int ds=n+m;
	if (vx==1){
		ds=min(ds,m-1-x);
	} else 
		ds=min(ds,x);
	if (vy==1){
		ds=min(ds,n-1-y);
	} else 
		ds=min(ds,y);
	uni(num(x,y),num(x+ds*vx,y+ds*vy));
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    if (n<m){
    	swap(n,m);
    }
    for (int i=0;i<n*2+m*2-4;i++){
    	nx[i]=i;
    	r[i]=1;
    }
    for (int i=0;i<n;i++){
    	go(0,i,1,1);
    	go(0,i,1,-1);
    	go(m-1,i,-1,1);
    	go(m-1,i,-1,-1);
    }
    for (int i=0;i<m;i++){
    	go(i,0,1,1);
    	go(i,0,-1,1);
    	go(i,n-1,1,-1);
    	go(i,n-1,-1,-1);
    }
    int ans=0;
    for (int i=0;i<n*2+m*2-4;i++)
    	if (b[get(i)]==0) {
    		ans++;
    		b[get(i)]=1;
    	}
    cout<<ans<<endl;
    return 0;
}
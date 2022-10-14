#include<stdio.h>
#define rep3(n)        for(int i=0;i<n;i++)
#define pb             push_back
#define endl           "\n"
#define sz(a)          (int)a.size()
struct node{
	int lazy=0;
	int left=0;
	int right=0;
	int cnt1=0;
};
struct node v[15000000];
int d=0;
inline void extend(int id,int tl,int tr){
	if(v[id].left==0){
		  int mid=(tl+tr)/2;
		  v[id].left=++d;
          v[id].right=++d;
          v[v[id].left].cnt1=mid-tl+1;
          v[v[id].right].cnt1=tr-mid;
	    }
    }
inline void update(int t ,int l,int r,int val,int tl,int tr){
	 if(l>tr || tl>r)return;
	 if(tl>=l && r>=tr){
	 	v[t].cnt1=(val>0)?tr-tl+1:0;
	 	v[t].lazy=val;
	 	return;
	 }
	 if(v[t].lazy){
	 	if(tl!=tr){
           extend(t,tl,tr);
           int mid=(tl+tr)/2;
           v[v[t].left].cnt1=(v[t].lazy>0)?mid-tl+1:0;
           v[v[t].right].cnt1=(v[t].lazy>0)?tr-mid:0;
           v[v[t].left].lazy=v[t].lazy;
           v[v[t].right].lazy=v[t].lazy;
	 	}
	 	v[t].lazy=0;
	 }
	extend(t,tl,tr);
	int mid=(tl+tr)/2;
    update(v[t].left,l,r,val,tl,(tl+tr)/2);
	update(v[t].right,l,r,val,(tl+tr)/2+1,tr);
	v[t].cnt1=v[v[t].left].cnt1+v[v[t].right].cnt1;
}
void solve(){
 int n;scanf("%d\n",&n);
 int q;scanf("%d\n",&q);
 v[0].cnt1=n;
 rep3(q){
   int l,r,k;
   scanf("%d %d %d",&l,&r,&k);
   int val=(k==1)?-1:1;
   update(0,l,r,val,1,n);
   printf("%d\n",v[0].cnt1);
 }
  return;
}
signed main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
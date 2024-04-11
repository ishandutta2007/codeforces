#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int m,n,x[MAX],le,ri,id1,id2,mid,a[MAX],b[MAX],mx1,mx2,ans,st;
int main(){
    cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    cin>>m;
    rep(i,1,m)cin>>a[i];
    rep(i,1,m)cin>>b[i];
    rep(i,1,m){
    	st=0;
    	id1 = 0, id2 = -1;
    	le=1, ri=n;
    	while(le<=ri){
    		mid=(le+ri)/2;
    		if(x[mid]==a[i])id1=mid, ri=mid-1;
    		else if(x[mid]<a[i])le=mid+1;
    		else ri=mid-1;
		}
		le=1, ri=n;
    	while(le<=ri){
    		mid=(le+ri)/2;
    		if(x[mid]==a[i])id2=mid, le=mid+1;
    		else if(x[mid]<a[i])le=mid+1;
    		else ri=mid-1;
		}
		if(mx1<id2-id1+1)mx1=id2-id1+1, st=2, ans=i;
		else if(mx1==id2-id1+1)st=1;
		id1 = 0, id2 = -1;
    	le=1, ri=n;
    	while(le<=ri){
    		mid=(le+ri)/2;
    		if(x[mid]==b[i])id1=mid, ri=mid-1;
    		else if(x[mid]<b[i])le=mid+1;
    		else ri=mid-1;
		}
		le=1, ri=n;
    	while(le<=ri){
    		mid=(le+ri)/2;
    		if(x[mid]==b[i])id2=mid, le=mid+1;
    		else if(x[mid]<b[i])le=mid+1;
    		else ri=mid-1;
		}
		if(st==2)mx2=id2-id1+1;
		else if(mx2<id2-id1+1 && st)ans=i, mx2=id2-id1+1;
	}
	cout<<max(1,ans)<<endl;
    return 0;
}
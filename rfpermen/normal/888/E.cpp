#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=100005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,mx,x[37],m,cnt,cnt2,y[632000],z[963000];
void bf1(int idx,ll jlh){
	if(idx>17 || idx>n)return;
	cnt++;
	y[cnt] = (jlh+x[idx])%m;
	bf1(idx+1,(jlh+x[idx])%m);
	bf1(idx+1,jlh);
}
void bf2(int idx,ll jlh){
	if(idx>n)return;
	cnt2++;
	z[cnt2] = (jlh+x[idx])%m;
	bf2(idx+1,(jlh+x[idx])%m);
	bf2(idx+1,jlh);
}
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>x[i];
	bf1(1,0);
	bf2(18,0);
	//cout<<cnt<<" "<<cnt2<<endl;
	rep(i,1,cnt){
		y[i]%=m;
	}
	rep(i,1,cnt)mx = max(y[i],mx);
	if(n<18){
		cout<<mx<<endl;
		return 0;
	}
	rep(i,1,cnt2){
		z[i]%=m;
	}
	rep(i,1,cnt2)mx = max(z[i],mx);
	sort(z+1,z+1+cnt2);
	rep(i,1,cnt){
		ll le = 1, ri = cnt2, mid, p=0;
		while(le<=ri){
			mid = (le+ri)/2;
			if(y[i]+z[mid]>=m)ri=mid-1;
			else p=mid, le=mid+1;
		}
		mx = max((z[p]+y[i])%m,mx);
	}
	cout<<mx<<endl;
	return 0;
}
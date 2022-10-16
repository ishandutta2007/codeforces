#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=105;
ll gcd(ll r,ll v){
	if(v==0) return r;
	return gcd(v,r%v);
}
ll n,R,C,cnt,up,don,le,ri,sq,ans;
char grid[MAX][MAX];
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>R>>C;
	up=MAX, le=MAX;
	rep(r,1,R){
		rep(c,1,C){
			cin>>grid[r][c];
			if(grid[r][c]=='B'){
				cnt++;
				if(up>r)up=r;
				if(don<r)don=r;
				if(le>c)le=c;
				if(ri<c)ri=c;
			}
		}
	}
	sq=max((ll)1,max(abs(up-don)+1,abs(le-ri)+1));
	if(up==MAX)sq=1;
	if(R<sq || C<sq)cout<<-1<<endl;
	else cout<<sq*sq-cnt<<endl;
	//cout<<up<<" "<<don<<" "<<le<<" "<<ri<<endl;
	//cout<<sq;
	return 0;
}
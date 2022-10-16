#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x first
#define y second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,res;
pdd p[305];
double ans,le,ri,a,b,c,s;
pdd sub(pdd a,pdd b){
	return mp(a.x-b.x,a.y-b.y);
}
ll crossProduct(pdd a,pdd b){
	return a.x*b.y - a.y*b.x;
}
int ccw(pdd a,pdd b,pdd c){
	ll tmp = crossProduct(sub(b,a),sub(c,a));
	//cout<<tmp<<endl;
	if(tmp<0)return -1;
	if(tmp>0)return 1;
	return 0;
}


int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>p[i].x>>p[i].y;
	}
	rep(i,1,n)rep(j,i+1,n){
		le = ri = 0;
		rep(k,1,n){
			res = ccw(p[k],p[j],p[i]);
			//cout<<i<<" "<<j<<" "<<k<<" "<<res<<endl;
			if(res==0)continue;
			a = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
			b = sqrt((p[i].x-p[k].x)*(p[i].x-p[k].x) + (p[i].y-p[k].y)*(p[i].y-p[k].y));
			c = sqrt((p[k].x-p[j].x)*(p[k].x-p[j].x) + (p[k].y-p[j].y)*(p[k].y-p[j].y));
			s = (a+b+c)/2.0;
			//cout<<a<<" "<<b<<" "<<c<<" "<<s<<endl;
			//cout<<"Area = "<<s*(s-a)*(s-b)*(s-c)<<endl;
			if(res==1){
				le = max(le,s*(s-a)*(s-b)*(s-c));
			}
			else ri = max(ri,s*(s-a)*(s-b)*(s-c));
		}
		//cout<<i<<" "<<j<<" = "<<le<<" "<<ri<<endl;
		if(le<1e-9 || ri<1e-9)continue;
		ans = max(ans,sqrt(le)+sqrt(ri));
	}
	cout<<ans<<endl;
    return 0;
}
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
#define fi first
#define se second
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

ll x,y,le,ri,mid,a,h,w,res,tmp;
double cek,eps=1e-9;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    rep(i,0,31){
    	if(x<(1<<i))break;
    	le = 1, ri = y;
    	res = 0;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		cek = (1<<i);
    		cek/= mid;
    		//cout<<(1<<i)<<" "<<mid<<" "<<cek<<endl;
    		if(cek>0.8-eps && cek<1.25+eps)res = mid, le = mid+1;
    		else if(cek<0.8+eps)ri = mid-1;
    		else le = mid+1;
		}
		tmp = (1<<i);
		if(a<tmp*res)a = tmp*res, h = tmp, w = res;
		else if(a==tmp*res && h<tmp)h = tmp, w = res;
	}
	rep(i,0,31){
    	if(y<(1<<i))break;
    	le = 1, ri = x;
    	res = 0;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		cek = mid;
    		cek/= (1<<i);
    		if(cek>0.8-eps && cek<1.25+eps)res = mid, le = mid+1;
    		else if(cek>1.25-eps)ri = mid-1;
    		else le = mid+1;
		}
		tmp = (1<<i);
		if(a<tmp*res)a = tmp*res, h = res, w = tmp;
		else if(a==tmp*res && h<res)h = res, w = tmp;
	}
	cout<<h<<" "<<w<<endl;
    return 0;
}
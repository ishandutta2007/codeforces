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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x[3],y,z,sz,cnt,ans,tmp;
string s,t;
map<string,int> m;
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    m["C"] = 0; m["C#"] = 1; m["D"] = 2; m["D#"] = 3;
    m["E"] = 4; m["F"] = 5; m["F#"] = 6; m["G"] = 7;
    m["G#"] = 8; m["A"] = 9; m["B"] = 10; m["H"] = 11;
    rep(i,0,2){
    	cin>>s;
    	x[i] = m[s];
	}
	sort(x,x+3);
	do {
		if(x[0]>x[1])a = 12 - x[0] + x[1];
		else a = x[1]-x[0];
		if(x[1]>x[2])b = 12 - x[1] + x[2];
		else b = x[2]-x[1];
		//cout<<a<<" "<<b<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
		if(a==4 && b==3)return cout<<"major",0;
		else if(a==3 && b==4)return cout<<"minor",0;
	}while(next_permutation(x,x+3));
	cout<<"strange";
    return 0;
}
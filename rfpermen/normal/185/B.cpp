#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 100+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int a,b,c;
double s,op1,op2,op3;

double ter(double x){
	double le,ri,m1,m2,a1,a2;
	le = 0.0, ri = x;
	rep(k,1,1000){
		m1 = (le+le+ri)/3.0;
		m2 = (le+ri+ri)/3.0;
		if(!b)a1 = a2 = 0.0;
		else a1 = (double)b*log(m1), a2 = (double)b*log(m2);
		if(c)a1+= (double)c*log(x-m1), a2+= (double)c*log(x-m2);
		if(a1>a2)ri = m2;
		else le = m1;
	}
	op2 = m1, op3 = x-m1;
	return a1;
}

double ternary(){
	double le,ri,m1,m2,a1,a2;
	le = 0.0, ri = s;
	rep(k,1,1000){
		m1 = (le+le+ri)/3.0;
		m2 = (le+ri+ri)/3.0;
		if(!a)a1 = a2 = 0.0;
		else a1 = (double)a*log(m1), a2 = (double)a*log(m2);
		a1+= ter(s-m1), a2+= ter(s-m2);
		if(a1>a2)ri = m2;
		else le = m1;
	}
	op1 = m1;
	return a1;
}
 
int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>a>>b>>c;
	ternary();
//    cout<<<<endl;
    cout<<op1<<' '<<op2<<' '<<op3<<endl;
    return 0;
}
// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef short int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=5010;

ll t[maxn],n,m;
vector<string> vec;

void decompose(string &str){
	vec.clear();
	string s="";
	REP(i,sz(str)){
		if(str[i]==' '){
			vec.PB(s);
			s="";
		}
		else
			s+=str[i];
	}
	if(s!="")
		vec.PB(s);
}

struct Oper2{
	ll var,var1,var2,op;
	void get(ll vr,ll a,ll b,ll c){
		var=vr;
		var1=a;
		op=b;
		var2=c;
	}
};
struct Oper1{
	ll var;
	string num;
	void get(ll a,string &b){
		var=a;
		num=b;
	}
};
Oper1 oper1[maxn];
Oper2 oper2[maxn];

bool varib[maxn];

ll f(ll dig,bool value){
	memset(varib,0,sizeof varib);
	ll t1=0,t2=0;
	REP(i,n){
		if(t[i]==1){
			varib[oper1[t1].var]=(oper1[t1].num[dig]=='1');
			t1++;
		}
		else{
			bool a=(oper2[t2].var1==-1?value:varib[oper2[t2].var1]);
			bool b=(oper2[t2].var2==-1?value:varib[oper2[t2].var2]);
			if(oper2[t2].op==0){//and
				varib[oper2[t2].var]=a&b;
			}
			if(oper2[t2].op==1){// or
				varib[oper2[t2].var]=a|b;
			}
			if(oper2[t2].op==2){// xor
				varib[oper2[t2].var]=a^b;
			}
			t2++;
		}
	}
	ll sum=0;
	REP(i,maxn)
		sum+=varib[i];
	return sum;
}

int main(){
	ll t1=0,t2=0;cin>>n>>m;
	string s;
	map<string,ll>mp;
	ll cnt=0;
	mp["?"]=-1;
	
	getline(cin,s);
	REP(i,n){
		getline(cin,s);
		decompose(s);
		if(sz(vec)==3){
			t[i]=1;
			if(!mp.count(vec[0]))mp[vec[0]]=cnt++;
			oper1[t1++].get(mp[vec[0]],vec[2]);
		}
		else{
			t[i]=2;
			if(!mp.count(vec[0]))mp[vec[0]]=cnt++;
			if(!mp.count(vec[2]))mp[vec[2]]=cnt++;
			if(!mp.count(vec[4]))mp[vec[4]]=cnt++;
			ll op;
			if(vec[3]=="AND")op=0;
			if(vec[3]=="OR")op=1;
			if(vec[3]=="XOR")op=2;
			oper2[t2++].get(mp[vec[0]],mp[vec[2]],op,mp[vec[4]]);
		}
	}
	
	string ans_min,ans_max;
	REP(i,m){
		ll a=f(i,0),b=f(i,1);
		if(a==b){
			ans_min+="0";
			ans_max+="0";
		}
		if(a<b){
			ans_min+="0";
			ans_max+="1";
		}
		if(a>b){
			ans_min+="1";
			ans_max+="0";
		}
	}
	
	cout<<ans_min<<endl<<ans_max;
}
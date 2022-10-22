#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

int n,t,k;

string ans,s;

void mv(int x){
	while(x>=9){
		s+='9';
		x-=9;
	}
	if(x) s+=char(int('0')+x);
}
void mv1(int x){
	if(x>=8) x-=8,s+='8';
	while(x>=9){
		s+='9';
		x-=9;
	}
	if(x) s+=char(int('0')+x);
}
void check(int x,int u){
	s="";
	int res=0,cnt=0;
	for(int i=u;cnt<=k;cnt++,i=(i+1)%10)
		res+=i;
	res+=x*9*(10-u);
	res+=k-(10-u)+1;
	res=n-res;
	if(res>=0 && res%(k+1)==0){
		s+=char(u+int('0'));
		f(i,0,x) s+='9';
		mv1(res/(k+1));
		reverse(s.begin(),s.end());
		if(ans=="" || (s.size()<=ans.size() && (s.size()<ans.size() || s<ans))) ans=s;
	}
}
void case1(int x){
	f(j,10-k,10)
		check(x,j);
}
void case2(int x){
	int res=n;
	s=char(int('0')+x);
	f(i,x,x+k+1) res-=i;
	if(res>=0 && res%(k+1)==0){
		mv(res/(k+1));
		reverse(s.begin(),s.end());
		if(ans=="" || (s.size()<=ans.size() && (s.size()<ans.size() || s<ans))) ans=s;
	}
}

int main(){
	cin>>t;
	f(q,0,t){
		ans="";
		cin>>n>>k;
		f(i,0,151)
			case1(i);
		f(i,0,10-k)
			case2(i);
		if(1){
			if(ans=="") cout<<-1<<endl;
			else cout<<ans<<endl;
		}
		else if(q==27)
			cout<<n<<" "<<k<<endl;
	}
}
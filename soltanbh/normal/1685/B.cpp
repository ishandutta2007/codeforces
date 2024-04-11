#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,a,b,ab,ba;
string s;

void Main(){
	cin>>a>>b>>ab>>ba>>s; n=s.size();
	int cnta=0;
	f(i,0,n) cnta+=s[i]=='A';
	if(cnta!=a+ab+ba){
		cout<<"NO"<<'\n';
		return ;
	}
	vector<int> v1,v2;
	int st,res=0;
	f(i,0,n){
		if(i==0 || s[i]==s[i-1]){
			st=i;
		}
		if(i==n-1 || s[i]==s[i+1]){
			int len=(i-st+1)/2;
			if(s[i]==s[st]){
				//cout<<i<<" -> "<<st<<endl;
				res+=len;
			}
			else{
				if(s[st]=='A'){
					ab-=len;
					if(len>1) v1.pb(len);
				}
				else{
					ba-=len;
					if(len>1) v2.pb(len);
				}
			}
		}
	}
	//eror(res);
	sort(all(v1));
	sort(all(v2));
	if(ab<0){
		while(ab<0 && ba>0 && v1.size()){
			ab+=2;
			ba-=1;
			v1.back()-=2;
			while(ba>0 && v1.back()>0){
				ba--;
				ab++;
				v1.back()--;
			}
			v1.pop_back();
		}
	}
	else if(ba<0){
		while(ba<0 && ab>0 && v2.size()){
			ba+=2;
			ab-=1;
			v2.back()-=2;
			while(ab>0 && v2.back()>0){
				ab--;
				ba++;
				v2.back()--;
			}
			v2.pop_back();
		}
	}
	if(max(0ll,ab)+max(0ll,ba)<=res){
		cout<<"YES"<<'\n';
		return ;
	}
	cout<<"NO"<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
2 3 5 4
AABAABBABAAABABBABBBABB
*/
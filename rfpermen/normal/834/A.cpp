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
const int MAX=1005;
ll gcd(ll r,ll v){
	if(v==0) return r;
	return gcd(v,r%v);
}
char c,s;
int n;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>s>>n;
	if(n%4==0){
		cout<<"undefined"<<endl;
	}
	else if(n%4==1){
		if(c=='>' && s=='v')cout<<"cw"<<endl;
	else if(c=='v' && s=='<')cout<<"cw"<<endl;
	else if(c=='<' && s=='^')cout<<"cw"<<endl;
	else if(c=='^' && s=='>')cout<<"cw"<<endl;
	else if(c=='>' && s=='^')cout<<"ccw"<<endl;
	else if(c=='^' && s=='<')cout<<"ccw"<<endl;
	else if(c=='<' && s=='v')cout<<"ccw"<<endl;
	else if(c=='v' && s=='>')cout<<"ccw"<<endl;
	else cout<<"undefined"<<endl;
	}
	else if(n%4==2){
		cout<<"undefined"<<endl;
	}
	else if(n%4==3){
		if(c=='>' && s=='v')cout<<"ccw"<<endl;
	else if(c=='v' && s=='<')cout<<"ccw"<<endl;
	else if(c=='<' && s=='^')cout<<"ccw"<<endl;
	else if(c=='^' && s=='>')cout<<"ccw"<<endl;
	else if(c=='>' && s=='^')cout<<"cw"<<endl;
	else if(c=='^' && s=='<')cout<<"cw"<<endl;
	else if(c=='<' && s=='v')cout<<"cw"<<endl;
	else if(c=='v' && s=='>')cout<<"cw"<<endl;
	else cout<<"undefined"<<endl;
	}
	
	return 0;
}
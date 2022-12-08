#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline ll read(){
	ll x=0; char ch=getchar(); bool d=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return d?x:-x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=20005,mo=1e9+7;
int f[2][N],rk2[N],rk1[N],L[N],R[N];
string s,t;
bool check(int pos1,int pos2){
	int n=s.length(),m=t.length(),l=0,r=0;
	while(l<n||r<m){
		if(l==pos1) l++;
		if(r==pos2) r++;
		if(r==m) return 1;
		if(l==n) return 0;
		if(s[l]!=t[r]) return s[l]>t[r];
		l++; r++;
	}
	return 1;
}
int main(){
	int n=read();
	cin>>t;
	For(i,1,t.length()+1) f[1][i]=1;
	int la=-1,k1=0,k2=0,m=t.length();
	Rep(i,m-1,0){
		if(t[i]-'a'>la) L[++k1]=i;
		else R[++k2]=i;
		if(i&&t[i]!=t[i-1]) la=t[i]-'a';
	}
	Rep(i,k1,1) rk1[k1-i+1]=L[i];
	rk1[k1+1]=-1;
	For(i,1,k2) rk1[i+k1+1]=R[i];
	// cout<<"# "<<1<<endl;
	// For(i,1,k1+k2) cout<<rk1[i]<<" ";
	// cout<<endl;
	For(o,2,n){
		cin>>s; m=s.length();
		la=-1; k1=k2=0;
		Rep(i,m-1,0){
			if(s[i]-'a'>la) L[++k1]=i;
			else R[++k2]=i;
			if(i&&s[i]!=s[i-1]) la=s[i]-'a';
		}
		Rep(i,k1,1) rk2[k1-i+1]=L[i];
		rk2[k1+1]=-1;
		For(i,1,k2) rk2[i+k1+1]=R[i];
		// reverse(rk2+1,rk2+m+1);
		// cout<<"# "<<o<<endl;
		// For(i,1,t.length()+1) cout<<rk2[i]<<" ";
		// cout<<endl;
		int pos=1,sum=0;
		// cout<<"#"<<o<<" "<<s<<" "<<t<<" "<<check(0,0)<<endl;
		For(i,1,s.length()+1){
			while(pos<=t.length()+1&&check(rk2[i],rk1[pos])){
				sum=(sum+f[(o%2)^1][pos])%mo;
				pos++;
			}
			// cout<<o<<" "<<i<<" "<<id<<" "<<pos<<" "<<sum<<endl;
			f[o%2][i]=sum;
		}
		// cout<<"# "<<o<<endl;
		// For(i,1,m) cout<<f[o%2][i]<<" ";
		// cout<<endl;
		t=s;
		memset(rk1,0,sizeof(rk1));
		For(i,1,20001) f[(o%2)^1][i]=0;
		For(i,1,m+1) rk1[i]=rk2[i];
	}
	int ans=0;
	For(i,1,m+1) ans=(ans+f[n%2][i])%mo;
	cout<<ans;
}
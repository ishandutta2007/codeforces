//													In The Name of Allah
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e6+10,p=1e9+7;
ll ten[maxn],num[maxn];
struct seg3{
	pll a,b,c;
};
vector<seg3>collision;
inline ll ask(pll a){
	if(a.F==0)return num[a.S];
	return (((num[a.S]-(ten[a.S-a.F+1]*num[a.F-1]))%p)+p)%p;
}
void check(seg3 seg){
	if(seg.a.F<=seg.a.S&&seg.a.S<=seg.b.F&&seg.b.F<=seg.b.S&&seg.b.S<=seg.c.F&&seg.c.F<=seg.c.S){
		if(seg.a.S-seg.a.F>seg.c.S-seg.c.F||seg.b.S-seg.b.F>seg.c.S-seg.c.F)return;
		if((ask(seg.a)+ask(seg.b))%p==ask(seg.c)){
			collision.PB(seg);
		}
	}
}
seg3 make_seg(pll x,pll y,pll z){
	seg3 seg;
	seg.a=x;seg.b=y;seg.c=z;
	return seg;
}
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
 
const int base = 1e9;
typedef vector<int> BigInt;
 
void Set(BigInt &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}
 
void Print(BigInt a) {
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i,a.size()-2,0) printf("%09d", a[i]);
}
 
 
 
BigInt Integer(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size()%9 != 0) s = '0'+s;
    for (int i=0;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}
 
BigInt Integer(char c[]) {
    string s = "";
    FOR(i,0,strlen(c)-1) s = s + c[i];
    return Integer(s);
}
 
BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}
 
BigInt Integer(int x) {
    return Integer((ll) x);
}
 
 
 
 
void operator >> (istream &in, BigInt &a) {
    string s;
    getline(cin, s);
    a = Integer(s);
}
 
void operator << (ostream &out, BigInt a) {
    Print(a);
}
BigInt operator + (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    FOR(i,0,max(a.size(), b.size())-1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.pb(carry%base);
        carry /= base;
    }
    if (carry) ans.pb(carry);
    Set(ans);
    return ans;
}
int main(){
	ten[0]=1;for(ll i=1;i<maxn;i++)ten[i]=(ten[i-1]*10)%p;
	string s;cin>>s;
	ll Num=0;
	for(ll i=0;i<s.size();i++){
		Num*=10;
		Num+=s[i]-'0';
		Num%=p;
		num[i]=Num;
	}
	for(ll i=s.size()-1;i>=0;i--){
		ll len=s.size()-i;
		check(make_seg(MP(0,len-1),MP(len,i-1),MP(i,s.size()-1)));
		check(make_seg(MP(0,len-2),MP(len-1,i-1),MP(i,s.size()-1)));
		check(make_seg(MP(0,i-len-1),MP(i-len,i-1),MP(i,s.size()-1)));
		check(make_seg(MP(0,i-len),MP(i-len+1,i-1),MP(i,s.size()-1)));
	}
	for(ll i=0;i<collision.size();i++){
		seg3 seg=collision[i];
		if((s[seg.a.F]=='0'&&seg.a.F!=seg.a.S)||(s[seg.b.F]=='0'&&seg.b.F!=seg.b.S)||(s[seg.c.F]=='0'&&seg.c.F!=seg.c.S))continue;
		BigInt A=Integer(s.substr(seg.a.F,seg.a.S-seg.a.F+1));
		BigInt B=Integer(s.substr(seg.b.F,seg.b.S-seg.b.F+1));
		BigInt C=Integer(s.substr(seg.c.F,seg.c.S-seg.c.F+1));
		if(A+B==C){
			cout<<A;
			cout<<'+';
			cout<<B;
			cout<<'=';
			cout<<C;
			return 0;
		}
	}
}
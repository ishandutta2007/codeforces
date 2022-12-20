// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int Dig=45e4,lim=5;

int Sum(int n){
    int tmp=0;
    while(n){
	tmp+=n%10;
	n/=10;
    }
    return tmp;
}

string N,ANS;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a;cin>>a;
    if(a*Sum(a)==1) return cout<<1<<endl,0;
    int A=1,S=0,dif2=a*Sum(a)-1;
    for(int i=0;A && i<Dig;i++){
	if(i>lim && N.back()!='9' && (Sum(a-A)+1)*a<=S+1 && (S+1-a*(Sum(a-A)+1))%dif2==0) {N[sz(N)-1]++;break;}
	A*=10;
	int x=A/a;
	S+=x;
	if(sz(N) || x) N.PB(char(x+'0'));
	A%=a;
    }
    if(A==0 && a>S) return cout<<-1<<endl,0;
    int dif=S+1-a*(Sum(a-A)+1);
    if(A==0) dif=S-a;
    if(dif==0) return cout<<N<<endl,0;
    int g=__gcd(dif,dif2);
    for(int i=0;i<(dif2/g);i++)
	ANS+=N+"00000";
    for(int i=0;i<(dif/g);i++)
	ANS+="100000";
    return cout<<ANS<<endl,0;
}
#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

ll k,d,t,w;
db s,ans,m;

int main(){
	cin>>k>>d>>t;
	w=(k/d+(k%d!=0))*d;
	s=db(1.0)*k/t+db(1.0)*(w-k)/2/t;
	m=1;
	ans=floor(m/s)*w;
	m-=floor(m/s)*s;
	if (m<=db(1.0)*k/t){
		ans+=m*t;
	} else{
		ans+=k;
		m-=db(1.0)*k/t;
		ans+=m*2*t;
	}
	printf("%.10lf\n",double(ans));
}
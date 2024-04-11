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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn=26;
const int inf=2e9;

#pragma GCC Optimize("Ofast")

map<pii,pii>mp;//S: mask // sum of first one
int a[3][maxn];
int p1,p2;

ll pw(ll a,ll b){
	if(b==0)return 1;
	return (b%2?a:1)*pw(a*a,b/2);
}
inline string code(int num){
	if(num==0)return "MW";
	if(num==1)return "LW";
	if(num==2)return "LM";
}
void print(int part1,int part2){
	REP(i,p1){
		cout<<code(part1%3)<<endl;
		part1/=3;
	}
	REP(i,p2){
		cout<<code(part2%3)<<endl;
		part2/=3;
	}
}

int main(){
	int n;cin>>n;
	REP(i,n)
		cin>>a[0][i]>>a[1][i]>>a[2][i];
	p1=(n/2);p2=(n/2)+(n%2);
	int tp1=pw(3,p1),tp2=pw(3,p2);
	REP(i,tp1){
		int cop=i,sm[3];
		memset(sm,0,sizeof sm);
		REP(j,p1){
			sm[(cop+1)%3]+=a[(cop+1)%3][j];
			sm[(cop+2)%3]+=a[(cop+2)%3][j];
			cop/=3;
		}
		int A=sm[1]-sm[0],B=sm[2]-sm[0];
		if(!mp.count(MP(A,B))||mp[MP(A,B)].S<sm[0]){
			mp[MP(A,B)]=MP(i,sm[0]);
		}
	}
	int ans=-inf,mask1,mask2;
	REP(i,tp2){
		int cop=i,sm[3];
		memset(sm,0,sizeof sm);
		REP(j,p2){
			sm[(cop+1)%3]+=a[(cop+1)%3][p1+j];
			sm[(cop+2)%3]+=a[(cop+2)%3][p1+j];
			cop/=3;
		}
		int A=sm[0]-sm[1],B=sm[0]-sm[2];
		if(mp.count(MP(A,B))){
			pii mpp=mp[MP(A,B)];
			if(ans<(sm[0]+mpp.S)){
				ans=sm[0]+mpp.S;
				mask1=mpp.F;
				mask2=i;
			}
		}
	}
	if(ans!=(-inf))
		print(mask1,mask2);
	else
		cout<<"Impossible";
}
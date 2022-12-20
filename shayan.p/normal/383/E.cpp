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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e4+10;
const ll MAX=(1<<24);

string s[maxn];
ll esh_1[25],esh_2[25][25],esh_3[25][25][25];
ll one[MAX],two[MAX],three[MAX];
bool st[25];

int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>s[i];
	FOR(m1,0,23){
		REP(i,n){
			st[s[i][0]-'a']=1;
			st[s[i][1]-'a']=1;
			st[s[i][2]-'a']=1;
			if(st[m1])
				esh_1[m1]++;
			st[s[i][0]-'a']=0;
			st[s[i][1]-'a']=0;
			st[s[i][2]-'a']=0;
		}
	}
	FOR(m1,0,23){
		FOR(m2,m1+1,23){
			REP(i,n){
				st[s[i][0]-'a']=1;
				st[s[i][1]-'a']=1;
				st[s[i][2]-'a']=1;
				if(st[m1]&&st[m2])
					esh_2[m1][m2]++;
				st[s[i][0]-'a']=0;
				st[s[i][1]-'a']=0;
				st[s[i][2]-'a']=0;
			}
		}
	}
	FOR(m1,0,23){
		FOR(m2,m1+1,23){
			FOR(m3,m2+1,23){
				REP(i,n){
					st[s[i][0]-'a']=1;
					st[s[i][1]-'a']=1;
					st[s[i][2]-'a']=1;
					if(st[m1]&&st[m2]&&st[m3])
						esh_3[m1][m2][m3]++;
					st[s[i][0]-'a']=0;
					st[s[i][1]-'a']=0;
					st[s[i][2]-'a']=0;
				}
			}
		}
	}
	
	ll arr[24];
	FOR(i,1,MAX-1){// for 0 they are all zero
		ll cop=i;
		ll ff=-1,ss,SZ=0;
		FOR(j,0,23){
			arr[j]=(cop%2);
			if(arr[j]){
				if(ff==-1)ff=j;
				ss=j;
				SZ++;
			}
			cop=(cop>>1);
		}
		// kam arzesh tarin ragham back hast
		one[i]=esh_1[ff];
		if(SZ<2)continue;
		two[i]=two[i^(1<<ss)]+esh_2[ff][ss];
		if(SZ<3)continue;
		three[i]=three[i^(1<<ss)];
		FOR(j,ff+1,ss-1){
			if(arr[j])
			three[i]+=esh_3[ff][j][ss];
		}
	}
	ll ans=0;
	FOR(i,0,MAX-1){
		ll cop=i;
		ll num=0;
		while(cop>0){
			num+=one[cop];
			num-=two[cop];
			num+=three[cop];
			cop-=(cop & -cop);
		}
		ans^=(num*num);
	}
	cout<<ans;
}
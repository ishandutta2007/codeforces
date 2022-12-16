// new day,new strength,new thougts
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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll NUM=25;

#pragma GCC Optimize("Ofast")

char ch[50][50];
ll arr[4];
int main(){
	REP(i,4){
		cin>>arr[i];
		arr[i]--;
	}
		
	REP(q,2){
		REP(w,2){
			REP(i,NUM){
				REP(j,NUM){
					ch[(NUM*q)+i][(NUM*w)+j]='A'+(2*q)+w;
					if((i%2)&&(j%2)&&arr[(2*(1-q))+(1-w)]){
						arr[(2*(1-q))+(1-w)]--;
						ch[(NUM*q)+i][(NUM*w)+j]='A'+(2*(1-q))+(1-w);
					}
				}
			}
		}
	}
	cout<<(2*NUM)<<" "<<(2*NUM)<<endl;
	REP(i,(2*NUM)){
		REP(j,(2*NUM))
			cout<<ch[i][j];
		cout<<endl;
	}
}
// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

string s[2];

deque<char> Get(){
    cin>>s[0]>>s[1];
    deque<char>v1,v2;
    v1.clear();
    v2.clear();
    v1.PB(s[0][0]);
    v1.PB(s[0][1]);
    v1.PB(s[1][1]);
    v1.PB(s[1][0]);
    bool start=0;
    REP(i,8){
	if(start&&v1[i%4]!='X')
	    v2.PB(v1[i%4]);
	start^=(v1[i%4]=='X');
    }
    while(v2.front()!='A'){
	v2.PB(v2.front());
	v2.POF();
    }
    return v2;
}

int main(){
       cout<<(Get()==Get()?"YES":"NO");
}
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define B 1000000
int m,t=0;
vector<int> so;
bool go[1141919];
vector<lint> ya[89381];
map<lint,int> prime;
map<lint,int> me[89381];
bool isprime(lint a){
    rep(i,m){
        if(a/so[i]<so[i]) return true;
        if(a%so[i]==0) return false;
    }
    return true;
}
void cal(lint now,int p){
    if(p>=m){
        //cout<<now<<endl;
        if(now==1) t++;
        if(now>(lint)B) t+=prime[now-1];
        return;
    }
    //if(me[p].count(now)>0) return me[p][now];
    lint ret=0;
    rep(i,ya[p].size()){
        if(ya[p][i]>now) break;
        lint ne=now/ya[p][i];
        if(now==ne*ya[p][i]) cal(ne,p+1);
    }
    cal(now,p+1);
    //return me[p][now]=ret;
    //return ret;
}
int main()
{
    memset(go,false,sizeof(go));
    REP(i,2,B+1){
        if(go[i]) continue;
        so.pb(i);
        for(int j=i+i;j<=B;j+=i) go[j]=true;
    }
    //cout<<so.size()<<endl;
    lint n;cin>>n;
    m=so.size();
    REP(i,1,B+1){
        if(n%i==0 && n/i>(lint)B){
            if(isprime(n/i-1)) prime[n/i-1]=1;
        }
    }
    rep(i,m){
        lint now=so[i];
        while(now<n){
            ya[i].pb(now+1);now*=so[i];
        }
    }
    //cout<<t<<endl;
    reverse(ya,ya+m);
    cal(n,0);
    cout<<t<<endl;
}
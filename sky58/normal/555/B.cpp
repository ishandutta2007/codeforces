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
typedef pair<lint,int> pint;
typedef pair<lint,lint> plint;
typedef pair<plint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<tint> gap;
vector<pint> bri;
priority_queue<pint> q;
lint L[252521],R[252521];
int out[252521];
int main()
{
    int n,m;lint a;
    scanf("%d %d",&n,&m);
    rep(i,n){
        scanf("%I64d %I64d",&L[i],&R[i]);
    }
    rep(i,n-1) gap.pb(mp(mp(L[i+1]-R[i],R[i+1]-L[i]),i));
    rep(i,m){
        scanf("%I64d",&a);bri.pb(mp(a,i));
    }
    sort(All(gap));sort(All(bri));
    memset(out,-1,sizeof(out));
    //rep(i,n-1) cout<<gap[i].fi.fi<<' '<<gap[i].fi.se<<' '<<gap[i].se<<endl;
    //cout<<bri[0].fi<<endl;
    int it=0;
    rep(i,m){
        //cout<<i<<endl;
        lint len=bri[i].fi;
        while(gap[it].fi.fi<=len && it<n-1){
            q.push(mp(-gap[it].fi.se,gap[it].se));
            it++;
        }
        //cout<<it<<endl;
        if(!q.empty()){
            pint p=q.top();
            //cout<<-p.fi<<' '<<p.se<<endl;
            if(-p.fi<len){
                cout<<"No"<<endl;return 0;
            }
        }
        if(q.empty()) continue;
        pint p=q.top();q.pop();
        out[p.se]=bri[i].se;
    }
    if(!q.empty()){
        cout<<"No"<<endl;return 0;
    }
    //cout<<out[0]<<endl;
    rep(i,n-1){
        if(out[i]<0){
            cout<<"No"<<endl;return 0;
        }
    }
    printf("Yes\n");
    rep(i,n-1){
        if(i<n-2) printf("%d ",out[i]+1);
        else printf("%d\n",out[i]+1);
    }
}
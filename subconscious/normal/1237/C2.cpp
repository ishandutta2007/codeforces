#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
const ld eps=1e-9;
const int N=(int)2e6+5;
map<pair<int,int>,vector<pair<int,int>>>p;
map<int,vector<pair<int,int>>>p2;
int sta[N],top,n;
int main(){
    scanf("%d",&n);
    rep(i,n){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        p[mp(x,y)].pb(mp(z,i));
    }
    for(auto&v:p){
        auto&vec=v.second;
        sort(vec.begin(),vec.end());
        for(int i=0,mx=vec.size();i+1<mx;i+=2)
            printf("%d %d\n",vec[i].second,vec[i+1].second);
        if(vec.size()%2==1)p2[v.first.first].pb(mp(v.first.second,vec.back().second));
    }
    for(auto&v:p2){
        auto&vec=v.second;
        sort(vec.begin(),vec.end());
        for(int i=0,mx=vec.size();i+1<mx;i+=2)
            printf("%d %d\n",vec[i].second,vec[i+1].second);
        if(vec.size()%2==1)sta[++top]=vec.back().second;
    }
    rep(i,top/2)printf("%d %d\n",sta[i*2-1],sta[i*2]);
    return 0;
}
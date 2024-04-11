#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e5+5;
const ll inf=1e18;
int T,n;
int te[N],pos[26];
char s[N],t[N];
void add(int p,int x){
    for(;p<=n;p+=p&-p)
        te[p]+=x;
}
int que(int p){
    int s=0;
    for(;p;p-=p&-p)
        s+=te[p];
    return s;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        ll ans=inf;
        for(int i=0;i<26;++i){
            pos[i]=1;
            while(pos[i]<=n&&s[pos[i]]!='a'+i)++pos[i];
        }
        rep(i,n)te[i]=0;
        ll now=0;
        rep(i,n){
            int mi=1e9,is=-1;
            for(int j=0;'a'+j<t[i];++j)if(pos[j]!=n+1){
                int stp=pos[j]-1-que(pos[j]);
                if(mi>stp)mi=stp,is=j;
            }
            if(is!=-1){
                ans=min(ans,now+mi);
            }
            if(pos[t[i]-'a']==n+1)break;
            now+=pos[t[i]-'a']-1-que(pos[t[i]-'a']);
            add(pos[t[i]-'a'],1);
            pos[t[i]-'a']++;
            while(pos[t[i]-'a']<=n&&s[pos[t[i]-'a']]!=t[i])++pos[t[i]-'a'];
        }
        if(ans==inf)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}
/*


*/
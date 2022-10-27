#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int n,m,q;
LL dp[1<<13][13];
vector<int> submask[1<<13];
int lg[1<<13],a[105],b[105],c[105],u[105],v[105];
void init() {
    for(int i=0;i<13;i++) lg[1<<i]=i;
    for(int mask=0;mask<1<<13;mask++) {
        //printf("mask=%d\n", mask);
        vector<int> v;v.clear();
        for(int i=0;i<13;i++) if((mask>>i)&1) v.push_back(i);
        for(int s=0;s<(1<<v.size());s++) {
            int newmask=0;
            int tmp=s;
            while(tmp) {
                newmask |= (1<<v[lg[tmp&(-tmp)]]);
                tmp -= tmp&(-tmp);
            }
            submask[mask].push_back(newmask);
        }
    }
}
int main() {
    init(); scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&u[i],&v[i]);u[i]--;v[i]--;
    }
    for(int i=1;i<=q;i++) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);a[i]--;b[i]--;c[i]--;
    }

    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    for(int mask=1;mask<1<<n;mask++){
        for(int root=0;root<n;root++) if((mask>>root)&1) {  
            if((1<<root) == mask) continue; 
            int mn_pos=-1;
            for(int i=0;i<n;i++) if((mask>>i)&1 && i!=root) {
                mn_pos = i; break;
            }
            for(auto newmask: submask[mask]) if(((newmask>>mn_pos)&1) && ((newmask>>root)&1) ==0) {
                //printf("mask=%d, newmask=%d, root=%d\n", mask,newmask,root);
                bool ok=1; int cnt=0,paigulong=-1;
                for(int i=1;i<=m;i++) {
                    if(u[i]!=root&&v[i]!=root&& ((newmask>>u[i])&1)==1 && (((mask^newmask)>>v[i])&1)==1 ) ok=0;
                    if(u[i]!=root&&v[i]!=root&& ((newmask>>v[i])&1)==1 && (((mask^newmask)>>u[i])&1)==1 ) ok=0;
                    //printf("ok=%d\n", ok);
                    if(u[i]==root && (newmask>>v[i])&1) cnt++, paigulong=v[i];
                    if(v[i]==root && (newmask>>u[i])&1) cnt++, paigulong=u[i];
                }
                for(int i=1;i<=q;i++) {
                    if(c[i]==root) {
                        if( ((newmask>>a[i])&1) && ((newmask>>b[i])&1) )
                            ok = 0;
                    }
                    if((newmask>>c[i])&1) {
                        if(!(newmask>>a[i]&1) || !(newmask>>b[i]&1) )
                            ok = 0;
                    }
                }
                if(cnt>=2) ok=0;
                if(ok==0) continue;
                if(cnt==1) dp[mask][root] += dp[newmask^mask][root] * dp[newmask][paigulong];
                if(cnt==0) {
                    //printf("gou\n");
                    for(int i=0;i<n;i++)if((newmask>>i)&1){
                        //printf("dp[%d][%d] += dp[%d][%d](%d)*dp[%d][%d](%d)\n", mask,root,newmask^mask,root,dp[newmask^mask][root],newmask,i,dp[newmask][i]);
                        dp[mask][root] += dp[newmask^mask][root] * dp[newmask][i];
                    }
                }
            }
            //printf("dp[%d][%d]=%d\n", mask,root,dp[mask][root]);
        }
    }
    cout << dp[(1<<n)-1][0] << endl;
}
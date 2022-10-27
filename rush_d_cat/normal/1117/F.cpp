#include <iostream>
using namespace std;
const int N=100000+10;
char s[N];
int n,p,mp[20][20],cnt[20];
int ban[1<<17],gg[1<<17];

void solve(int x,int y){
    for(int i=0;i<1<<p;i++) ban[i]=0;
    int mask=0, has=0; 
    for(int i=1;i<=n;i++){
        if(s[i]=='a'+x){
            if (x==y) {
                if(has) {
                    //printf("x=%d,y=%d,mask=%d\n", x,y,mask);
                    ban[mask] ++;
                }
            }
            mask=0;
            has=1;
        } else if(s[i]=='a'+y){
            if(has) {
                //printf("x=%d,y=%d,m=%d\n", x,y,mask);
                ban[mask]++;
            }
        } else {
            mask |= 1<<(s[i]-'a');
        }
    }

    if (x != y) {
        swap(x,y);
        mask=0,has=1;
        for(int i=1;i<=n;i++){
            if(s[i]=='a'+x){
                mask=0; has=1;
            } else if(s[i]=='a'+y){
                if(has) {
                    //printf("x=%d,y=%d,mask=%d\n", x,y,mask);
                    ban[mask]++;
                }
            } else {
                mask |= 1<<(s[i]-'a');
            }
        }    
    }   
    ban[0] = 0;
    for (int bit = 0; bit < p; bit ++) {
        for (int i = 1; i < (1<<p); i ++) {
            if ( ((i>>bit) & 1) == 1 )
                ban[i] += ban[i^(1<<bit)];
        }
    }    

    for (int i=0;i<1<<p;i++) {
        if(ban[i] && ((i>>x&1)==0) && ((i>>y&1)==0) ) {
            gg[i] = 1;
            //printf("gg = %d\n", i);
        }
    }
}

int dp[1<<17],vis[1<<17];
void solve(int mask) {
    if(vis[mask]) return;
    dp[mask]=1; vis[mask]=1;
    for(int i=0;i<p;i++){
        if(((mask>>i)&1) == 0) {
            if(gg[mask^(1<<i)] == 0) {
                solve(mask^(1<<i));
            }
        }
    }
}

int main(){
    scanf("%d%d%s",&n,&p,s+1);
    for(int i=1;i<=n;i++) {
        cnt[s[i]-'a'] ++;
    }
    for(int i=0;i<p;i++)for(int j=0;j<p;j++){
        scanf("%d",&mp[i][j]);
        if(mp[i][j]==0 && i<=j) solve(i,j);
    }
    solve(0);
    int ans = N;
    for(int i=0;i<(1<<p);i++) {
        if(dp[i] == 1) {
            int tmp=0;
            for(int j=0;j<p;j++){
                if((i>>j&1) == 0) tmp += cnt[j];
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
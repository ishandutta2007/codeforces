#include <bits/stdc++.h>
using namespace std;
const int N = 2000000 + 10;
int a[N],b[N],cnt[N],vis[N],sum[N];
vector<int> v;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]), b[a[i]]++;
        for(int i=1;i<=n;i++) if(b[i]) v.push_back(b[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int x: v){
//            cout<<x<<":";
            for(int l=1,r;l<=x;l=r+1){
                r = x / (x / l);
                cnt[x/l+1] ++;
//                cout<<x/l+1<<' ';
                vis[x/l+1] = 1;
            }
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    int t = x / i;
                    if(vis[t]==0) cnt[t]++;
//                    if(vis[t]==0) cout<<t<<' ';
                    if(i*i!=x){
                        t = i;
                        if(vis[t]==0) cnt[t]++;
//                        if(vis[t]==0) cout<<t<<' ';
                    }
                }
            }
//            cout<<endl;
            for(int l=1,r;l<=x;l=r+1){
                r = x / (x / l);
                vis[x/l+1] = 0;
            }
        }
        int s = 0;
        for(int i=1;i<=n+1;i++){
            if(cnt[i]==v.size()) s = i;
//            if(cnt[i]==v.size()) cout<<i<<endl;
        }
//        cout<<s<<endl;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += (b[i]+s-1)/s;
        }
        printf("%d\n",ans);
        v.clear();
        for(int i=1;i<=n+1;i++) cnt[i] = vis[i] = b[i] = sum[i] = 0;
    }
}
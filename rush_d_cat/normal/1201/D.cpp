#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
typedef long long LL;
using namespace std;
const int N = 200000 + 10;
int n,m,k,q;
vector<int> vec[N],row[N],v;
int mn[N],mx[N];
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
map< pair<int,int>,LL > dp;
int main() {
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<N;i++){
        mn[i]=N,mx[i]=0;
    }
    int mxr = 0;
    for(int i=1;i<=k+1;i++){
        int r,c; 
        if(i<=k)scanf("%d%d",&r,&c);
        else r=1,c=1;
        
        vec[r].push_back(c);
        mn[r]=min(mn[r],c);
        mx[r]=max(mx[r],c);
        mxr = max(mxr, r);
    }
    for(int i=1;i<=q;i++){
        int x; scanf("%d",&x); v.push_back(x);
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    int las=0; mn[0]=mx[0]=0; row[0].push_back(1);
    for(int i=1;i<=n;i++){
        if(vec[i].size()) {
            int p1 = id(mn[i]);
            int p2 = id(mx[i]);
            for(int j=-1;j<=1;j++){
                if(p1+j<=v.size() && p1+j>=1) row[i].push_back(v[p1+j-1]);
            }
            for(int j=-1;j<=1;j++){
                if(p2+j<=v.size() && p2+j>=1) row[i].push_back(v[p2+j-1]);
            }
            if(i==mxr) {
                row[i].push_back(mn[i]); row[i].push_back(mx[i]);
            }
            sort(row[i].begin(), row[i].end()); 
            row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
            for(int j=0;j<row[i].size();j++) {
                for(int k=0;k<row[las].size();k++){
                    int tmp1 = abs(row[las][k] - mn[i]);
                    if (row[i][j] > mx[i]) tmp1 += row[i][j] - mn[i];
                    else tmp1 += mx[i] - mn[i] + (mx[i] - row[i][j]);
                    
                    int tmp2 = abs(row[las][k] - mx[i]);
                    if (mn[i] > row[i][j]) tmp2 += mx[i] - row[i][j];
                    else tmp2 += mx[i] - mn[i] + row[i][j] - mn[i];

                    if (dp[make_pair(i,row[i][j])] == 0)
                        dp[make_pair(i,row[i][j])] = dp[make_pair(las,row[las][k])] + i - las + min(tmp1,tmp2);
                    else
                        dp[make_pair(i,row[i][j])] = min(dp[make_pair(las,row[las][k])] + i - las + min(tmp1,tmp2), dp[make_pair(i,row[i][j])]);
                    //printf("(%d, %lld) %d\n", i,row[i][j],dp[make_pair(i,row[i][j])]-1);
                }
            }
            las=i;
        }
    }
    LL ans=1e18;
    for(auto c: row[mxr]) {
        ans = min(ans, dp[make_pair(mxr, c)]-1);
    }
    cout << ans << endl;
}
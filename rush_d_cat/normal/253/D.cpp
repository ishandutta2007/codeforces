// 2:23
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=422;
int n,m,k,sum[N][N]; char s[N][N];
vector<int> v[30];
int c[N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) sum[i][j]=sum[i-1][j]+(s[i][j]=='a'?1:0);
    long long ans=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        for(int ch=0;ch<26;ch++)v[ch].clear();
        int bg[26]={0},ed[26]={0},cnt[26]={0};
        for(int x=1;x<=m;x++){
            c[x]=sum[j][x]-sum[i-1][x];
            if(s[i][x] == s[j][x]) v[s[i][x]-'a'].push_back(x);
        }
        for(int x=1;x<=m;x++) c[x]+=c[x-1];

        for(int r=1,l=0;r<=m;r++) {
            while(c[r]-c[l]>k) ++l;
            if(l==r) continue;
            // (l,r]
            //printf("(%d,%d]\n", l,r);
            if(s[i][r]==s[j][r]) {
                int ch=s[i][r]-'a';
                ed[ch]=cnt[ch]++;
                while(bg[ch]<v[ch].size() && v[ch][bg[ch]] <= l) bg[ch]++;
                ans += max(ed[ch]-bg[ch],0);
            }
        }
    }
    printf("%lld\n", ans);
}
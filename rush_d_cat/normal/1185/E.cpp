#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 2000 + 10;
int T,n,m;
char s[N][N]; int d[30][30],has[30];
vector< pair<int,int> > vec[30];
vector< int > ans[30];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%s",s[i]+1);
        }

        for(int i=0;i<30;i++){
            ans[i].clear(); vec[i].clear(); has[i]=0;
            for(int j=0;j<30;j++){
                d[i][j]=i==j?0:1e9;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i][j]!='.'){
                    vec[s[i][j]-'a'].push_back(make_pair(i,j));
                }
            }
        }
        
        bool gg=0;
        for(int i=0;i<26;i++){
            if(vec[i].size() == 0) continue;

            int mxx=0,mnx=N,mxy=0,mny=N;
            for(auto p: vec[i]) {
                mxx=max(mxx,p.first);
                mxy=max(mxy,p.second);
                mnx=min(mnx,p.first);
                mny=min(mny,p.second);
            }
            //printf("%d %d %d %d\n", mnx,mxx,mny,mxy);
            ans[i].push_back(mnx); ans[i].push_back(mny);
            ans[i].push_back(mxx); ans[i].push_back(mxy);
            if(mxx!=mnx && mxy!=mny) {
                gg=1;  break;
            }
            if(mxx == mnx) {
                for(int j=mny;j<=mxy;j++) {
                    if(s[mxx][j] == '.'){
                        gg=1;
                        break;
                    }
                    if(s[mxx][j] != 'a'+i) {
                        d[i][s[mxx][j]-'a'] = 1;
                    }
                }
            } else {
                for(int j=mnx;j<=mxx;j++){
                    if(s[j][mny] == '.') {
                        gg=1; break;
                    }
                    if(s[j][mny] != 'a'+i) {
                        d[i][s[j][mny]-'a'] = 1;
                    }
                }
            }
        }
        if (gg) {
            printf("NO\n");
            continue;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    d[i][j]=min(d[i][k]+d[k][j], d[i][j]);
                }
            }
        }

        int cnt=0; 
        pair<int,int> pos;
        for(int i=0;i<26;i++){
            if(vec[i].size()) {
                cnt=i+1;
                pos=vec[i][0];
                for(int j=i+1;j<26;j++){
                    if(d[j][i] < 1e9) {
                        gg=1;
                    } 
                }
            }
        }
        printf("%s\n", gg?"NO":"YES");
        if(!gg) {
            printf("%d\n", cnt);
            for(int i=0;i<cnt;i++){
                if(ans[i].size()) {
                    for(auto x: ans[i]) {
                        printf("%d ", x);
                    }
                    printf("\n");
                } else {
                    printf("%d %d %d %d\n", pos.first,pos.second,pos.first,pos.second);
                }
                
            }       
        }
    }
}
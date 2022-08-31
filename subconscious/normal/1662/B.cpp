#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1005;
int a[3][30],n;
char s[N];
vi v[3],r[3];
vector<pr>ans;
int main() {
    for(int i=0;i<3;++i){
        scanf("%s",s+1);n=strlen(s+1);
        rep(j,n)++a[i][s[j]-'A'+1];
    }
    rep(now,26){
//        for(int i=0;i<3;++i)printf("%d ",a[i][now]);
//        puts("");
        bool flag=0;
        for(int i=0;i<3;++i)if(a[i][now]>a[(i+1)%3][now]+a[(i+2)%3][now]){
                while(a[i][now]&&a[(i+1)%3][now])v[(i+2)%3].pb(now),--a[i][now],--a[(i+1)%3][now];
                while(a[i][now]&&a[(i+2)%3][now])v[(i+1)%3].pb(now),--a[i][now],--a[(i+2)%3][now];
            flag=1;break;
        }
        if(!flag){
            for(;;){
                int mi=0;
                for(int i=0;i<3;++i)if(a[i][now]<=a[(i+1)%3][now]&&a[i][now]<=a[(i+2)%3][now]){
                    mi=i;
                }
                if(a[(mi+1)%3][now]&&a[(mi+2)%3][now]){
                    v[mi].pb(now);--a[(mi+1)%3][now];--a[(mi+2)%3][now];
                }else{
                    break;
                }
            }
        }
        for(int i=0;i<3;++i)while(a[i][now])r[i].pb(now),--a[i][now];
    }
    for(int i=0;i<3;++i){
        while(v[i].size()>0&&r[i].size()>0){
            ans.pb(mp(v[i].back(),r[i].back()));
            v[i].pop_back(),r[i].pop_back();
        }
        while(v[i].size()>0){
            r[(i+1)%3].pb(v[i].back());
            r[(i+2)%3].pb(v[i].back());
            v[i].pop_back();
        }
    }

    for(;;){
        int mi=0;
        for(int i=0;i<3;++i)if(r[i].size()<=r[(i+1)%3].size()&&r[i].size()<=r[(i+2)%3].size()){
                mi=i;
            }
        if(r[(mi+1)%3].size()&&r[(mi+2)%3].size()){
            ans.pb(mp(r[(mi+1)%3].back(),r[(mi+2)%3].back()));
            r[(mi+1)%3].pop_back();
            r[(mi+2)%3].pop_back();
        }else{
            break;
        }
    }
    for(int i=0;i<3;++i)while(r[i].size()){
        ans.pb(mp(1,r[i].back()));
        r[i].pop_back();
    }
    printf("%d\n",ans.size());
    for(pr p:ans)printf("%c%c\n",p.st+'A'-1,p.nd+'A'-1);
    return 0;
}
/*
2 1 4
1 2
 */
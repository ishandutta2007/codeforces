#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=998244353;
const ld eps=1e-10;
char s[N],ans[N];
int cnt[N],T,n,top;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%s",s+1);n=strlen(s+1);
        rep(i,n)++cnt[s[i]-'a'+1];

        top=0;
        bool flag=0;
        rep(i,26)if(cnt[i]==1){
            ans[++top]='a'+i-1,--cnt[i];
            while(top<n){
                rep(j,26)if(cnt[j]>0){
                    --cnt[j];ans[++top]='a'+j-1;break;
                }
            }
            flag=1;break;
        }
        if(flag==0){
            rep(fs,26)if(cnt[fs]>0){
                if(cnt[fs]==n){
                    rep(i,n)ans[++top]='a'+fs-1,--cnt[fs];
                    break;
                }
                if(cnt[fs]>=2&&n-cnt[fs]>=cnt[fs]-2){
                    ans[++top]='a'+fs-1;--cnt[fs];
                    ans[++top]='a'+fs-1;--cnt[fs];
                    while(cnt[fs]>0){
                        for(int j=fs+1;j<=26;++j)if(cnt[j]>0){
                            --cnt[j];ans[++top]='a'+j-1;break;
                        }
                        ans[++top]='a'+fs-1;--cnt[fs];
                    }
                    while(top<n){
                        rep(j,26)if(cnt[j]>0){
                            --cnt[j];ans[++top]='a'+j-1;break;
                        }
                    }
                    break;
                }

                int ne=fs+1;while(cnt[ne]==0)++ne;
                ans[++top]='a'+fs-1;--cnt[fs];
                ans[++top]='a'+ne-1;--cnt[ne];
                
                bool flag=0;
                for(int i=ne+1;i<=26;++i)if(cnt[i]>0){
                    while(cnt[fs]>0){
                        ans[++top]='a'+fs-1;--cnt[fs];
                    }
                    ans[++top]='a'+i-1;--cnt[i];
                    while(top<n){
                        rep(j,26)if(cnt[j]>0){
                            --cnt[j];ans[++top]='a'+j-1;break;
                        }
                    }
                    flag=1;break;
                }
                if(flag)break;
                while(cnt[ne]>0){
                    ans[++top]='a'+ne-1;--cnt[ne];
                }
                while(cnt[fs]>0){
                    ans[++top]='a'+fs-1;--cnt[fs];
                }
                break;
            }
        }

        ans[top+1]='\0';
        puts(ans+1);
    }
    return 0;
}
/*
*/
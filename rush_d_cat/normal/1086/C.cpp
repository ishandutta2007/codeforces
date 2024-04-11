#include <iostream>
#include <cstring>
using namespace std;
const int N=1000000+10;

int t,k,n;char s[N],a[N],b[N];
int f[26];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%s%s%s",&k,s+1,a+1,b+1); n=strlen(s+1);
        for(int i=0;i<k;i++) f[i]=-1;
        for(int i=1;i<=n;i++) s[i]-='a',a[i]-='a',b[i]-='a';

        int pos=-1,to=-1;
        for(int i=1;i<=n;i++){
            if(f[s[i]] == -1) {
                bool vis[26]={0};
                for(int j=0;j<k;j++) {
                    if(f[j]!=-1) vis[f[j]]=1;
                }
                for(int j=k-1;j>=a[i]+1;j--){
                    if(vis[j]==0) {
                        pos=i,to=j;
                    }
                }
                if(vis[a[i]]) break;
                f[s[i]]=a[i];

            } else {
                if(f[s[i]]<a[i]) break;
                if(f[s[i]]>a[i]) {
                    pos=i;to=f[s[i]];break;
                }
            }
            if(i==n) pos=n,to=a[i];
        }
        //printf("# pos = %d, to = %d\n", pos, to);
        if(pos==-1) {
            printf("NO\n"); continue;
        }

        for(int i=0;i<k;i++) f[i]=-1;
        for(int i=1;i<pos;i++) {
            f[s[i]]=a[i];
        }
        f[s[pos]]=to;
        
        bool vis[26]={0};
        for(int i=0;i<k;i++) if(f[i]!=-1) vis[f[i]]=1;
        for(int i=pos+1;i<=n;i++) {
            if(f[s[i]]==-1) {
                for(int j=0;j<k;j++)
                    if(vis[j]==0) {
                        f[s[i]]=j;vis[j]=1; break;
                    }
            }
        }

        for(int i=0;i<k;i++){
            if(f[i]==-1) {
                for(int j=0;j<k;j++){
                    if(vis[j]==0){
                        f[i]=j; vis[j]=1; break;
                    }
                }
            }
        }

        for(int i=1;i<=n;i++) s[i]=f[s[i]];
        int x=0; while(x<=n && s[x]==b[x]) ++x;
        if(x<=n && s[x]>b[x]) {
            printf("NO\n"); continue;
        }
        printf("YES\n");
        for(int i=0;i<k;i++) printf("%c", 'a'+f[i]);
        printf("\n");
    }
}

/*

*/
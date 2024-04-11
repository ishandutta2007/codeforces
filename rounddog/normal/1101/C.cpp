#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
int a[maxn],T,l[maxn],r[maxn],s[maxn],t[maxn],n,m;
map <int,int> f;
set <int> S;

int main(){
    cin >> T;
    while (T--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> l[i] >> r[i];
        S.clear(); int cnt=0; f.clear();
        for (int i=1;i<=n;i++) S.insert(l[i]),S.insert(r[i]);
        for (auto w=S.begin();w!=S.end();w++) f[*w]=++cnt;
        for (int i=1;i<=n;i++) l[i]=f[l[i]],r[i]=f[r[i]];
        for (int i=0;i<=1+cnt;i++) s[i]=t[i]=0;
        for (int i=1;i<=n;i++) s[r[i]]++,t[l[i]]++;
        for (int i=2;i<=cnt;i++) s[i]+=s[i-1];
        for (int i=cnt;i>=2;i--) t[i-1]+=t[i];
        int ans=-1;
        for (int i=1;i<cnt;i++) if (s[i]+t[i+1]==n) ans=i;
        if (ans==-1) {puts("-1");continue;}
        for (int i=1;i<=n;i++) if (r[i]<=ans) printf("1 "); else printf("2 ");
        puts("");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
struct base{
    int r[30];
    void ins(int x){
        for (int i=30;i>=0;i--)
            if (x>>i){
                if (!r[i]) r[i]=x;
                x^=r[i];
                if (!x) break;
            }
    }
}c;

int main(){
    cin >> n; int x=0;ans=0;
    for (int i=1;i<=n;i++){
        cin >> k; x^=k;
        c.ins(k);
    }
    if (x){
        for (int i=0;i<30;i++) if (c.r[i]) ans++;
        printf("%d\n",ans);
    } else puts("-1");
    return 0;
}
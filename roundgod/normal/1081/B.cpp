#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
int a[maxn],n,cnt[maxn],ans[maxn],cc;
vector <int> h[maxn];

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i]; a[i]=n-a[i];
        cnt[a[i]]++;
        h[a[i]].push_back(i);
    }
    for (int i=1;i<=n;i++) if (cnt[i]%i) {puts("Impossible");return 0;}
    cc=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<h[i].size();j++) ans[h[i][j]]=cc+j/i;
        cc+=h[i].size()/i;
    }
    puts("Possible");
    for (int i=1;i<=n;i++) cout << ans[i] << ' ' ; cout << endl;
}
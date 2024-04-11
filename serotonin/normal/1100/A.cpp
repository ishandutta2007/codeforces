#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

int a[105];

int main()
{
    int i,j,n,b,k,tot=0,e,s;
    cin >> n >> k;
    for(i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]>0) tot++;
    }
    int ans=0;
    for(b=0; b<k; b++) {
        s=0,e=0;
        for(j=0; b+j<n; j+=k) {
            if(a[b+j]>0) s++;
            else e++;
        }
        int now=abs((tot-s)-(n-tot-e));
        ans=max(ans,now);
    }
    cout << ans;
}
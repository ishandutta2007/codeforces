#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            cin>>a[i];
        }
        int x=m-1;
        k=min(k,m-1);
        int numDef = x - k;
        if (numDef<0)numDef=0;
        int ret=0;
        for (int l=0;l<=k;l++) {
            int r = k - l;
            int L = 1+l;
            int R = n-r;
            int cur = 1e9;
            for (int j=0;j<=numDef;j++){
                cur = min(cur, max(a[L+j],a[R-(numDef-j)]));
            }
            ret=max(ret,cur);

        }
        cout<<ret<<endl;
    }
}
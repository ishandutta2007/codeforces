#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int peak[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) {
            if (i && i<n && a[i] > a[i-1] && a[i]>a[i+1]) peak[i]=1;
            else peak[i]=0;
            peak[i]+=peak[i-1]; 
        }
        int ret=-1, best=0;
        int l=1, r = k;
        while(r<=n){
            if (peak[r-1] - peak[l] > ret) {
                ret = peak[r-1] - peak[l];
                best = l;
            }
            l++,r++;
        }
        cout<<ret+1<<' '<<best<<endl;
    }
}
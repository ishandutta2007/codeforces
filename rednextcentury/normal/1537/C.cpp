#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int b[1000000];
int getSol(int i, bool build_sol){

}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a,a+n);
        int mn = 1e9;
        for (int i=1;i<n;i++) mn = min(mn, a[i]-a[i-1]);
        int sol = 0;
        for (int i=0;i+1<n;i++) {
            if (a[i+1]-a[i]>mn)continue;
            b[1] = a[i];
            b[n] = a[i+1];
            int cur=2;
            for (int j=i+2;j<n;j++) b[cur++] = a[j];
            for (int j=0;j<i;j++) b[cur++] = a[j];
            break;
        }
        for (int i=1;i<=n;i++) cout<<b[i]<<' ';
        cout<<endl;
    }
}
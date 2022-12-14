#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5001];
int numGreater[5005][5001];
int numLess[5005][5001];
ll get(int i,int j){
    ll ret = -numGreater[i-1][a[i]+1] - numLess[i+1][a[i]-1];
    ret -= numGreater[j-1][a[j]+1] + numLess[j+1][a[j]-1];
    ret+=numGreater[i-1][a[j]+1] + numLess[i+1][a[j]-1];
    ret+=numGreater[j-1][a[i]+1] + numLess[j+1][a[i]-1];
    if (a[i]>a[j])ret++;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        for (int j=0;j<n;j++){
            numGreater[i][j] = numGreater[i-1][j];
        }
        for (int j=0;j<=a[i];j++) numGreater[i][j]++;
    }
    for (int i=n;i>=1;i--){
        for (int j=0;j<n;j++){
            numLess[i][j] = numLess[i+1][j];
        }
        for (int j=a[i];j<n;j++) numLess[i][j]++;
    }
    ll inv = 0;
    for (int i=1;i<=n;i++){
        inv += numGreater[i][a[i]+1];
    }
    ll best=1e15;
    int num=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[i]<a[j])continue;
            ll delta = get(i,j);
            if (inv+delta<best){
                best = inv+delta;
                num=1;
            } else if (inv+delta==best) num++;
        }
    }
    cout<<best<<' '<<num<<endl;
}
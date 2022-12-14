#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long dp0[1000000];
long long dp1[1000000];
vector<int> v[5];
vector<int> A,B;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        int w,c;
        cin>>w>>c;
        v[w].push_back(c);
        if (w==2)A.push_back(c),B.push_back(c);
    }
    for (int i = 1; i <=3 ; ++i)
        sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
    if (v[1].size())dp1[1]=v[1][0];
    for (int i=1;i+1<v[1].size();i+=2)
        A.push_back(v[1][i]+v[1][i+1]);
    for (int i=0;i+1<v[1].size();i+=2)
        B.push_back(v[1][i]+v[1][i+1]);
    int W=2;
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    for (int i=0;i<B.size();i++){
        dp0[W]=dp0[W-2]+B[i];
        W+=2;
    }
    W=3;
    for (int i=0;i<A.size();i++) {
        dp1[W]=dp1[W-2]+A[i];
        W+=2;
    }
    for (int i=1;i<=m;i++) {
        dp1[i]=max(dp1[i],dp1[i-1]);
        dp0[i]=max(dp0[i],dp0[i-1]);
    }
    long long ret=max(dp0[m],dp1[m]);
    long long sum=0;
    for (auto x:v[3]) {
        m-=3;
        if (m<0)break;
        sum+=x;
        ret=max(ret,sum+max(dp0[m],dp1[m]));
    }
    cout<<ret<<endl;
}
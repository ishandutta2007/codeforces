#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> A(n);
        map<int,int> mp;
        for(int &i:A){
            cin>>i;
            mp[i]++;
        }
        vector<vector<int>> B(n,vector<int>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                B[i][j+1]=B[i][j];
                if(A[i]==A[j])B[i][j+1]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                if(A[i]==A[j])ans+=sum;
                else sum-=B[j][j]-B[j][i],sum+=B[j][n]-B[j][j+1];
            }
        }
        for(pair<int,int> p:mp)ans+=p.second*(p.second-1)*(p.second-2)*(p.second-3)/24;
        cout<<ans<<endl;
    }
}
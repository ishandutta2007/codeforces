#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q,m,t;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int> >ps(26,vector<int>(n+1,0)), ans(26,vector<int>(n + 1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            ps[j][i+1]=ps[j][i];
        }
        ps[s[i]-'a'][i+1]++;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            for(int k=j+1;k<=n;k++){
                t=k-j-(ps[i][k]-ps[i][j]);
                ans[i][t] = max(ans[i][t],k-j);
            }
        }
        for(int j=0;j<n;j++){
            ans[i][j+1]=max(ans[i][j+1],ans[i][j]);
        }
    }
    cin>>q;
    char c;
    for(int i=0;i<q;i++){
        cin>>m>>c;
        cout<<ans[c-'a'][m]<<endl;
    }
    return 0;
}
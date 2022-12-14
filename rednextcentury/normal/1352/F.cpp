#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool dp[101][101][101][2];
bool vis[101][101][101][2];
bool solve(int n0,int n1,int n2,int last){
    if (n0<0 || n1<0 || n2<0)return 0;
    if (n0+n1+n2==0)return 1;
    if (vis[n0][n1][n2][last])return dp[n0][n1][n2][last];
    vis[n0][n1][n2][last]=1;
    bool ret=0;
    if (last==0){
        ret|=solve(n0-1,n1,n2,0)|solve(n0,n1-1,n2,1);
    } else {
        ret|=solve(n0,n1-1,n2,0)|solve(n0,n1,n2-1,1);
    }
    return dp[n0][n1][n2][last]=ret;
}
string ret="";
void path(int n0,int n1,int n2,int last){
    if (n0+n1+n2==0)return;
    if (last==0){
        
        if (solve(n0-1,n1,n2,0)){
            ret+="0";
            path(n0-1,n1,n2,0);
            return;
        } else if (solve(n0,n1-1,n2,1)){
            ret+="1";
            path(n0,n1-1,n2,1);
            return;
        }
        
    } else {
        if (solve(n0,n1-1,n2,0)){
            ret+="0";
            path(n0,n1-1,n2,0);
            return;
        } else if (solve(n0,n1,n2-1,1)){
            ret+="1";
            path(n0,n1,n2-1,1);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        if (solve(n0,n1,n2,0)){
            ret="0";
            path(n0,n1,n2,0);
            cout<<ret<<endl;
        } else {
            ret="1";
            path(n0,n1,n2,1);
            cout<<ret<<endl;
        }
    }
}
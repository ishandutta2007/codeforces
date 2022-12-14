#include<bits/stdc++.h>
using namespace std;
#define ll long long
string whySoAnnoying[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int cost(string why, int really){
    int ret=0;
    for (int i=0;i<why.size();i++){
        if (why[i]=='1' && whySoAnnoying[really][i]=='0') return -1;
        else if (why[i]=='0' && whySoAnnoying[really][i]=='1') ret++;
    }
    return ret;
}
string s[3000];
int canBeAnnoying[3000][11];
bool dp[2002][2002];
bool vis[2002][2002];
int n;
bool solve(int i,int j){
    if (j<0) return 0;
    if (i==n)return j==0;
    if (vis[i][j])return dp[i][j];
    vis[i][j]=1;
    dp[i][j]=0;
    for (int dig=9;dig>=0;dig--){
        if (canBeAnnoying[i][dig]==-1)continue;
        if (solve(i+1, j - canBeAnnoying[i][dig])) dp[i][j]=1;
    }
    return dp[i][j];
}
string ret="";
void path(int i,int j){
    if (i==n)return;
    for (int dig=9;dig>=0;dig--){
        if (canBeAnnoying[i][dig]==-1)continue;
        if (solve(i+1, j - canBeAnnoying[i][dig])){
            ret+=char('0'+dig);
            path(i+1,j-canBeAnnoying[i][dig]);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        cin>>s[i];
        for (int j=0;j<10;j++) canBeAnnoying[i][j] = cost(s[i], j);
    }
    if (!solve(0,k))cout<<-1<<endl;
    else {
        path(0,k);cout<<ret<<endl;
    }
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char g[10][10];
int main(){
    int t;
    cin >> t;
    while (t --)
    {
for(int i =0; i<8; i++) cin>>g[i];
{
    for(int i= 1; i<7;i++)
{
    for(int j= 1; j<7;j++)
    {
    if (g[i][j]=='#'&&g[i-1][j-1]=='#'&&g[i+1][j+1]=='#'&&g[i+1][j-1]=='#'&&g[i-1][j+1]=='#')
  {
    cout<<i+1<<' '<<j+1<<endl;
    break;
}
}
}
}
}
return 0;
}
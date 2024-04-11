#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1000 + 11;

int dp[N][2][2];

void up(int i, int l1, int r1, int l2, int r2, int x)
{
      dp[i][l1][r1]=max(dp[i][l1][r1],dp[i-1][l2][r2]+x);
}

int main()
{
      string s1,s2;
      cin>>s1>>s2;
      for (int j=0; j<s1.size(); j++)
      {
            if (s1[j]=='X') s1[j]='1';
            if (s2[j]=='X') s2[j]='1';
            dp[j][0][0]=-1;
            dp[j][0][1]=-1;
            dp[j][1][0]=-1;
            dp[j][1][1]=-1;
      }
      dp[0][s1[0]-'0'][s2[0]-'0']=0;
      for (int d=1; d<s1.size(); d++)
      {
            if (s1[d]=='0') up(d,1,s2[d]-'0',0,0,1);
            if (s2[d]=='0') up(d,s1[d]-'0',1,0,0,1);
            up(d,s1[d]-'0',s2[d]-'0',0,0,0);
            up(d,s1[d]-'0',s2[d]-'0',1,0,0);
            up(d,s1[d]-'0',s2[d]-'0',0,1,0);
            up(d,s1[d]-'0',s2[d]-'0',1,1,0);
            if (s1[d]=='0'&&s2[d]=='0') up(d,1,1,0,0,1);
            if (s1[d]=='0'&&s2[d]=='0') up(d,1,1,0,1,1);
            if (s1[d]=='0'&&s2[d]=='0') up(d,1,1,1,0,1);
      }
      int p=s1.size()-1;
      cout<<max(max(dp[p][0][0],dp[p][0][1]),max(dp[p][1][0],dp[p][1][1]));
}
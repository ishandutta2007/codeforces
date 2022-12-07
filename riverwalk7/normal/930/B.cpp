#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define MAXN 5050
using namespace std;
string s; int u, v, x, y;
int DP[26][MAXN][26];
int good[MAXN][MAXN]; bool flag;
int best[26][MAXN];
int b[MAXN];
int cnt[26];
double ans;
int main()
{
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        for(int j=i+1; j<s.length(); j++)
        {
            if(i!=j)
            {
                u = s[i]-'a';
                v = s[j]-'a';
                x = (j-i+s.length())%s.length();
                y = (i-j+s.length())%s.length();
                DP[u][x][v]++;
                DP[v][y][u]++;
            }
        }
    }
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<s.length(); j++)
        {
            if(j!=i)
            {
                u = s[i]-'a';
                v = s[j]-'a';
                x = (j-i+s.length())%s.length();
                if(DP[u][x][v]<=1)
                {
                    good[i][j] = true;
                }
            }
        }
    }
    for(int i=0; i<s.length(); i++)
    {
        u = s[i]-'a';
        cnt[u]++;
        for(int j=0; j<s.length(); j++)
        {
            if(i!=j)
            {
                if(good[i][j])
                {
                    u = s[i]-'a';
                    x = (j-i+s.length())%s.length();
                    best[u][x]++;
                }
            }
        }
    }
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<s.length(); j++)
        {
            b[i] = max(b[i], best[i][j]);
        }
        //cout<<b[i]<<endl;
        ans += ((double)(b[i]))/((double)(s.length()));
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
}
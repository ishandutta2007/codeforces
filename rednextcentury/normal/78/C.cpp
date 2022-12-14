
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
int k;
map<int,bool> dp;
map<int,bool> solved;
bool solve(int n)
{
    if (solved[n])
        return dp[n];
    for (int i=1;i*i<=n;i++)
    {
        if (n%i)
            continue;
        if (n/i!=n && n/i>=k && !solve(n/i))
        {
           solved[n]=1,dp[n]=1;
           return 1;
        }
        if (i!=n && i>=k && !solve(i))
         {
             solved[n]=1,dp[n]=1;
             return 1;
         }
    }
    solved[n]=1;
    dp[n]=0;
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m>>k;
    if (n%2==0)
    {
        cout<<"Marsel"<<endl;
        return 0;
    }
    if (solve(m))
        cout<<"Timur"<<endl;
    else
        cout<<"Marsel"<<endl;
}
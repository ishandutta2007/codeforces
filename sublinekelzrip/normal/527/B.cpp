#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int sd[30][30];
string a,b;
int main()
{
    int n,ans=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            ans++;
        sd[a[i]-97][b[i]-97]=i+1;
    }
    int ans1=-1,ans2=-1;
    for(int j=0;j<26;j++)
        for(int k=j+1;k<26;k++)
            if(sd[j][k]!=0&&sd[k][j]!=0)
            {
                cout<<ans-2<<endl;
                cout<<sd[j][k]<<' '<<sd[k][j];
                return 0;
            }
    for(int j=0;j<26;j++)
        for(int k=0;k<26;k++)
            for(int l=0;l<26;l++)
                if(j!=k&&j!=l&&k!=l)
                    if(sd[j][k]!=0&&sd[l][j]!=0)
                    {
                        cout<<ans-1<<endl;
                        cout<<sd[j][k]<<' '<<sd[l][j]<<endl;
                        return 0;
                    }
    cout<<ans<<endl;
    cout<<-1<<' '<<-1<<endl;
}
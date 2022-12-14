# include<iostream>
# include<algorithm>
# include<string>
# include<cstring>
# include<stdio.h>
# include<cmath>
# include<iomanip>
# include<map>
# include<cstdlib>
# include<vector>
# include<set>
# include<queue>
# include<stack>
using namespace std;
int main()
{
    int n;
    int mn=100000000;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int a,p;
        cin>>a>>p;
        mn=min(mn,p);
        ans+=mn*a;
    }
    cout<<ans<<endl;
}
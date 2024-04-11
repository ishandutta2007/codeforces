# include <iostream>
# include <string>
# include <map>
# include <cstdlib>
using namespace std;
char a[1000][1000];
map<int,int> y;
int main()
{
    int n,m;
    cin>>n>>m;
    bool p=1;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        bool g=0,s=0;
        int locg;
        int locs;
        for (int x=0;x<m;x++)
        {
            cin>>a[i][x];
            if (a[i][x]=='G')
            {
                g=1;
                locg=x;
            }
            else if (a[i][x]=='S')
            {
                s=1;
                locs=x;
            }
            if (s==1 && g==0)
                p=0;
            if (s==1 && g==1 && locs>locg)
                if (++y[locs-locg]==1)
                    ans++;
        }
    }
    if (ans==0 || p==0)
        cout<<-1<<endl;
    else
    cout<<ans<<endl;
}
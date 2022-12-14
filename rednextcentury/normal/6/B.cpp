# include <iostream>
# include <algorithm>
using namespace std;
int a[30]={0};
char b[100][100];
int main()
{
    int m,n;
    char d;
    cin>>n>>m>>d;
    for (int i=0;i<n;i++)
        for (int x=0;x<m;x++)
            cin>>b[i][x];
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            if (b[i][x]==d)
            {
                if (x+1<m && b[i][x+1]!=d && b[i][x+1]!='.')
                    a[b[i][x+1]-'A']++;
                if (x-1>=0 && b[i][x-1]!=d && b[i][x-1]!='.')
                    a[b[i][x-1]-'A']++;
                if (i+1<n && b[i+1][x]!=d && b[i+1][x]!='.')
                    a[b[i+1][x]-'A']++;
                if (i-1>=0 && b[i-1][x]!=d && b[i-1][x]!='.')
                    a[b[i-1][x]-'A']++;
            }
        
        
        }
    }
    int ans=0;
    for (int i=0;i<30;i++)
    {
    if (a[i]>0)
        ans++;
    
    
    }
    cout<<ans<<endl;








}
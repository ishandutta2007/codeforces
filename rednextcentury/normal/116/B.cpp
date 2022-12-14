# include <string>
# include <iostream>
using namespace std;
char a[100][100];
int main ()
{
int n,m,ans=0;

cin>>n>>m;
for (int i=0;i<n;i++)
{
    string s;
    cin>>s;
    for (int x=0;x<m;x++)
        a[i][x]=s[x];
}
for (int i=0;i<n;i++)
{
    for (int x=0;x<m;x++)
    {
        if (a[i][x]=='W' &&( (i!=0 && a[i-1][x]=='P') ||(x!=0 && a[i][x-1]=='P')||(i!=n-1 && a[i+1][x]=='P')||(x!=m-1 && a[i][x+1]=='P')))
            ans++;
    
    
    
    
    }
}
cout<<ans<<endl;
}
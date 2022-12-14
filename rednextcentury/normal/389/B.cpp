# include <iostream>
# include <map>
# include <iomanip>
# include <queue>
# include <string>
using namespace std;
char a[100][100];
int visited[100][100];
void read(int a[],int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void print(int a[],int n)
{
    cout<<a[0];
    for (int i=1;i<n;i++)
        cout<<" "<<a[i];
    cout<<endl;
}
int main()
{

        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            for (int x=0;x<n;x++)
                cin>>a[i][x];
        bool p=1;
        for (int i=0;i<n;i++)
        {
            for (int x=0;x<n;x++)
            {
                if (!visited[i][x] && a[i][x]=='#')
                {
                    if (i+2>=n || x==0 || x==n-1)
                    {
                        p=0;
                        break;
                    }
                    else
                    {
                        if (a[i+1][x]=='#' && a[i+2][x]=='#' && a[i+1][x+1]=='#' && a[i+1][x-1]=='#' && visited[i+1][x]==0 && visited[i+1][x+1]==0 && visited[i+1][x-1]==0 && visited[i+2][x]==0 && visited[i][x]==0 )
                        {
                            visited[i][x]=1;
                            visited[i+1][x]=1;
                            visited[i+1][x+1]=1;
                            visited[i+1][x-1]=1;
                            visited[i+2][x]=1;
                        }
                        else
                        {
                            p=0;
                            break;
                        }
                    }
                }
            }
        }
        if (p==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
}
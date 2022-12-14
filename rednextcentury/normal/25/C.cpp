#include<iostream>
# include <cmath>
#include <algorithm>
#include <set>
#include<vector>
using namespace std;
long long dist[500][500];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<n;x++)
        {
            cin>>dist[i][x];
        }
    }
    int k;
    cin>>k;
    for (int p=0;p<k;p++)
    {
        long long s,e,len;
        long long sum=0;
        cin>>s>>e>>len;
        s--;e--;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][s]+dist[e][j]+len);
                dist[i][j]=min(dist[i][j],dist[i][e]+dist[s][j]+len);
            }
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                sum+=dist[i][j];
            }
        }
        cout<<sum/2<<endl;
    }
}
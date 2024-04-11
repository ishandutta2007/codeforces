#include <iostream>
#include <algorithm>
# include <fstream>
#include <map>
# include <vector>
using namespace std;
int a[100000];
map<int,int> compressed;
map<int,int> real;
int input[100000][2];
struct cube
{
    int len;
    int idx;
};
vector<cube> colors[100000];
int num[100000];
bool comp(cube a,cube b)
{
    return a.len>b.len;
}
long long best[1000000][2][2];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>input[i][0]>>input[i][1];
        a[i]=input[i][0];
    }
    sort(a,a+n);
    int tot=0;
    compressed[a[0]]=0;
    real[1]=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]!=a[i-1])
            tot++;
        compressed[a[i]]=tot;
        real[tot]=a[i];
    }
    cube x;
    for (int i=0;i<n;i++)
    {
        x.len=input[i][1];
        x.idx=i;
        num[compressed[input[i][0]]]++;
        colors[compressed[input[i][0]]].push_back(x);
    }
    for (int i=0;i<n;i++)
    {
        if (num[i]==0)
            continue;
        else
        {
            sort(colors[i].begin(),colors[i].end(),comp);
        }
    }
    for (int i=0;i<n;i++)
    {
        long long sum=0;
        for (int x=0;x<num[i];x++)
        {
            sum+=colors[i][x].len;
            if (sum>best[x+1][0][0])
            {
                best[x+1][1][0]=best[x+1][0][0];
                best[x+1][1][1]=best[x+1][0][1];
                best[x+1][0][0]=sum;
                best[x+1][0][1]=i+1;
            }
            else if (sum>best[x+1][1][0])
            {
                best[x+1][1][0]=sum;
                best[x+1][1][1]=i+1;
            }
        }
    }
    long long ans=0;
    int col1,col2;
    int num1,num2;
    for (int i=1;i<n;i++)
    {
        long long now=0;
        if (i>0)
        {
            now=best[i][0][0];
            if (best[i-1][0][1]!=best[i][0][1])
            {
                now+=best[i-1][0][0];
                if (best[i-1][0][1]==0 || best[i][0][1]==0)
                    now=0;
            }
            else
            {
                now+=best[i-1][1][0];
                if (best[i-1][1][1]==0 || best[i][0][1]==0)
                    now=0;
            }
            if (now>ans)
            {
                ans=now;
                col1=best[i][0][1];
                if (best[i-1][0][1]!=best[i][0][1])
                    col2=best[i-1][0][1];
                else
                    col2=best[i-1][1][1];
                num1=i;
                num2=i-1;
            }
        }

            now=best[i][0][0]+best[i][1][0];
            if (best[i][0][1]==0 || best[i][1][1]==0)
                now=0;
            if (now>ans)
            {
                ans=now;
                col1=best[i][0][1];
                col2=best[i][1][1];
                num1=i;
                num2=i;
            }
            now=best[i][0][0];
            if (best[i+1][0][1]!=best[i][0][1])
            {
                now+=best[i+1][0][0];
                if (best[i][0][1]==0 || best[i+1][0][1]==0)
                    now=0;
            }
            else
            {
                now+=best[i+1][1][0];
                if (best[i][0][1]==0 || best[i+1][1][1]==0)
                    now=0;
            }
            if (now>ans)
            {
                ans=now;
                col1=best[i][0][1];
                if (best[i+1][0][1]!=best[i][0][1])
                    col2=best[i+1][0][1];
                else
                    col2=best[i+1][1][1];
                num1=i;
                num2=i+1;
            }
    }
    cout<<ans<<endl;
    cout<<num1+num2<<endl;
    if (num1>num2)
    {
        for (int i=0;i<num2;i++)
        {
            cout<<colors[col1-1][i].idx+1<<" ";
            cout<<colors[col2-1][i].idx+1<<" ";
        }
        cout<<colors[col1-1][num1-1].idx+1<<endl;
    }
    else if (num2>num1)
    {
        for (int i=0;i<num1;i++)
        {
            cout<<colors[col2-1][i].idx+1<<" ";
            cout<<colors[col1-1][i].idx+1<<" ";
        }
        cout<<colors[col2-1][num2-1].idx+1<<endl;
    }
    else
    {
        for (int i=0;i<num2;i++)
        {
            cout<<colors[col1-1][i].idx+1<<" ";
            cout<<colors[col2-1][i].idx+1<<" ";
        }
    }
}
#include<iostream>
# include <queue>
#include <vector>
using namespace std;
vector<int> employee[1000000];
int main()
{
    int n;
    cin>>n;
    queue<int> q1;
    queue<int> q2;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (x==-1)
        {
            q1.push(0);
            q2.push(i);
        }
        else
            employee[x].push_back(i);
    }
    int i=0;
    while(!q1.empty())
    {
        while(!q1.empty() && q1.front()==i)
        {
            q1.pop();
            int idx=q2.front();
            q2.pop();
            int j=employee[idx].size();
            for (int x=0;x<j;x++)
            {
                q1.push(i+1);
                q2.push(employee[idx][x]);
            }
        }
        i++;
    }
    cout<<i<<endl;
}
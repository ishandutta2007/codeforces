#include<iostream>
#include<vector>

using namespace std;

int parent[1001];
vector<int> v[1001];
bool b[1001];

int main ()
{
    int n,i,j,sum;

    cin>>n;

    for(i=2;i<=n;i++)
    {
        cin>>parent[i];
        b[parent[i]]=1;
        v[parent[i]].push_back(i);
    }

    for(i=1;i<=n;i++)
    {
        if(b[i])
        {
            sum=0;
            for(j=0;j<v[i].size();j++)
            {
                sum+=1-b[v[i][j]];
            }
            if(sum<3)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;

    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct duo
{
    int num,pos;
};

duo arr[100002];
int br2;
bool boo[100002];
vector<int>v[100002];

bool cmp(duo a,duo b)
{
    return a.num<b.num;
}

int main ()
{
    int n,j,i;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].num;
        arr[i].pos=i;
    }

    sort(arr+1,arr+n+1,cmp);

    for(i=1;i<=n;i++)
    {
        if(boo[i]==0)
        {
            boo[i]=1;
            j=arr[i].pos;
            v[br2].push_back(arr[i].pos);
            while(j!=i)
            {
                //cout<<j<<" "<<arr[j].pos<<endl;
                boo[j]=1;
                j=arr[j].pos;
                v[br2].push_back(j);
            }
            //v[br2].pop_back();
            br2++;
        }
    }

    cout<<br2<<endl;

    for(i=0;i<br2;i++)
    {
        cout<<v[i].size()<<" ";
        for(j=0;j<v[i].size()-1;j++)cout<<v[i][j]<<" ";
        cout<<v[i][j]<<endl;
    }

    return 0;
}
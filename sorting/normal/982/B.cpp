#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

pair<int,int> w[200001];

int res[200001];
vector<int> v;

int main ()
{
    int n,i,cnt=0;
    string s;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>w[i].first;
        w[i].second=i;
    }

    sort(w,w+n);

    cin>>s;

    for(i=0;i<2*n;i++)
    {
        if(s[i]=='0')
        {
            res[i]=w[cnt].second+1;
            cnt++;
            v.push_back(i);
        }
        else
        {
            res[i]=res[v.back()];
            v.pop_back();
        }
    }

    for(i=0;i<2*n;i++)
        cout<<res[i]<<" ";

    return 0;
}
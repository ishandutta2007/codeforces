#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    char last = ';';
    vector<int> vec;
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        if (x==last)vec.push_back(a[i]);
        else
        {
            last = x;
            sort(vec.begin(),vec.end());
            reverse(vec.begin(),vec.end());
            for (int j=0;j<min((int)vec.size(),k);j++)
                ret+=vec[j];
            vec.clear();
            vec.push_back(a[i]);
        }
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for (int j=0;j<min((int)vec.size(),k);j++)
        ret+=vec[j];
    vec.clear();
    cout<<ret<<endl;
}
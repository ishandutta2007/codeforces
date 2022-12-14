#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int a[1000000];
int get()
{
    int ret=0;
    for (int i=0;i<vec.size();i+=2)
        ret+=vec[i+1]-vec[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    n*=2;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ret=1e9;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            vec.clear();
            for (int k=0;k<n;k++)
                if (k!=i && k!=j)
                    vec.push_back(a[k]);
            ret=min(ret,get());
        }
    }
    cout<<ret<<endl;
}
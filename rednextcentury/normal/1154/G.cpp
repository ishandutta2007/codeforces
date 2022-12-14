#include<bits/stdc++.h>
using namespace std;
vector<int> a[10000001];
long long b[1000080];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b[i+1]=x;
        if (a[x].size()<2)
            a[x].push_back(i+1);
    }
    long long best = 1e18;
    int A=-1,B=-1;
    for (int i=1;i<=10000000;i++)
    {
        vector<long long> vec;
        for (int j=i;j<=10000000;j+=i)
        {
            for (int k=0;k<a[j].size();k++)
            {
                if (vec.size()<2)vec.push_back(a[j][k]);
                else break;
            }
            if (vec.size()==2)break;
        }
        if (vec.size()==2 && b[vec[0]]*b[vec[1]]/i<best)
            best = min(best,b[vec[0]]*b[vec[1]]/i),A=vec[0],B=vec[1];
    }
    if (A>B)swap(A,B);
    cout<<A<<' '<<B<<endl;
}
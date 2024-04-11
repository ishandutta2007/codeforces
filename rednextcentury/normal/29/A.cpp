# include <iostream>
# include <algorithm>
using namespace std;
pair<int,int> a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i].second==a[j].first-a[i].first && a[j].second==a[i].first-a[j].first)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}
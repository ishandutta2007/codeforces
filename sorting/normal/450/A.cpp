#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int > a[100001];

int main ()
{
    int n,m,i;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i].first;

        if(a[i].first%m!=0)
            a[i].first=a[i].first/m+1;
        else
            a[i].first=a[i].first/m;

        a[i].second=i+1;
    }

    sort(a,a+n);

    cout<<a[n-1].second<<endl;

    return 0;
}
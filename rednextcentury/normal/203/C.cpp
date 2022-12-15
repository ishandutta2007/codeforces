#include<bits/stdc++.h>
using namespace std;
pair<int,int> A[1000000];
int main()
{
	int n,d,a,b;
    cin>>n>>d>>a>>b;
    for (int i=0;i<n;i++)
    {
    	int x,y;
        cin>>x>>y;
        A[i].first=x*a+y*b;
        A[i].second=i+1;
    }
    sort(A,A+n);
    int ans=0,s=0;
    vector<int> vec;
    while(ans<n && d>=A[ans].first)
    {
    	d-=A[ans].first;
        vec.push_back(A[ans].second);
        ans++;
    }
    cout<<ans<<endl;
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
    cout<<endl;
}
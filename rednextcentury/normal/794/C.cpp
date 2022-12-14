#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    string ret="";
    int n=a.size();
    for (int i=0;i<n;i++)
        ret+='-';
    int l=0,r=n-1;
    int num=0;
    int nn=0;
    int rr=a.size()/2-(n%2==0);
    int rrr=b.size()/2-1;
    for (int i=0;i<a.size();i++)
    {
        // a's turn
        if (a[i]<b[i])
        {
            ret[l]=a[i];
            l++;
        }
        else
            ret[r]=a[rr-num],num++,r--;
        if (l>r)break;
        // z's turn
        if (b[i]>a[i+1])
        {
            ret[l]=b[i];
            l++;
        }
        else
            ret[r]=b[rrr-nn],nn++,r--;
        if (l>r)break;
    }
    cout<<ret<<endl;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int k;
bool check(int W)
{
    int line=1;
    int cur=0;
    for (int i=0;i<vec.size();i++)
    {
        int g=(i+1<vec.size());
        if (vec[i]+g>W)return 0;
        if (cur+vec[i]+g<=W)
            cur+=vec[i]+g;
        else
            line++,cur=0,i--;
    }
    return line<=k;
}
int bs(int l,int r)
{
    int ans=1000000;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid-1;
        else l=mid+1;
    }
return ans;
}
int main()
{
    cin>>k;
        string s;
    while(1)
    {
        getline(cin,s);
        if (s.size()>0)break;
    }
    int num=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==' ' || s[i]=='-') vec.push_back(num),num=0;
        else num++;
    }
    vec.push_back(num);
    cout<<bs(1,1000000)<<endl;
}
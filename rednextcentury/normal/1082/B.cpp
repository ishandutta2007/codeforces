#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum=0;
    int l=0;
    int mx=0;
    int num=0;
    for (int r=0;r<n;r++)
    {
        if (s[r]=='S')sum++;
        else num++;
        while(sum>1)
        {
            if (s[l]=='S')sum--;
            l++;
        }
        mx=max(mx,r-l+1);
    }
    cout<<min(mx,num)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        v.pb(l);
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<v.size(); j++)
        if (abs(v[j]-v[j-1])>1) {cout<<"NO"<<endl; return 0;}
        int pos=0;
        for (int j=0; j<v.size(); j++)
            if (v[j]>v[pos]) pos=j;
        for (int j=pos; j<v.size()-1; j++)
            v[j]=v[j+1];
        v.pop_back();
    }
    cout<<"YES"<<endl;
}
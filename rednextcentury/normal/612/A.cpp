# include<bits/stdc++.h>
using namespace std;
bool vis[1000];
vector<int> vec,vec2;
int a[1000000];
int main()
{
    int n,p,q;
    cin>>n>>p>>q;
    string s;
    cin>>s;
    for (int i=0;i<=n;i++)
    {
        int x=n-i*p;
        if (x<0) break;
        if (x%q!=0) continue;
        int j=0;
        int k=0;
        cout<<i+x/q<<endl;
        while(k<i)
        {
            cout<<s.substr(j,p)<<endl;
            j+=p;
            k++;
        }
        k=0;
        while(k<x/q)
        {
            k++;
            cout<<s.substr(j,q)<<endl;;
            j+=q;
        }
        return 0;
    }
    cout<<-1<<endl;
}
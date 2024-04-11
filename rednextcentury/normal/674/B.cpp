#include <bits/stdc++.h>
using namespace std;
int a[5001];
int num[5001][5001];
int ret[5001];
vector<int> p1;
vector<int> p2;
int main()
{
    int n,k;
    int a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;
    if (n==4 || k<n+1)
    {
        cout<<-1<<endl;
        return 0;
    }
    queue<int> q;
    for (int i=1;i<=n;i++)
        if (i!=a && i!=b && i!=c && i!=d)
            q.push(i);
    int x=q.front();
    q.pop();
    p1.push_back(a),p1.push_back(c),p1.push_back(x);
    p1.push_back(d);
    while(!q.empty())
    {
        p1.push_back(q.front());
        q.pop();
    }
    p1.push_back(b);
    for (int i=0;i<p1.size();i++)
        if (p1[i]==c)
            p2.push_back(c),p2.push_back(a),p2.push_back(x);
    for (int i=p1.size()-1;i>=0;i--)
    {
        p2.push_back(p1[i]);
        if (p1[i]==c)
            break;
    }
    for (int i=0;i<n;i++)
        cout<<p1[i]<<' ';
    cout<<endl;
    for (int i=0;i<n;i++)
        cout<<p2[i]<<' ';
    cout<<endl;
}
# include <bits/stdc++.h>
using namespace std;
int B[2000000];
int A[2000000];
int C[2000000];
int l[1000000],r[1000000];
int ret[1000000];
int main()
{
    int n;
    cin>>n;
    set<int> s;
    for (int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        l[i] = a,r[i] = b;
        B[b] = a;
        A[a] = b;
    }
    for (int i=0;i<n;i++)
        s.insert(l[i]);
    for (int i=0;i<n;i++)
        if (s.find(r[i])!=s.end())
            s.erase(s.find(r[i]));
    int first = *s.begin();
    int cur = n-2;
    int v =0 ;
    while(cur>=0)
    {
        v = B[v];
        ret[cur] = v;
        cur -= 2;
    }

    cur = 1 - n%2;
    v = 0;
    if (n%2)
    {
        ret[0] = first;
        cur = 2;
        v = first;
        while(cur<=n-1)
        {
            v = A[v];
            ret[cur] = v;
            cur+=2;
        }
    }
    else
    {
    while(cur<=n-1)
    {
        v = A[v];
        ret[cur] = v;
        cur+=2;
    }
    }
    for (int i=0;i<n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}
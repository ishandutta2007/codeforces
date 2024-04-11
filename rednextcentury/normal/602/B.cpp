# include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int l=0;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        s.insert(x);
        while(*s.begin()+1<*(--s.end())) s.erase(s.find(a[l])),l++;
        ans=max(ans,(int)s.size());
    }
    cout<<ans<<endl;
}
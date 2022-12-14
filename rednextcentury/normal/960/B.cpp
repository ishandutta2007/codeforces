#include <bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000];
multiset<long long> s;
int main()
{
    int n,k1,k2;
    cin>>n>>k1>>k2;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++){
        cin>>b[i];
        s.insert(abs(a[i]-b[i]));
    }
    for (int i=0;i<k1+k2;i++)
    {
        long long cur = *(--s.end());
        s.erase(--s.end());
        cur--;
        if (cur<0)cur=-cur;
        s.insert(cur);
    }
    long long ret=0;
    for (multiset<long long>::iterator it=s.begin();it!=s.end();it++)
        ret+=(*it)*(*it);
    cout<<ret<<endl;
}
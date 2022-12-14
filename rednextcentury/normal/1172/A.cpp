#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int ret=0;
int n;
set<int> s;
bool Try(int cur,int id) {
    set<int> t;
    for (auto x:s)t.insert(x);
    for (int i=0;i<id;i++) {
        if (!t.empty() && *t.begin()==cur) {
            t.erase(t.begin());
            cur++;
        } else {
            return 0;
        }
        if (a[i]!=0)t.insert(a[i]);
    }
    ret = id+(n-cur+1);
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (x!=0)
            s.insert(x);
    }
    int cur=1;
    int id=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]==1)id=i;
    }
    bool ok=1;
    for (int i=id+1;i<n;i++) {
        if (a[i]!=a[i-1]+1) ok=0;
    }
    if (!ok)id=n;
    else {
        cur=a[n-1]+1;
        if (Try(cur,id)) {
            cout<<ret<<endl;
            return 0;
        }
        id=n;
        cur=1;
    }
    for (int i=0;i<id;i++) {
        if (!s.empty() && *s.begin()==cur) {
            s.erase(s.begin());
            cur++;
        }
        if (a[i]!=0)s.insert(a[i]);
    }
    cout<<id+(n-cur+1)<<endl;
}
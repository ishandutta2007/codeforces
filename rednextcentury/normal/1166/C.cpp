#include <bits/stdc++.h>
using namespace std;
vector<long long> pos,neg;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<long long> vec;
    for (int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        if (x<0)neg.push_back(-x);
        else if (x>0)pos.push_back(x);
        if (x!=0)
            vec.push_back(abs(x));
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    long long ret=0;
    for (auto x:vec)
    {
        long long L = x / 2 + x%2;
        L--;
        long long R = x*2;
        long long A = upper_bound(pos.begin(),pos.end(),R)-pos.begin();
        long long B = upper_bound(pos.begin(),pos.end(),L)-pos.begin();
        ret += A-B;
        A = upper_bound(neg.begin(),neg.end(),R)-neg.begin();
        B = upper_bound(neg.begin(),neg.end(),L)-neg.begin();
        ret+=A-B;
        ret--;
    }
    cout<<ret/2<<endl;

}
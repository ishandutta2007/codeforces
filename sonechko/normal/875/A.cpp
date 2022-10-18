#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
const int N = 1e5 + 11;
int ss(int l)
{
    int sum=0;
    while (l>0)
    {
        sum+=l%10;
        l/=10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for (int i=0; i<=min(n,100000); i++)
        if (n-i>=0&&ss(n-i)==i) v.pb(n-i);
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";

}
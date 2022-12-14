#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    multiset<int> L;
    multiset<int> R;
    for (int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        L.insert(l);
        R.insert(r);
    }
    long long ret=0;
    while(!L.empty())
    {
        int x=*L.begin();
        int y=*R.begin();
        L.erase(L.begin());
        R.erase(R.begin());
        ret+=max(x,y);
    }
    cout<<ret+n<<endl;
}
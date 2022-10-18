#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,s;
    cin>>n>>s;
    int aa=-100;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        int bb=l*60+r;
        int gg=max(0,aa+s+1);
        if (gg+s+1<=bb)
        {
            cout<<gg/60<<" "<<gg%60<<endl;
            return 0;
        }
        aa=bb;
    }
    cout<<(aa+s+1)/60<<" "<<(aa+s+1)%60<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    string s;
    cin>>s;
    s="."+s;
    for (int d=45000; d>=1; d--)
    {
        ll x=d*1ll*d;
        int pos=s.size()-1;
        int kk=0,kol=0;
        while (x>0)
        {
            int p=x%10;
            while (s[pos]!=char(p+'0'))
            {
                pos--;
                if (pos<=0) {kk=1; break;}
            }
            pos--;
            if (pos==-1) kk=1;
            kol++;
            if (kk==1) break;
            x/=10;
        }
        if (kk==0) {cout<<s.size()-1-kol<<endl; return 0;}
    }
    cout<<"-1"<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s="."+s;
    for (int l=1; l<=5; l++)
    {
        int p=n/l;
        int kol=n%l;
        int g=0;
        if (kol>0) g=1;
        if (p+g<=20)
        {
            int c=1;
            cout<<l<<" "<<p+g<<endl;
            for (int r=1; r<=l; r++)
            {
                for (int j=1; j<=p; j++)
                {
                    cout<<s[c];
                    c++;
                }
                if (kol>0)
                {
                    cout<<s[c];
                    c++;
                    kol--;
                } else
                if (g>0)
                {
                    cout<<"*";
                }
                cout<<endl;
            }
            return 0;
        }
    }
}
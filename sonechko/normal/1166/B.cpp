#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int d=1; d<=n; d++)
        if (n%d==0&&d>=5&&n/d>=5)
    {
        string ans="";
        int l=d;
        int r=n/d;
        for (int i=1; i<=l; i++)
        {
            for (int j=1; j<=r; j++)
            {
                if ((i+j)%5==0) cout<<'a'; else
                if ((i+j)%5==1) cout<<'e'; else
                if ((i+j)%5==2) cout<<'i'; else
                if ((i+j)%5==3) cout<<'o'; else cout<<'u';
            }
        }
        return 0;
    }
    cout<<-1;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int n;
        cin>>n;
        int kk=0;
        if (n<4) {kk+=4-n; n+=kk;}
        if (n%2==1) kk++;
        cout<<kk<<"\n";
    }
}
/**
x+y=z

**/
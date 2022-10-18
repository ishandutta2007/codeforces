#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 5e5 + 11;

bool use[N];
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int t=1;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (use[l]==1) cout<<0<<" "; else
        {
            int kol=0;
            while (1)
            {
                kol++;
                use[a[t]]=1;
                if (a[t]==l) {t++; break;}
                t++;
            }
            cout<<kol<<" ";
        }
    }
}
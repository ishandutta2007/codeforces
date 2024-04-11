
#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t=s;
    s='.'+s;
    int l,r,k;
    if (n%2==1) {l=n/2; r=n/2+2; t[n/2]=s[1]; k=2;} else {l=n/2; r=n/2+1; k=1;}
    int p=1;
    while(k<=n)
    {
        if (p==1) {t[l-1]=s[k]; l--;} else
            {
                t[r-1]=s[k]; r++;
            }
            k++;
            p=1-p;
    }
    cout<<t<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

void up()
{
    int n;
    cin>>n;
    int a=2,b=2,c=2;
    while (n%a!=0&&a<=(int)sqrt(n))
        a++;
    if (n%a!=0) {cout<<"NO\n"; return;}
    b=a+1;
    n/=a;
    while (n%b!=0&&b<=(int)sqrt(n))
        b++;
    if (n%b!=0) {cout<<"NO\n"; return;}
    n/=b;
    if (n<=b) {cout<<"NO\n"; return;}
    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<n<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
         up();
}
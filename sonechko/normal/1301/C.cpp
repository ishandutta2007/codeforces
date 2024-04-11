#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll sum(ll m)
{
    return m*(m+1)/2;
}

void up()
{
    ll n,m;
    cin>>n>>m;
    if (m==0) {cout<<"0\n"; return;}
    ll c=(n-m)/(m+1);
    c++;
    ll d=(n-m)%(m+1);
    ll ans=(c+1)*n*d-(c+1)*(c+1)*sum(d)+(c+1)*d;

    m-=d;
    n-=d*(c+1);
    ans+=c*n*m-c*c*sum(m)+c*m;

    cout<<ans<<"\n";
///c*(n-c+1)+c*(n-c*2+1)+c*(n-c*3+1).. =
///= -c*c+1-c*c*2+c-c*c*3+c+..
///= c*n*m - c*c*sum(m) + c*m = c*(n*m+m-c*sum(m));

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**

8 2 (20)



3*5 + 2*3 = 15+6=21

110

3 10

1110000000
10+9+8=27

0010010010

3*8 + 3*5 + 3*2 = 3 * (2+5+8) = 3 * 15 = 45

0010100100

3*8 + 2*6 + 3*3 =

p1 p2 p3 p4

p1*(n-p1+1) +
(p2-p1)*(n-p2+1) +
(p3-p2)*(n-p3+1) ..
=

+p1*n -p1*p1 +p1
+p2*n -p2*p2 +p2  -p1*n     +p1*p2     -p1
+p3*n -p3*p3 +p3  -p2*n     +p2*p3     -p2..
+pk*n -pk*pk +pk  -(pk-1)*n +(pk-1)*pk -p(k-1)

= -p1*p1-p2*p2-p3*p3-...-pk*pk +p1*p2 + p2*p3 + p3*p4 + .. + p(k-1)*pk
   +pk*n + pk +

p1 * (p2-p1) + p2 * (p3-p2) + p3 * (p4-p3) + ..

**/
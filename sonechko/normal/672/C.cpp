#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100001;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define next aihfuebf
ld brec(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
ld a1[N],a2[N];
int main()
{
    ll x1,y1,x2,y2,x0,y0;
    cin>>x1>>y1>>x2>>y2>>x0>>y0;
    int n;
    cin>>n;
    ld ans=0,res=0;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        a1[i]=brec(l,r,x0,y0)-brec(l,r,x1,y1);
        a2[i]=brec(l,r,x0,y0)-brec(l,r,x2,y2);
        ans+=brec(l,r,x0,y0)*2;
    }
    res=ans;
    int l1=1,l2=1;
    for (int i=1; i<=n; i++)
    {
        if (a1[i]-a1[l1]>=0.00000001) l1=i;
        if (a2[i]-a2[l2]>=0.00000001) l2=i;
    }
    //cout<<l1<<" "<<l2<<endl;
    if (l1!=l2) {ans-=a1[l1]; ans-=a2[l2];} else
        {
            int num1=1,num2=1;
            if (l1==1) {num1=2; num2=2;}
            //cout<<a1[l1]<<" "<<a2[l1]<<endl;
            for (int i=1; i<=n; i++)
            {
                if (a1[i]-a1[num1]>=0.00000001&&l1!=i) num1=i;
                if (a2[i]-a2[num2]>=0.00000001&&l1!=i) num2=i;
            }
            if ((a1[l1]+a2[num2])-(a2[l1]+a1[num1])>=0.000000001)
                ans-=a1[l1]+a2[num2]; else ans-=a2[l2]+a1[num1];
        }
    ld res1=ans;




    ans=res;
    ld pr=-1000000000000000000;
    for (int i=1; i<=n; i++)
    {
        if (a1[i]-pr>=0.000000001) pr=a1[i];
        if (a2[i]-pr>=0.000000001) pr=a2[i];
    }
    ld res2=ans-pr;
    outld(10);
    if (res2-res1>=0.000000001) cout<<res1<<endl; else cout<<res2<<endl;

}
#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000+7;
const int N = 1000+10;
const int M = 100;
const int N2 = 100+5;
const int N3 = 1000+5;
const int N4 = 10000+5;
const int N5 = 100000+15;
const int N6 = 1000000+5;
const int N7 = 10000000+5;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
int a[N],b[N],ans[N];
char res[N];
int main()
{
    #ifdef LOCAL
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
        cin>>b[i];
    int k=1;
    int m1=0;
    for (int ij=1; ij<=m; ij++)
    {
        if (k==n+1) {cout<<"NO"<<endl; return 0;}
        int p=0,l=k,r=k;
        for (int j=k; j<=n; j++)
        {
            p+=a[j];
            if (p==b[ij]) break;
            r++;
            if (p>b[ij]) {cout<<"NO"<<endl; return 0;}
        }
        if (p<b[ij]) {cout<<"NO"<<endl; return 0;}
        int good=0;
        for (int i=l; i<=r; i++)
        {
            int m2=m1,d=a[i];
            int l1=i,r1=i;
            while (1==1)
            {
                int ff=0;
                if (l1!=l&&d>a[l1-1]) {m2++; ans[m2]=ij+l1-l; l1--; res[m2]='L'; d+=a[l1]; ff=1;}
                if (r1!=r&&d>a[r1+1]) {m2++; ans[m2]=ij+l1-l; r1++; res[m2]='R'; d+=a[r1]; ff=1;}
                if (ff==0) break;
            }
            if (l1==l&&r1==r) { m1=m2; k=r+1; good=1; break;}
        }
        if (good==0) {cout<<"NO"<<endl; return 0;}
    }
    if (k<n+1) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int i=1; i<=m1; i++)
        cout<<ans[i]<<" "<<res[i]<<endl;
}
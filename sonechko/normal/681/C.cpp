#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000001;
const int M = 10;
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
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
int a[N],b[N];
string t[N],ans[N];
int main()
{
    #ifdef LOCAL

    #else
    //filesio("l");
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>t[i];
        if (t[i]=="insert") cin>>a[i]; else
        if (t[i]=="getMin") cin>>a[i];
    }
    multiset<pair<int,int> > st;
    int g=0,p=0;
    for (int i=1; i<=n; i++)
    if (t[i]=="insert") {g++; st.insert(mp(a[i],g)); p++; ans[p]=t[i]; b[p]=a[i];} else
    if (t[i]=="getMin")
    {
       if (st.size()==0) {p++; ans[p]="insert"; b[p]=a[i]; g++; st.insert(mp(a[i],g));}
       int k=(*st.begin()).first;
       if (k!=a[i])
       {
           while (st.size()!=0)
           {
               if ((*st.begin()).first<a[i]) {p++; ans[p]="removeMin"; st.erase(st.begin()); } else break;
           }
           if (st.size()==0||(*st.begin()).first!=a[i]) {p++; ans[p]="insert"; b[p]=a[i]; g++; st.insert(mp(a[i],g));}
           p++;
           ans[p]=t[i];
           b[p]=a[i];
       } else {p++; ans[p]=t[i]; b[p]=a[i];}
    } else
    {
    if (st.size()==0) {p++; ans[p]="insert"; b[p]=1; g++; st.insert(mp(1,g));}
    p++;
    ans[p]="removeMin";
    st.erase(st.begin());
    }
    cout<<p<<endl;
    for (int i=1; i<=p; i++)
        if (ans[i]=="removeMin") cout<<ans[i]<<endl; else cout<<ans[i]<<" "<<b[i]<<endl;
}
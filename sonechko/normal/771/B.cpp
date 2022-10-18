#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
vector<int> v[N];
int use[N];
string s[N],a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,l=0;
    cin>>n>>m;
    for (int i=1; i<=n-m+1; i++)
        {
            cin>>s[i];
        }
    string aa="A",b="a";
    for (int i=1; i<m; i++)
        {
            if (b=="z") {aa="B"; b="a";} else
            {
                int k=b[0]-'a';
                k++;
                char ch=(k+'a');
                b[0]=ch;
            }
            a[i]=aa+b;
        }
    for (int i=m; i<=n; i++)
    if (s[i-m+1]=="YES")
    {
        if (b=="z") {aa="B"; b="a";} else
            {
                int k=b[0]-'a';
                k++;
                char ch=(k+'a');
                b[0]=ch;
            }
        a[i]=aa+b;
    } else
    {
        a[i]=a[i-m+1];
    }
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
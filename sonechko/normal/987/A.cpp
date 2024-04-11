#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        if (s[0]=='p') use[1]=1;
        if (s[0]=='g') use[2]=1;
        if (s[0]=='b') use[3]=1;
        if (s[0]=='o') use[4]=1;
        if (s[0]=='r') use[5]=1;
        if (s[0]=='y') use[6]=1;
    }
    cout<<6-n<<endl;
    if (use[1]==0) cout<<"Power"<<endl;
    if (use[2]==0) cout<<"Time"<<endl;
    if (use[3]==0) cout<<"Space"<<endl;
    if (use[4]==0) cout<<"Soul"<<endl;
    if (use[5]==0) cout<<"Reality"<<endl;
    if (use[6]==0) cout<<"Mind"<<endl;
}
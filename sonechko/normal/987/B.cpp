#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (n==m) cout<<"="; else
    if (n+m==6&&(n==2||m==2)) cout<<"="; else
    if (n==2&&m==3) cout<<"<"; else
    if (m==2&&n==3) cout<<">"; else
    if (n==1&&m>1) cout<<"<"; else
    if (m==1&&n>1) cout<<">"; else
    if (n<m) cout<<">"; else cout<<"<";
}
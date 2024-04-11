#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
int up(int x)
{
    if (x>0)return x/2+1;
    else return x/2;
}

int down(int x)
{
    if (x>0)return x/2;
    else return x/2-1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> pos,neg;
    int odd=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (abs(a[i])%2==0)a[i]/=2;
        else if (odd==0)a[i]=up(a[i]),odd=1-odd;
        else a[i]=down(a[i]),odd=1-odd;
    }
    for (int i=0;i<n;i++)cout<<a[i]<<endl;

}